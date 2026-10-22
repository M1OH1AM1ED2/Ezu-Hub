#ifndef CPPLEXER_H
#define CPPLEXER_H
 
#include <Qsci/qscilexercustom.h>
 
class CppLexer : public QsciLexerCustom
{
    Q_OBJECT
 
public:
    enum Style {
        Default = 0,
        Keyword,        // class, const, int, void, auto ... (blue)
        ControlKeyword, // if, for, return, throw ... (purple)
        Constant,       // true, false, nullptr, this (bright blue)
        Type,           // std::string, vector, size_t ... (teal)
        ClassName,      // MyClass, namespaces (teal)
        Function,       // foo( ... (yellow)
        Macro,          // MY_MACRO (magenta)
        Identifier,     // variables (light blue)
        Preprocessor,   // #include, #define ... (purple)
        IncludePath,    // <iostream> (orange)
        Comment,
        DocComment,
        String,
        RawString,
        Number,
        Operator,
        EscapeSequence,
        Bracket1,       // gold
        Bracket2,       // orchid
        Bracket3,       // blue
        Error           // keep last
    };
 
    explicit CppLexer(QObject *parent = nullptr);
 
    const char *language() const override;
    QString description(int style) const override;
    void styleText(int start, int end) override;
    void setEditor(QsciScintilla *editor) override;
};
 
#endif
 
