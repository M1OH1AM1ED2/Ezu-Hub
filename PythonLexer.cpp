#include "PythonLexer.h"
 
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
               c == '_';
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
 
    bool isConstantName(const QByteArray &w)
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
 
    // Returns the index of the opening quote if a string literal (with an
    // optional r/b/u/f prefix) starts at position i, otherwise -1.
    int stringQuotePos(const QByteArray &t, int n, int i, bool &raw, bool &fmt)
    {
        raw = false;
        fmt = false;
        int j = i;
        while (j < n && j - i < 3) {
            const char ch = t.at(j);
            if (ch == 'r' || ch == 'R')
                raw = true;
            else if (ch == 'f' || ch == 'F')
                fmt = true;
            else if (ch == 'b' || ch == 'B' || ch == 'u' || ch == 'U')
                ;
            else
                break;
            ++j;
        }
        if (j < n && (t.at(j) == '\'' || t.at(j) == '"'))
            return j;
        return -1;
    }
 
    // VS Code "Dark+" inspired palette (slightly boosted saturation).
    const char *kBackground       = "#181825";
    const char *kMarginBackground = "#181825";   // line-number column background
    const char *kMarginForeground = "#858585";   // line-number text color
    const char *kForeground = "#D4D4D4";
    const char *kKeyword    = "#569CD6";
    const char *kControl    = "#C586C0";
    const char *kConstant   = "#4FC1FF";
    const char *kType       = "#4EC9B0";
    const char *kClass      = "#4EC9B0";
    const char *kFunction   = "#DCDCAA";
    const char *kSelf       = "#569CD6";
    const char *kVariable   = "#9CDCFE";
    const char *kComment    = "#6A9955";
    const char *kString     = "#CE9178";
    const char *kRawString  = "#D69D85";
    const char *kNumber     = "#B5CEA8";
    const char *kOperator   = "#D4D4D4";
    const char *kDecorator  = "#DCDCAA";
    const char *kEscape     = "#D7BA7D";
    const char *kInterp     = "#4FC1FF";
    const char *kBracket1   = "#FFD700";
    const char *kBracket2   = "#DA70D6";
    const char *kBracket3   = "#179FFF";
    const char *kError      = "#F44747";
}
 
PythonLexer::PythonLexer(QObject *parent)
    : QsciLexerCustom(parent)
{
    setDefaultColor(QColor(kForeground));
    setDefaultPaper(QColor(kBackground));
 
    QFont font("Liberation Mono", 20);
    setDefaultFont(font);
 
    setColor(QColor(kForeground), Default);
    setColor(QColor(kKeyword),    Keyword);
    setColor(QColor(kControl),    ControlKeyword);
    setColor(QColor(kConstant),   Constant);
    setColor(QColor(kType),       Type);
    setColor(QColor(kClass),      ClassName);
    setColor(QColor(kFunction),   Function);
    setColor(QColor(kSelf),       SelfParam);
    setColor(QColor(kVariable),   Identifier);
    setColor(QColor(kComment),    Comment);
    setColor(QColor(kString),     String);
    setColor(QColor(kRawString),  RawString);
    setColor(QColor(kNumber),     Number);
    setColor(QColor(kOperator),   Operator);
    setColor(QColor(kDecorator),  Decorator);
    setColor(QColor(kEscape),     EscapeSequence);
    setColor(QColor(kInterp),     Interpolation);
    setColor(QColor(kBracket1),   Bracket1);
    setColor(QColor(kBracket2),   Bracket2);
    setColor(QColor(kBracket3),   Bracket3);
    setColor(QColor(kError),      Error);
 
    for (int style = Default; style <= Error; ++style) {
        setPaper(QColor(kBackground), style);
        setFont(font, style);
    }
 
    QFont italic = font;
    italic.setItalic(true);
    setFont(italic, Comment);
    setFont(italic, SelfParam);
 
    QFont bold = font;
    bold.setBold(true);
    setFont(bold, Bracket1);
    setFont(bold, Bracket2);
    setFont(bold, Bracket3);
}
 
void PythonLexer::setEditor(QsciScintilla *editor)
{
    QsciLexerCustom::setEditor(editor);
 
    if (editor) {
        editor->setMarginsBackgroundColor(QColor(kMarginBackground));
        editor->setMarginsForegroundColor(QColor(kMarginForeground));
    }
}
 
const char *PythonLexer::language() const
{
    return "Python";
}
 
QString PythonLexer::description(int style) const
{
    switch (style) {
    case Default:        return "Default";
    case Keyword:        return "Keyword";
    case ControlKeyword: return "Control keyword";
    case Constant:       return "Constant";
    case Type:           return "Built-in type";
    case ClassName:      return "Class name";
    case Function:       return "Function";
    case SelfParam:      return "self / cls";
    case Identifier:     return "Variable";
    case Comment:        return "Comment";
    case String:         return "String";
    case RawString:      return "Raw string";
    case Number:         return "Number";
    case Operator:       return "Operator";
    case Decorator:      return "Decorator";
    case EscapeSequence: return "Escape sequence";
    case Interpolation:  return "f-string expression";
    case Bracket1:       return "Bracket level 1";
    case Bracket2:       return "Bracket level 2";
    case Bracket3:       return "Bracket level 3";
    case Error:          return "Unclosed string";
    default:             return QString();
    }
}
 
void PythonLexer::styleText(int start, int end)
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
 
    // Blue.
    static const char *keywords[] = {
        "and", "async", "class", "def", "del", "global", "in", "is",
        "lambda", "nonlocal", "not", "or"
    };
 
    // Purple.
    static const char *controlKeywords[] = {
        "as", "assert", "await", "break", "continue", "elif", "else",
        "except", "finally", "for", "from", "if", "import", "pass", "raise",
        "return", "try", "while", "with", "yield"
    };
 
    static const char *constants[] = {
        "True", "False", "None", "NotImplemented", "Ellipsis", "__debug__"
    };
 
    static const char *types[] = {
        "int", "float", "str", "bool", "list", "dict", "set", "tuple",
        "frozenset", "bytes", "bytearray", "complex", "object", "type",
        "range", "memoryview", "slice", "property", "staticmethod",
        "classmethod"
    };
 
    static const char *builtins[] = {
        "print", "len", "open", "input", "enumerate", "zip", "map", "filter",
        "sorted", "reversed", "sum", "min", "max", "abs", "all", "any",
        "isinstance", "issubclass", "hasattr", "getattr", "setattr",
        "delattr", "id", "hash", "repr", "format", "iter", "next", "round",
        "pow", "divmod", "chr", "ord", "hex", "oct", "bin", "vars", "dir",
        "globals", "locals", "callable", "compile", "eval", "exec", "super",
        "exit", "quit", "help"
    };
 
    const int keywordCount = int(sizeof(keywords) / sizeof(keywords[0]));
    const int controlCount = int(sizeof(controlKeywords) / sizeof(controlKeywords[0]));
    const int constantCount = int(sizeof(constants) / sizeof(constants[0]));
    const int typeCount = int(sizeof(types) / sizeof(types[0]));
    const int builtinCount = int(sizeof(builtins) / sizeof(builtins[0]));
 
    auto atLineStart = [&](int pos) {
        int k = pos - 1;
        while (k >= 0 && (text.at(k) == ' ' || text.at(k) == '\t'))
            --k;
        return k < 0 || text.at(k) == '\n';
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
 
        // Comments.
        if (c == '#') {
            int j = i + 1;
            while (j < n && text.at(j) != '\n')
                ++j;
            mark(i, j, Comment);
            lastWord.clear();
            i = j;
            continue;
        }
 
        // String literals, with optional prefixes (r, b, u, f, rb, fr ...).
        const bool canStartPrefix = (i == 0 || !isIdentifierChar(text.at(i - 1)));
        if (c == '\'' || c == '"' || (isLetter(c) && canStartPrefix)) {
            bool raw = false;
            bool fmt = false;
            const int q = stringQuotePos(text, n, i, raw, fmt);
            if (q >= 0) {
                const char quote = text.at(q);
                const bool triple = q + 2 < n &&
                                    text.at(q + 1) == quote &&
                                    text.at(q + 2) == quote;
                const int contentStart = q + (triple ? 3 : 1);
                int j = contentStart;
                bool closed = false;
 
                while (j < n) {
                    const char d = text.at(j);
                    if (d == '\\' && j + 1 < n) {
                        j += 2;
                        continue;
                    }
                    if (triple) {
                        if (d == quote && j + 2 < n &&
                            text.at(j + 1) == quote &&
                            text.at(j + 2) == quote) {
                            j += 3;
                            closed = true;
                            break;
                        }
                    } else {
                        if (d == quote) {
                            ++j;
                            closed = true;
                            break;
                        }
                        if (d == '\n')
                            break;
                    }
                    ++j;
                }
                j = qMin(j, n);
 
                const int baseStyle = raw ? RawString : String;
                mark(i, j, closed ? baseStyle : (triple ? baseStyle : Error));
 
                const int contentEnd = closed ? j - (triple ? 3 : 1) : j;
                int k = contentStart;
                while (k < contentEnd) {
                    const char d = text.at(k);
                    if (!raw && d == '\\' && k + 1 < contentEnd) {
                        mark(k, k + 2, EscapeSequence);
                        k += 2;
                    } else if (fmt && d == '{') {
                        if (k + 1 < contentEnd && text.at(k + 1) == '{') {
                            k += 2;
                            continue;
                        }
                        int depth = 1;
                        int e = k + 1;
                        while (e < contentEnd && depth > 0) {
                            if (text.at(e) == '{')
                                ++depth;
                            else if (text.at(e) == '}')
                                --depth;
                            ++e;
                        }
                        mark(k, e, Interpolation);
                        k = e;
                    } else {
                        ++k;
                    }
                }
 
                lastWord.clear();
                i = j;
                continue;
            }
        }
 
        // Decorators.
        if (c == '@' && atLineStart(i)) {
            int j = i + 1;
            while (j < n && (isIdentifierChar(text.at(j)) || text.at(j) == '.'))
                ++j;
            mark(i, j, Decorator);
            lastWord.clear();
            i = j;
            continue;
        }
 
        // Keywords, types, builtins, functions, classes, identifiers.
        if (isLetter(c)) {
            int j = i + 1;
            while (j < n && isIdentifierChar(text.at(j)))
                ++j;
 
            const QByteArray word = text.mid(i, j - i);
 
            int k = j;
            while (k < n && (text.at(k) == ' ' || text.at(k) == '\t'))
                ++k;
            const bool followedByCall = k < n && text.at(k) == '(';
            const bool dunder = word.size() > 4 &&
                                word.startsWith("__") && word.endsWith("__");
 
            int style = Identifier;
            if (lastWord == "def")
                style = Function;
            else if (lastWord == "class")
                style = ClassName;
            else if (contains(controlKeywords, controlCount, word))
                style = ControlKeyword;
            else if (contains(constants, constantCount, word))
                style = Constant;
            else if (contains(keywords, keywordCount, word))
                style = Keyword;
            else if (word == "self" || word == "cls")
                style = SelfParam;
            else if (contains(types, typeCount, word))
                style = Type;
            else if (contains(builtins, builtinCount, word))
                style = Function;
            else if (dunder)
                style = followedByCall ? Function : Constant;
            else if (isUpper(word.at(0)))
                style = isConstantName(word) ? Constant : ClassName;
            else if (followedByCall)
                style = Function;
 
            mark(i, j, style);
            lastWord = word;
            i = j;
            continue;
        }
 
        lastWord.clear();
 
        // Numeric literals (hex, binary, floats, underscores, complex).
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
                if ((d == '+' || d == '-') && j > i &&
                    (text.at(j - 1) == 'e' || text.at(j - 1) == 'E')) {
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
 
        if (QByteArray("+-*/%~!<>&|^=:@").contains(c))
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
 
