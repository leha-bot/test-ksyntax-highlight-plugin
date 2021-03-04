#include <SyntaxHighlightPlugin.h>

#include <KSyntaxHighlighting/SyntaxHighlighter>
#include <KSyntaxHighlighting/Repository>
#include <KSyntaxHighlighting/Theme>
#include <KSyntaxHighlighting/Definition>

class KSyntaxHighlightingPlugin : public QObject, public SyntaxHighlightPluginInterface
{
    Q_OBJECT
    Q_INTERFACES(SyntaxHighlightPluginInterface)
    Q_PLUGIN_METADATA(IID IID_SyntaxHighlightPluginInterface)

    // SyntaxHighlightPluginInterface interface
    KSyntaxHighlighting::Repository repo; // all syntax highlights.
public:
    QSyntaxHighlighter *makeSyntaxHighlighterFor(QTextDocument *parent, const QString &syntaxHint) override
    {
        auto highlighter = new KSyntaxHighlighting::SyntaxHighlighter(parent);
        highlighter->setTheme(repo.defaultTheme());
        auto def = repo.definitionForFileName(QStringLiteral("test.") + syntaxHint);
        highlighter->setDefinition(def);
        return highlighter;
    }
};
#include "ExampleHighlighterKSyntaxPlugin.moc"
