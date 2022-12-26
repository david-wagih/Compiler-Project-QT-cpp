#ifndef GUI_H
#define GUI_H

#include <QMainWindow>
#include "ui_gui.h"
#include "parser.h"
#include <QFileDialog>
#include <QMessageBox>
#include "gvc.h"
#include "cdt.h"
#include "cgraph.h"

QT_BEGIN_NAMESPACE
namespace Ui { class gui; }
QT_END_NAMESPACE

class gui : public QMainWindow
{
    Q_OBJECT

public:
    gui(QWidget* parent = nullptr);
    ~gui();

private slots:
    int draw_node(Node* node, string& str, int id);
    void generate_syntax_tree(Node* tree);
    void on_browseBTN_clicked();
    void on_scan_parseBTN_clicked();

private:
    Ui::guiClass ui;
};

#endif // GUI_H
