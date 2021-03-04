#ifndef SYNTAXHIGHLIGHTPLUGIN_H
#define SYNTAXHIGHLIGHTPLUGIN_H

#include <QObject>
#include <QSyntaxHighlighter>

#define IID_SyntaxHighlightPluginInterface "org.procxx.kepka.SyntaxHighlight/0.1"

class SyntaxHighlightPluginInterface
{
public:
    virtual ~SyntaxHighlightPluginInterface() = default;

    /// \brief Создает раскрашиватель синтаксиса для определенного языка, заданного \ref syntaxHint.
    /// \param parent Обязательный родительский QTextDocument для объекта-раскрашивателя.
    /// \param syntaxHint Простой идентификатор языка, например, "cpp", "js", "java".
    virtual QSyntaxHighlighter *makeSyntaxHighlighterFor(QTextDocument *parent, const QString &syntaxHint = "") = 0;

    static constexpr const char *pluginId = IID_SyntaxHighlightPluginInterface;
};

Q_DECLARE_INTERFACE(SyntaxHighlightPluginInterface, IID_SyntaxHighlightPluginInterface)

#endif // SYNTAXHIGHLIGHTPLUGIN_H
