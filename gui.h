#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_gui.h"
#include "parser.h"
#include <QFileDialog>
#include <string>
#include <QString>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <C:\Program Files\Graphviz\include\graphviz\gvc.h>
#include <C:\Program Files\Graphviz\include\graphviz\cdt.h>
#include <C:\Program Files\Graphviz\include\graphviz\cgraph.h>

class gui : public QMainWindow
{
    Q_OBJECT

public:
    gui(QWidget *parent = nullptr);
    ~gui();

private slots:
    int draw_node(Node* node, string& str, int id);
    void generate_syntax_tree(Node* tree);
    void on_browseBTN_clicked();
    void on_scan_parseBTN_clicked();

private:
    Ui::guiClass ui;
};
