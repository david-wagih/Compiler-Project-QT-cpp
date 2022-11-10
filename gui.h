#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_gui.h"

class gui : public QMainWindow
{
    Q_OBJECT

public:
    gui(QWidget *parent = nullptr);
    ~gui();

private:
    Ui::guiClass ui;
};
