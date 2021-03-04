#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "SyntaxHighlightPlugin.h"

#include <QFileDialog>
#include <QPluginLoader>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // highlighter = new Highlighter(ui->textEdit->document());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadPluginFromFile()
{
    auto pluginName = QFileDialog::getOpenFileName(this, "Select highlighter plugin", QString(), "Plugin files (*.so *.dll)");
    this->loader = new QPluginLoader(pluginName);
    loader->load();
    if (loader->isLoaded()) {
        iface = qobject_cast<SyntaxHighlightPluginInterface*>(loader->instance());
        this->highlighter = iface->makeSyntaxHighlighterFor(this->ui->textEdit->document(), "1.cpp");
    } else
    {
        qDebug() << "Can't load plugin: " << this->loader->errorString();
    }
}

