#include "DartLexer.h"
 
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
 
    // VS Code "Dark+" inspired palette (slightly boosted saturation).
    const char *kBackground       = "#181825";
    const char *kMarginBackground = "#181825";   // line-number column background
    const char *kMarginForeground = "#858585";   // line-number text color
    const char *kForeground   = "#D4D4D4";
    const char *kKeyword      = "#569CD6"; // blue
    const char *kControl      = "#C586C0"; // purple
    const char *kConstant     = "#4FC1FF"; // bright blue
    const char *kType         = "#4EC9B0"; // teal
    const char *kClass        = "#4EC9B0"; // teal
    const char *kFunction     = "#DCDCAA"; // yellow
    const char *kVariable     = "#9CDCFE"; // light blue
    const char *kComment      = "#6A9955"; // green
    const char *kDocComment   = "#57A64A"; // vivid green
    const char *kString       = "#CE9178"; // orange
    const char *kRawString    = "#D69D85"; // light orange
    const char *kNumber       = "#B5CEA8"; // light green
    const char *kOperator     = "#D4D4D4";
    const char *kAnnotation   = "#DCDCAA"; // yellow
    const char *kEscape       = "#D7BA7D"; // gold
    const char *kInterp       = "#4FC1FF"; // bright blue
    const char *kBracket1     = "#FFD700"; // gold
    const char *kBracket2     = "#DA70D6"; // orchid
    const char *kBracket3     = "#179FFF"; // blue
    const char *kError        = "#F44747"; // red
}
 
DartLexer::DartLexer(QObject *parent)
    : QsciLexerCustom(parent)
{
    setDefaultColor(QColor(kForeground));
    setDefaultPaper(QColor(kBackground));
 
    QFont font("Liberation Mono", 17);
    setDefaultFont(font);
 
    setColor(QColor(kForeground), Default);
    setColor(QColor(kKeyword),    Keyword);
    setColor(QColor(kControl),    ControlKeyword);
    setColor(QColor(kConstant),   Constant);
    setColor(QColor(kType),       Type);
    setColor(QColor(kClass),      ClassName);
    setColor(QColor(kFunction),   Function);
    setColor(QColor(kVariable),   Identifier);
    setColor(QColor(kComment),    Comment);
    setColor(QColor(kDocComment), DocComment);
    setColor(QColor(kString),     String);
    setColor(QColor(kRawString),  RawString);
    setColor(QColor(kNumber),     Number);
    setColor(QColor(kOperator),   Operator);
    setColor(QColor(kAnnotation), Annotation);
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
 
    // Italic comments, like many VS Code themes.
    QFont italic = font;
    italic.setItalic(true);
    setFont(italic, Comment);
    setFont(italic, DocComment);
 
    // Bold brackets so the depth colors stand out.
    QFont bold = font;
    bold.setBold(true);
    setFont(bold, Bracket1);
    setFont(bold, Bracket2);
    setFont(bold, Bracket3);
}
 
void DartLexer::setEditor(QsciScintilla *editor)
{
    QsciLexerCustom::setEditor(editor);
 
    if (editor) {
        editor->setMarginsBackgroundColor(QColor(kMarginBackground));
        editor->setMarginsForegroundColor(QColor(kMarginForeground));
    }
}
 
const char *DartLexer::language() const
{
    return "Dart";
}
 
QString DartLexer::description(int style) const
{
    switch (style) {
    case Default:        return "Default";
    case Keyword:        return "Keyword";
    case ControlKeyword: return "Control keyword";
    case Constant:       return "Constant";
    case Type:           return "Built-in type";
    case ClassName:      return "Class name";
    case Function:       return "Function";
    case Identifier:     return "Variable";
    case Comment:        return "Comment";
    case DocComment:     return "Documentation comment";
    case String:         return "String";
    case RawString:      return "Raw string";
    case Number:         return "Number";
    case Operator:       return "Operator";
    case Annotation:     return "Annotation";
    case EscapeSequence: return "Escape sequence";
    case Interpolation:  return "String interpolation";
    case Bracket1:       return "Bracket level 1";
    case Bracket2:       return "Bracket level 2";
    case Bracket3:       return "Bracket level 3";
    case Error:          return "Unclosed string";
    default:             return QString();
    }
}
 
void DartLexer::styleText(int start, int end)
{
    if (!editor())
        return;
 
    // Scintilla positions and styling lengths are byte positions.
    // Parse the whole document for multiline comments/strings, but apply
    // styles only to the range requested by Scintilla.
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
 
    // Declaration / modifier keywords (blue).
    static const char *keywords[] = {
        "abstract", "as", "base", "class", "const", "covariant", "deferred",
        "dynamic", "enum", "extends", "extension", "external", "factory",
        "final", "get", "hide", "implements", "in", "interface", "is",
        "late", "mixin", "new", "of", "on", "operator", "required",
        "sealed", "set", "show", "static", "sync", "typedef", "var",
        "void", "with", "when"
    };
 
    // Control-flow / module keywords (purple).
    static const char *controlKeywords[] = {
        "assert", "async", "await", "break", "case", "catch", "continue",
        "default", "do", "else", "export", "finally", "for", "if", "import",
        "library", "part", "rethrow", "return", "switch", "throw", "try",
        "while", "yield"
    };
 
    // Constants (bright blue).
    static const char *constants[] = {
        "true", "false", "null", "this", "super"
    };
 
    static const char *types[] = {
        "bool", "double", "int", "Never", "num", "Object", "String",
        "List", "Map", "Set", "Iterable", "Future", "Stream", "Duration",
        "DateTime", "Exception", "Error", "Function", "Null", "Type",
        "Record", "Symbol", "Uri", "RegExp"
    };
 
    const int keywordCount = int(sizeof(keywords) / sizeof(keywords[0]));
    const int controlCount = int(sizeof(controlKeywords) / sizeof(controlKeywords[0]));
    const int constantCount = int(sizeof(constants) / sizeof(constants[0]));
    const int typeCount = int(sizeof(types) / sizeof(types[0]));
 
    int bracketDepth = 0;
 
    int i = 0;
    while (i < n) {
        const char c = text.at(i);
 
        // Single-line comments.
        if (c == '/' && i + 1 < n && text.at(i + 1) == '/') {
            const bool doc = i + 2 < n && text.at(i + 2) == '/';
            int j = i + 2;
            while (j < n && text.at(j) != '\n')
                ++j;
            mark(i, j, doc ? DocComment : Comment);
            i = j;
            continue;
        }
 
        // Multiline comments.
        if (c == '/' && i + 1 < n && text.at(i + 1) == '*') {
            const bool doc = i + 2 < n && text.at(i + 2) == '*';
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
 
        // Raw strings: r'...' and r"...".
        const bool rawPrefix =
            (c == 'r' || c == 'R') &&
            i + 1 < n &&
            (text.at(i + 1) == '\'' || text.at(i + 1) == '"') &&
            (i == 0 || !isIdentifierChar(text.at(i - 1)));
 
        const int quotePos = rawPrefix ? i + 1 : i;
        if (quotePos < n &&
            (text.at(quotePos) == '\'' || text.at(quotePos) == '"')) {
            const char quote = text.at(quotePos);
            const bool triple =
                quotePos + 2 < n &&
                text.at(quotePos + 1) == quote &&
                text.at(quotePos + 2) == quote;
 
            const int contentStart = quotePos + (triple ? 3 : 1);
            const int stringStyle = rawPrefix ? RawString : String;
            int j = contentStart;
            bool closed = false;
 
            while (j < n) {
                if (triple && j + 2 < n &&
                    text.at(j) == quote &&
                    text.at(j + 1) == quote &&
                    text.at(j + 2) == quote) {
                    j += 3;
                    closed = true;
                    break;
                }
 
                if (!triple && text.at(j) == quote) {
                    ++j;
                    closed = true;
                    break;
                }
 
                if (!triple && text.at(j) == '\n')
                    break;
 
                if (!rawPrefix && text.at(j) == '\\' && j + 1 < n) {
                    j += 2;
                    continue;
                }
 
                // Skip over ${ ... } so quotes inside don't end the string.
                if (!rawPrefix && text.at(j) == '$' && j + 1 < n &&
                    text.at(j + 1) == '{') {
                    int k = j + 2;
                    int depth = 1;
                    while (k < n && depth > 0) {
                        if (text.at(k) == '{')
                            ++depth;
                        else if (text.at(k) == '}')
                            --depth;
                        ++k;
                    }
                    j = k;
                    continue;
                }
                ++j;
            }
 
            mark(i, j, closed ? stringStyle : Error);
 
            // Apply escapes and interpolations on top of the string style.
            if (!rawPrefix) {
                int k = contentStart;
                const int contentEnd = closed ? j - (triple ? 3 : 1) : j;
                while (k < contentEnd) {
                    if (text.at(k) == '\\' && k + 1 < contentEnd) {
                        mark(k, k + 2, EscapeSequence);
                        k += 2;
                    } else if (text.at(k) == '$' && k + 1 < contentEnd) {
                        const int interpStart = k;
                        if (text.at(k + 1) == '{') {
                            int depth = 1;
                            k += 2;
                            while (k < contentEnd && depth > 0) {
                                if (text.at(k) == '{')
                                    ++depth;
                                else if (text.at(k) == '}')
                                    --depth;
                                ++k;
                            }
                        } else if (isLetter(text.at(k + 1))) {
                            k += 2;
                            while (k < contentEnd &&
                                   isIdentifierChar(text.at(k)))
                                ++k;
                        } else {
                            ++k;
                            continue;
                        }
                        mark(interpStart, k, Interpolation);
                    } else {
                        ++k;
                    }
                }
            }
 
            i = j;
            continue;
        }
 
        // Annotations.
        if (c == '@') {
            int j = i + 1;
            while (j < n && isIdentifierChar(text.at(j)))
                ++j;
            mark(i, j, Annotation);
            i = j;
            continue;
        }
 
        // Keywords, types, functions, classes, and identifiers.
        if (isLetter(c)) {
            int j = i + 1;
            while (j < n && isIdentifierChar(text.at(j)))
                ++j;
 
            const QByteArray word = text.mid(i, j - i);
 
            int style = Identifier;
            if (contains(controlKeywords, controlCount, word)) {
                style = ControlKeyword;
            } else if (contains(constants, constantCount, word)) {
                style = Constant;
            } else if (contains(keywords, keywordCount, word)) {
                style = Keyword;
            } else if (contains(types, typeCount, word)) {
                style = Type;
            } else if (isUpper(word.at(0))) {
                style = ClassName;
            } else {
                // Lowercase identifier followed by '(' is a function call/definition.
                int k = j;
                while (k < n && (text.at(k) == ' ' || text.at(k) == '\t'))
                    ++k;
                if (k < n && (text.at(k) == '(' || text.at(k) == '<')) {
                    // '<' only counts when it looks like generics: name<Type>(
                    if (text.at(k) == '(')
                        style = Function;
                }
            }
 
            mark(i, j, style);
            i = j;
            continue;
        }
 
        // Numeric literals.
        if (isDigit(c)) {
            int j = i + 1;
            while (j < n) {
                const char d = text.at(j);
                if (isIdentifierChar(d)) {
                    ++j;
                    continue;
                }
                if (d == '.' && j + 1 < n &&
                    isDigit(text.at(j + 1))) {
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
 
        // Brackets colored by nesting depth (bracket pair colorization).
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
 
        // Operators and punctuation.
        if (QByteArray("+-*/%~!<>&|^?=:").contains(c))
            mark(i, i + 1, Operator);
 
        ++i;
    }
 
    // Apply only the requested styling interval.
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
 
