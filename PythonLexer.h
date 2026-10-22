#ifndef PYTHONLEXER_H
#define PYTHONLEXER_H
 
#include <Qsci/qscilexercustom.h>
 
class PythonLexer : public QsciLexerCustom
{
    Q_OBJECT
 
public:
    enum Style {
        Default = 0,
        Keyword,        // def, class, lambda, and, or, not, in, is ... (blue)
        ControlKeyword, // if, for, return, import, try ... (purple)
        Constant,       // True, False, None, MAX_VALUE (bright blue)
        Type,           // int, str, list, dict ... (teal)
        ClassName,      // MyClass, ValueError (teal)
        Function,       // def name, print(, foo( (yellow)
        SelfParam,      // self, cls (blue, italic)
        Identifier,     // variables (light blue)
        Comment,
        String,
        RawString,
        Number,
        Operator,
        Decorator,      // @property (yellow)
        EscapeSequence,
        Interpolation,  // {expr} inside f-strings
        Bracket1,       // gold
        Bracket2,       // orchid
        Bracket3,       // blue
        Error           // keep last
    };
 
    explicit PythonLexer(QObject *parent = nullptr);
 
    const char *language() const override;
    QString description(int style) const override;
    void styleText(int start, int end) override;
    void setEditor(QsciScintilla *editor) override;
};
 
#endif
 
