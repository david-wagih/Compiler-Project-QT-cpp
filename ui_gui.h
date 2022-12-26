/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_guiClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *tokensLabel;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *syntaxTreeLabel;
    QFrame *line_4;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *inputLabel;
    QFrame *line_1;
    QFrame *breakLine;
    QFrame *line_3;
    QWidget *widget_1;
    QGridLayout *gridLayout_2;
    QLineEdit *filePathText;
    QLabel *fileLabel;
    QPushButton *browseBTN;
    QPushButton *scan_parseBTN;
    QFrame *line_2;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *listOfTokens;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_2;
    QPlainTextEdit *inputProgram;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout;
    QLabel *pictureLabel;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *guiClass)
    {
        if (guiClass->objectName().isEmpty())
            guiClass->setObjectName("guiClass");
        guiClass->resize(1000, 548);
        guiClass->setMinimumSize(QSize(1000, 500));
        centralWidget = new QWidget(guiClass);
        centralWidget->setObjectName("centralWidget");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        widget_3 = new QWidget(centralWidget);
        widget_3->setObjectName("widget_3");
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        tokensLabel = new QLabel(widget_3);
        tokensLabel->setObjectName("tokensLabel");
        tokensLabel->setMaximumSize(QSize(591, 16777215));
        QFont font;
        font.setPointSize(14);
        tokensLabel->setFont(font);

        verticalLayout_3->addWidget(tokensLabel);


        gridLayout->addWidget(widget_3, 2, 2, 1, 1);

        widget_4 = new QWidget(centralWidget);
        widget_4->setObjectName("widget_4");
        verticalLayout_4 = new QVBoxLayout(widget_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName("verticalLayout_4");
        syntaxTreeLabel = new QLabel(widget_4);
        syntaxTreeLabel->setObjectName("syntaxTreeLabel");
        syntaxTreeLabel->setFont(font);

        verticalLayout_4->addWidget(syntaxTreeLabel);


        gridLayout->addWidget(widget_4, 2, 4, 1, 1);

        line_4 = new QFrame(centralWidget);
        line_4->setObjectName("line_4");
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 3, 3, 1, 1);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        inputLabel = new QLabel(widget_2);
        inputLabel->setObjectName("inputLabel");
        inputLabel->setFont(font);

        horizontalLayout_2->addWidget(inputLabel);


        gridLayout->addWidget(widget_2, 2, 0, 1, 1);

        line_1 = new QFrame(centralWidget);
        line_1->setObjectName("line_1");
        line_1->setFrameShape(QFrame::VLine);
        line_1->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_1, 2, 1, 1, 1);

        breakLine = new QFrame(centralWidget);
        breakLine->setObjectName("breakLine");
        breakLine->setFrameShape(QFrame::HLine);
        breakLine->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(breakLine, 1, 0, 1, 5);

        line_3 = new QFrame(centralWidget);
        line_3->setObjectName("line_3");
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 3, 1, 1, 1);

        widget_1 = new QWidget(centralWidget);
        widget_1->setObjectName("widget_1");
        gridLayout_2 = new QGridLayout(widget_1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName("gridLayout_2");
        filePathText = new QLineEdit(widget_1);
        filePathText->setObjectName("filePathText");
        filePathText->setReadOnly(true);

        gridLayout_2->addWidget(filePathText, 0, 1, 1, 1);

        fileLabel = new QLabel(widget_1);
        fileLabel->setObjectName("fileLabel");
        fileLabel->setFont(font);

        gridLayout_2->addWidget(fileLabel, 0, 0, 1, 1);

        browseBTN = new QPushButton(widget_1);
        browseBTN->setObjectName("browseBTN");
        QFont font1;
        font1.setPointSize(11);
        browseBTN->setFont(font1);

        gridLayout_2->addWidget(browseBTN, 0, 2, 1, 1);

        scan_parseBTN = new QPushButton(widget_1);
        scan_parseBTN->setObjectName("scan_parseBTN");
        scan_parseBTN->setFont(font1);

        gridLayout_2->addWidget(scan_parseBTN, 1, 1, 1, 1);


        gridLayout->addWidget(widget_1, 0, 0, 1, 5);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 2, 3, 1, 1);

        widget_6 = new QWidget(centralWidget);
        widget_6->setObjectName("widget_6");
        widget_6->setMinimumSize(QSize(320, 300));
        widget_6->setMaximumSize(QSize(609, 16777215));
        horizontalLayout = new QHBoxLayout(widget_6);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        listOfTokens = new QPlainTextEdit(widget_6);
        listOfTokens->setObjectName("listOfTokens");
        listOfTokens->setMinimumSize(QSize(300, 300));
        listOfTokens->setReadOnly(true);

        horizontalLayout->addWidget(listOfTokens);


        gridLayout->addWidget(widget_6, 3, 2, 1, 1, Qt::AlignHCenter);

        widget_5 = new QWidget(centralWidget);
        widget_5->setObjectName("widget_5");
        widget_5->setMinimumSize(QSize(320, 300));
        verticalLayout_2 = new QVBoxLayout(widget_5);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        inputProgram = new QPlainTextEdit(widget_5);
        inputProgram->setObjectName("inputProgram");
        inputProgram->setMinimumSize(QSize(300, 300));
        inputProgram->setReadOnly(true);

        verticalLayout_2->addWidget(inputProgram);


        gridLayout->addWidget(widget_5, 3, 0, 1, 1, Qt::AlignHCenter);

        widget_7 = new QWidget(centralWidget);
        widget_7->setObjectName("widget_7");
        widget_7->setMinimumSize(QSize(320, 300));
        verticalLayout = new QVBoxLayout(widget_7);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        pictureLabel = new QLabel(widget_7);
        pictureLabel->setObjectName("pictureLabel");
        pictureLabel->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(pictureLabel, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        gridLayout->addWidget(widget_7, 3, 4, 1, 1);

        guiClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(guiClass);
        mainToolBar->setObjectName("mainToolBar");
        guiClass->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(guiClass);

        QMetaObject::connectSlotsByName(guiClass);
    } // setupUi

    void retranslateUi(QMainWindow *guiClass)
    {
        guiClass->setWindowTitle(QCoreApplication::translate("guiClass", "Tiny Language Compiler", nullptr));
        tokensLabel->setText(QCoreApplication::translate("guiClass", "List of Tokens", nullptr));
        syntaxTreeLabel->setText(QCoreApplication::translate("guiClass", "Syntax Tree", nullptr));
        inputLabel->setText(QCoreApplication::translate("guiClass", "Program", nullptr));
        fileLabel->setText(QCoreApplication::translate("guiClass", "Choose an input file", nullptr));
        browseBTN->setText(QCoreApplication::translate("guiClass", "Browse", nullptr));
        scan_parseBTN->setText(QCoreApplication::translate("guiClass", "Generate Syntax Tree", nullptr));
        pictureLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class guiClass: public Ui_guiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
