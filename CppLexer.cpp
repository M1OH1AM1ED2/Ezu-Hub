#include "CppLexer.h"
 
#include <Qsci/qsciscintilla.h>
#include <QByteArray>
#include <QVector>
#include <QColor>
#include <QFont>
#include <QtGlobal>
 
namespace
{
    bool isLetter(char c)
    {
        return (c >= 'a' && c <= 'z') ||
               (c >= 'A' && c <= 'Z') ||
               c == '_' || c == '$';
    }
 
    bool isDigit(char c)
    {
        return c >= '0' && c <= '9';
    }
 
    bool isUpper(char c)
    {
        return c >= 'A' && c <= 'Z';
    }
 
    bool isIdentifierChar(char c)
    {
        return isLetter(c) || isDigit(c);
    }
 
    bool contains(const char *list[], int count, const QByteArray &word)
    {
        for (int i = 0; i < count; ++i) {
            if (word == list[i])
                return true;
        }
        return false;
    }
 
    // ALL_CAPS names are treated as macros.
    bool isMacroName(const QByteArray &w)
    {
        if (w.size() < 2)
            return false;
        bool hasUpper = false;
        for (char ch : w) {
            if (ch >= 'a' && ch <= 'z')
                return false;
            if (isUpper(ch))
                hasUpper = true;
        }
        return hasUpper;
    }
 
    // VS Code "Dark+" inspired palette (slightly boosted saturation).
    const char *kBackground       = "#181825";
    const char *kMarginBackground = "#181825";   // line-number column background
    const char *kMarginForeground = "#858585";   // line-number text color
    const char *kForeground   = "#D4D4D4";
    const char *kKeyword      = "#569CD6";
    const char *kControl      = "#C586C0";
    const char *kConstant     = "#4FC1FF";
    const char *kType         = "#4EC9B0";
    const char *kClass        = "#4EC9B0";
    const char *kFunction     = "#DCDCAA";
    const char *kMacro        = "#BD63C5";
    const char *kVariable     = "#9CDCFE";
    const char *kPreprocessor = "#C586C0";
    const char *kIncludePath  = "#CE9178";
    const char *kComment      = "#6A9955";
    const char *kDocComment   = "#57A64A";
    const char *kString       = "#CE9178";
    const char *kRawString    = "#D69D85";
    const char *kNumber       = "#B5CEA8";
    const char *kOperator     = "#D4D4D4";
    const char *kEscape       = "#D7BA7D";
    const char *kBracket1     = "#FFD700";
    const char *kBracket2     = "#DA70D6";
    const char *kBracket3     = "#179FFF";
    const char *kError        = "#F44747";
}
 
CppLexer::CppLexer(QObject *parent)
    : QsciLexerCustom(parent)
{
    setDefaultColor(QColor(kForeground));
    setDefaultPaper(QColor(kBackground));
 
    QFont font("Liberation Mono", 12);
    setDefaultFont(font);
 
    setColor(QColor(kForeground),   Default);
    setColor(QColor(kKeyword),      Keyword);
    setColor(QColor(kControl),      ControlKeyword);
    setColor(QColor(kConstant),     Constant);
    setColor(QColor(kType),         Type);
    setColor(QColor(kClass),        ClassName);
    setColor(QColor(kFunction),     Function);
    setColor(QColor(kMacro),        Macro);
    setColor(QColor(kVariable),     Identifier);
    setColor(QColor(kPreprocessor), Preprocessor);
    setColor(QColor(kIncludePath),  IncludePath);
    setColor(QColor(kComment),      Comment);
    setColor(QColor(kDocComment),   DocComment);
    setColor(QColor(kString),       String);
    setColor(QColor(kRawString),    RawString);
    setColor(QColor(kNumber),       Number);
    setColor(QColor(kOperator),     Operator);
    setColor(QColor(kEscape),       EscapeSequence);
    setColor(QColor(kBracket1),     Bracket1);
    setColor(QColor(kBracket2),     Bracket2);
    setColor(QColor(kBracket3),     Bracket3);
    setColor(QColor(kError),        Error);
 
    for (int style = Default; style <= Error; ++style) {
        setPaper(QColor(kBackground), style);
        setFont(font, style);
    }
 
    QFont italic = font;
    italic.setItalic(true);
    setFont(italic, Comment);
    setFont(italic, DocComment);
 
    QFont bold = font;
    bold.setBold(true);
    setFont(bold, Bracket1);
    setFont(bold, Bracket2);
    setFont(bold, Bracket3);
}
 
void CppLexer::setEditor(QsciScintilla *editor)
{
    QsciLexerCustom::setEditor(editor);
 
    if (editor) {
        editor->setMarginsBackgroundColor(QColor(kMarginBackground));
        editor->setMarginsForegroundColor(QColor(kMarginForeground));
    }
}
 
const char *CppLexer::language() const
{
    return "C++";
}
 
QString CppLexer::description(int style) const
{
    switch (style) {
    case Default:        return "Default";
    case Keyword:        return "Keyword";
    case ControlKeyword: return "Control keyword";
    case Constant:       return "Constant";
    case Type:           return "Standard type";
    case ClassName:      return "Class / namespace";
    case Function:       return "Function";
    case Macro:          return "Macro";
    case Identifier:     return "Variable";
    case Preprocessor:   return "Preprocessor directive";
    case IncludePath:    return "Include path";
    case Comment:        return "Comment";
    case DocComment:     return "Documentation comment";
    case String:         return "String / char";
    case RawString:      return "Raw string";
    case Number:         return "Number";
    case Operator:       return "Operator";
    case EscapeSequence: return "Escape sequence";
    case Bracket1:       return "Bracket level 1";
    case Bracket2:       return "Bracket level 2";
    case Bracket3:       return "Bracket level 3";
    case Error:          return "Unclosed string";
    default:             return QString();
    }
}
 
void CppLexer::styleText(int start, int end)
{
    if (!editor())
        return;
 
    const int documentLength = editor()->length();
    if (documentLength <= 0)
        return;
 
    const QByteArray text = editor()->bytes(0, documentLength);
    const int n = qMin(documentLength, static_cast<int>(text.size()));
    if (n <= 0)
        return;
 
    QVector<int> styles(n, Default);
 
    auto mark = [&](int from, int to, int style) {
        from = qBound(0, from, n);
        to = qBound(from, to, n);
        for (int k = from; k < to; ++k)
            styles[k] = style;
    };
 
    // Blue: declarations, modifiers and primitive types.
    static const char *keywords[] = {
        "alignas", "alignof", "asm", "auto", "bool", "char", "char8_t",
        "char16_t", "char32_t", "class", "concept", "const", "consteval",
        "constexpr", "constinit", "const_cast", "decltype", "delete",
        "double", "dynamic_cast", "enum", "explicit", "export", "extern",
        "final", "float", "friend", "inline", "int", "long", "mutable",
        "namespace", "new", "noexcept", "operator", "override", "private",
        "protected", "public", "register", "reinterpret_cast", "requires",
        "short", "signed", "sizeof", "static", "static_assert",
        "static_cast", "struct", "template", "thread_local", "typedef",
        "typeid", "typename", "union", "unsigned", "using", "virtual",
        "void", "volatile", "wchar_t"
    };
 
    // Purple: control flow.
    static const char *controlKeywords[] = {
        "break", "case", "catch", "co_await", "co_return", "co_yield",
        "continue", "default", "do", "else", "for", "goto", "if", "return",
        "switch", "throw", "try", "while"
    };
 
    static const char *constants[] = {
        "true", "false", "nullptr", "NULL", "this"
    };
 
    // Teal: common standard library types.
    static const char *types[] = {
        "string", "string_view", "wstring", "vector", "map", "unordered_map",
        "set", "unordered_set", "multimap", "multiset", "array", "list",
        "deque", "queue", "stack", "pair", "tuple", "optional", "variant",
        "function", "unique_ptr", "shared_ptr", "weak_ptr", "size_t",
        "ptrdiff_t", "int8_t", "int16_t", "int32_t", "int64_t", "uint8_t",
        "uint16_t", "uint32_t", "uint64_t", "intptr_t", "uintptr_t",
        "ostream", "istream", "ifstream", "ofstream", "stringstream",
        "thread", "mutex", "atomic", "chrono", "span", "any"
    };
 
    // Names after which an identifier is a class/namespace name.
    static const char *typeIntroducers[] = {
        "class", "struct", "enum", "union", "namespace",
        "public", "private", "protected", "virtual"
    };
 
    const int keywordCount = int(sizeof(keywords) / sizeof(keywords[0]));
    const int controlCount = int(sizeof(controlKeywords) / sizeof(controlKeywords[0]));
    const int constantCount = int(sizeof(constants) / sizeof(constants[0]));
    const int typeCount = int(sizeof(types) / sizeof(types[0]));
    const int introCount = int(sizeof(typeIntroducers) / sizeof(typeIntroducers[0]));
 
    // "..." and '...' literals, with escape highlighting.
    auto scanQuoted = [&](int from, int quotePos) -> int {
        const char quote = text.at(quotePos);
        int j = quotePos + 1;
        bool closed = false;
        while (j < n) {
            const char d = text.at(j);
            if (d == '\\' && j + 1 < n) {
                j += 2;
                continue;
            }
            if (d == quote) {
                ++j;
                closed = true;
                break;
            }
            if (d == '\n')
                break;
            ++j;
        }
        j = qMin(j, n);
        mark(from, j, closed ? String : Error);
 
        const int contentEnd = closed ? j - 1 : j;
        int k = quotePos + 1;
        while (k < contentEnd) {
            if (text.at(k) == '\\' && k + 1 < contentEnd) {
                mark(k, k + 2, EscapeSequence);
                k += 2;
            } else {
                ++k;
            }
        }
        return j;
    };
 
    // R"delim( ... )delim"
    auto scanRaw = [&](int from, int quotePos) -> int {
        int p = quotePos + 1;
        const int delimStart = p;
        while (p < n && p - delimStart <= 16 &&
               text.at(p) != '(' && text.at(p) != '\n' &&
               text.at(p) != '"' && text.at(p) != ' ')
            ++p;
        if (p >= n || text.at(p) != '(')
            return scanQuoted(from, quotePos);
 
        const QByteArray term =
            QByteArray(")") + text.mid(delimStart, p - delimStart) + QByteArray("\"");
        const int endPos = text.indexOf(term, p + 1);
        int j;
        bool closed;
        if (endPos < 0) {
            j = n;
            closed = false;
        } else {
            j = endPos + term.size();
            closed = true;
        }
        mark(from, j, closed ? RawString : Error);
        return j;
    };
 
    int bracketDepth = 0;
    QByteArray lastWord;
 
    int i = 0;
    while (i < n) {
        const char c = text.at(i);
 
        if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
            ++i;
            continue;
        }
 
        if (!isLetter(c))
            lastWord.clear();
 
        // Single-line comments.
        if (c == '/' && i + 1 < n && text.at(i + 1) == '/') {
            const bool doc = i + 2 < n &&
                             (text.at(i + 2) == '/' || text.at(i + 2) == '!');
            int j = i + 2;
            while (j < n && text.at(j) != '\n')
                ++j;
            mark(i, j, doc ? DocComment : Comment);
            i = j;
            continue;
        }
 
        // Multiline comments.
        if (c == '/' && i + 1 < n && text.at(i + 1) == '*') {
            const bool doc = i + 2 < n &&
                             (text.at(i + 2) == '*' || text.at(i + 2) == '!');
            int j = i + 2;
            while (j + 1 < n &&
                   !(text.at(j) == '*' && text.at(j + 1) == '/'))
                ++j;
            if (j + 1 < n)
                j += 2;
            else
                j = n;
            mark(i, j, doc ? DocComment : Comment);
            i = j;
            continue;
        }
 
        // Preprocessor directives (# at the start of a line).
        if (c == '#') {
            int k = i - 1;
            while (k >= 0 && (text.at(k) == ' ' || text.at(k) == '\t'))
                --k;
            if (k < 0 || text.at(k) == '\n') {
                int j = i + 1;
                while (j < n && (text.at(j) == ' ' || text.at(j) == '\t'))
                    ++j;
                const int wordStart = j;
                while (j < n && isLetter(text.at(j)))
                    ++j;
                const QByteArray directive = text.mid(wordStart, j - wordStart);
                mark(i, j, Preprocessor);
 
                if (directive == "include" || directive == "import" ||
                    directive == "include_next") {
                    int p = j;
                    while (p < n && (text.at(p) == ' ' || text.at(p) == '\t'))
                        ++p;
                    if (p < n && text.at(p) == '<') {
                        int e = p + 1;
                        while (e < n && text.at(e) != '>' && text.at(e) != '\n')
                            ++e;
                        if (e < n && text.at(e) == '>')
                            ++e;
                        mark(p, e, IncludePath);
                        j = e;
                    }
                }
                i = j;
                continue;
            }
        }
 
        // String and char literals.
        if (c == '"' || c == '\'') {
            i = scanQuoted(i, i);
            continue;
        }
 
        // Keywords, types, functions, classes, macros, identifiers.
        if (isLetter(c)) {
            int j = i + 1;
            while (j < n && isIdentifierChar(text.at(j)))
                ++j;
 
            const QByteArray word = text.mid(i, j - i);
 
            // Encoding prefixes and raw strings: L"..", u8"..", R"(..)".
            if (j < n && (text.at(j) == '"' || text.at(j) == '\'')) {
                if (text.at(j) == '"' &&
                    (word == "R" || word == "LR" || word == "uR" ||
                     word == "UR" || word == "u8R")) {
                    i = scanRaw(i, j);
                    lastWord.clear();
                    continue;
                }
                if (word == "L" || word == "u" || word == "U" || word == "u8") {
                    i = scanQuoted(i, j);
                    lastWord.clear();
                    continue;
                }
            }
 
            int k = j;
            while (k < n && (text.at(k) == ' ' || text.at(k) == '\t'))
                ++k;
            const bool followedByCall = k < n && text.at(k) == '(';
            const bool followedByScope =
                k + 1 < n && text.at(k) == ':' && text.at(k + 1) == ':';
 
            int style = Identifier;
            if (contains(controlKeywords, controlCount, word))
                style = ControlKeyword;
            else if (contains(constants, constantCount, word))
                style = Constant;
            else if (contains(keywords, keywordCount, word))
                style = Keyword;
            else if (contains(types, typeCount, word))
                style = Type;
            else if (contains(typeIntroducers, introCount, lastWord))
                style = ClassName;
            else if (followedByScope)
                style = ClassName;
            else if (isMacroName(word))
                style = Macro;
            else if (isUpper(word.at(0)))
                style = ClassName;
            else if (followedByCall)
                style = Function;
 
            mark(i, j, style);
            lastWord = word;
            i = j;
            continue;
        }
 
        // Numeric literals (hex, binary, floats, suffixes, digit separators).
        if (isDigit(c) || (c == '.' && i + 1 < n && isDigit(text.at(i + 1)))) {
            int j = i + 1;
            while (j < n) {
                const char d = text.at(j);
                if (isIdentifierChar(d)) {
                    ++j;
                    continue;
                }
                if (d == '.' && j + 1 < n && isDigit(text.at(j + 1))) {
                    ++j;
                    continue;
                }
                if (d == '\'' && j + 1 < n && isIdentifierChar(text.at(j + 1))) {
                    ++j;
                    continue;
                }
                if ((d == '+' || d == '-') && j > i &&
                    (text.at(j - 1) == 'e' || text.at(j - 1) == 'E' ||
                     text.at(j - 1) == 'p' || text.at(j - 1) == 'P')) {
                    ++j;
                    continue;
                }
                break;
            }
            mark(i, j, Number);
            i = j;
            continue;
        }
 
        // Brackets colored by nesting depth.
        if (c == '(' || c == '[' || c == '{') {
            mark(i, i + 1, Bracket1 + (bracketDepth % 3));
            ++bracketDepth;
            ++i;
            continue;
        }
        if (c == ')' || c == ']' || c == '}') {
            if (bracketDepth > 0)
                --bracketDepth;
            mark(i, i + 1, Bracket1 + (bracketDepth % 3));
            ++i;
            continue;
        }
 
        if (QByteArray("+-*/%~!<>&|^?=:").contains(c))
            mark(i, i + 1, Operator);
 
        ++i;
    }
 
    const int styleStart = qBound(0, start, n);
    const int styleEnd = qBound(styleStart, end, n);
    if (styleEnd <= styleStart)
        return;
 
    startStyling(styleStart);
 
    int runStart = styleStart;
    int currentStyle = styles.at(styleStart);
 
    for (int k = styleStart + 1; k < styleEnd; ++k) {
        if (styles.at(k) != currentStyle) {
            setStyling(k - runStart, currentStyle);
            runStart = k;
            currentStyle = styles.at(k);
        }
    }
 
    setStyling(styleEnd - runStart, currentStyle);
}
 
