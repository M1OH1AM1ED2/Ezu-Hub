#ifndef DARTLEXER_H
#define DARTLEXER_H
 
#include <Qsci/qscilexercustom.h>
 
class DartLexer : public QsciLexerCustom
{
    Q_OBJECT
 
public:
    enum Style {
        Default = 0,
        Keyword,        // class, final, var, void ... (blue)
        ControlKeyword, // if, return, import, await ... (purple)
        Constant,       // true, false, null, this, super (blue)
        Type,           // int, String, List ... (teal)
        ClassName,      // MyWidget, State ... (teal)
        Function,       // foo( ... (yellow)
        Identifier,     // variables (light blue)
        Comment,
        DocComment,
        String,
        RawString,
        Number,
        Operator,
        Annotation,
        EscapeSequence,
        Interpolation,
        Bracket1,       // gold
        Bracket2,       // orchid
        Bracket3,       // blue
        Error           // keep last
    };
 
    explicit DartLexer(QObject *parent = nullptr);
 
    const char *language() const override;
    QString description(int style) const override;
    void styleText(int start, int end) override;
    void setEditor(QsciScintilla *editor) override;
};
 
#endif
 
