#include "gui.h"

gui::gui(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

gui::~gui()
{}

int gui::draw_node(Node* node, string& str, int id)
{
    return id;
}

void gui::generate_syntax_tree(Node* tree)
{

}

void gui::on_browseBTN_clicked() 
{

}

void gui::on_scan_parseBTN_clicked() 
{

}
