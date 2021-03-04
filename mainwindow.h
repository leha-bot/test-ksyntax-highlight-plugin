#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSyntaxHighlighter>
#include <QPluginLoader>
#include "SyntaxHighlightPlugin.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void loadPluginFromFile();

private:
    Ui::MainWindow *ui;
    QSyntaxHighlighter *highlighter;
    SyntaxHighlightPluginInterface *iface;
    QPluginLoader *loader;
};
#endif // MAINWINDOW_H
