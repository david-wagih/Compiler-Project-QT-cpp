#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_gui.h"

class gui : public QMainWindow
{
    Q_OBJECT

public:
    gui(QWidget *parent = nullptr);
    ~gui();

private slots:
    void on_browseBTN_clicked();
    void on_scan_parseBTN_clicked();

private:
    Ui::guiClass ui;
};
