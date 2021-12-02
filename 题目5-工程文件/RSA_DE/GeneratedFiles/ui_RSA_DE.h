/********************************************************************************
** Form generated from reading UI file 'RSA_DE.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RSA_DE_H
#define UI_RSA_DE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RSA_DEClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *Btn_GenKey_slt;
    QPushButton *Btn_ED_slt;
    QSpacerItem *verticalSpacer;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_2;
    QPushButton *Btn_Open_File;
    QSpacerItem *verticalSpacer_3;
    QPushButton *Btn_Save_file;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_6;
    QPlainTextEdit *plain_PlainText;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *com_Select;
    QPushButton *Btn_StartED;
    QSpacerItem *horizontalSpacer_3;
    QPlainTextEdit *plain_Ciper;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *Line_KeySize;
    QPushButton *Btn_Gen;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_Pub_E;
    QPlainTextEdit *plain_Pub_E;
    QLabel *label_Pub_N;
    QPlainTextEdit *plain_Pub_N;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_Pri_D;
    QPlainTextEdit *plain_Pri_D;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RSA_DEClass)
    {
        if (RSA_DEClass->objectName().isEmpty())
            RSA_DEClass->setObjectName(QStringLiteral("RSA_DEClass"));
        RSA_DEClass->resize(1153, 672);
        RSA_DEClass->setStyleSheet(QStringLiteral("border-top-color: rgb(170, 255, 255);"));
        centralWidget = new QWidget(RSA_DEClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QLatin1String("#centralWidget{border-image: url(:/RSA_DE/Resources/images/nanyou.jpg);}\n"
"\n"
""));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Btn_GenKey_slt = new QPushButton(centralWidget);
        Btn_GenKey_slt->setObjectName(QStringLiteral("Btn_GenKey_slt"));
        Btn_GenKey_slt->setMinimumSize(QSize(0, 35));
        Btn_GenKey_slt->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);\n"
"font: 9pt \"\345\271\274\345\234\206\";"));

        verticalLayout->addWidget(Btn_GenKey_slt);

        Btn_ED_slt = new QPushButton(centralWidget);
        Btn_ED_slt->setObjectName(QStringLiteral("Btn_ED_slt"));
        Btn_ED_slt->setMinimumSize(QSize(0, 35));
        Btn_ED_slt->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);\n"
"font: 9pt \"\345\271\274\345\234\206\";"));

        verticalLayout->addWidget(Btn_ED_slt);

        verticalSpacer = new QSpacerItem(20, 378, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        horizontalLayout_6 = new QHBoxLayout(page);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalSpacer_2 = new QSpacerItem(20, 118, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);

        Btn_Open_File = new QPushButton(page);
        Btn_Open_File->setObjectName(QStringLiteral("Btn_Open_File"));
        Btn_Open_File->setMinimumSize(QSize(0, 35));
        Btn_Open_File->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);\n"
"font: 9pt \"\345\271\274\345\234\206\";"));

        verticalLayout_5->addWidget(Btn_Open_File);

        verticalSpacer_3 = new QSpacerItem(20, 138, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        Btn_Save_file = new QPushButton(page);
        Btn_Save_file->setObjectName(QStringLiteral("Btn_Save_file"));
        Btn_Save_file->setMinimumSize(QSize(0, 35));
        Btn_Save_file->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);\n"
"font: 9pt \"\345\271\274\345\234\206\";"));

        verticalLayout_5->addWidget(Btn_Save_file);

        verticalSpacer_4 = new QSpacerItem(20, 158, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_4);


        horizontalLayout_6->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        plain_PlainText = new QPlainTextEdit(page);
        plain_PlainText->setObjectName(QStringLiteral("plain_PlainText"));
        plain_PlainText->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 100);\n"
"font: 9pt \"Consolas\";"));

        verticalLayout_6->addWidget(plain_PlainText);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(88, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        com_Select = new QComboBox(page);
        com_Select->setObjectName(QStringLiteral("com_Select"));
        com_Select->setMinimumSize(QSize(80, 32));
        com_Select->setMaximumSize(QSize(100, 16777215));
        com_Select->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);\n"
"font: 9pt \"\345\271\274\345\234\206\";"));

        horizontalLayout_5->addWidget(com_Select);

        Btn_StartED = new QPushButton(page);
        Btn_StartED->setObjectName(QStringLiteral("Btn_StartED"));
        Btn_StartED->setMaximumSize(QSize(80, 16777215));
        Btn_StartED->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);\n"
"font: 9pt \"\345\271\274\345\234\206\";"));

        horizontalLayout_5->addWidget(Btn_StartED);

        horizontalSpacer_3 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_6->addLayout(horizontalLayout_5);

        plain_Ciper = new QPlainTextEdit(page);
        plain_Ciper->setObjectName(QStringLiteral("plain_Ciper"));
        plain_Ciper->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 100);\n"
"font: 9pt \"Consolas\";"));

        verticalLayout_6->addWidget(plain_Ciper);


        horizontalLayout_6->addLayout(verticalLayout_6);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        verticalLayout_4 = new QVBoxLayout(page_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        Line_KeySize = new QLineEdit(page_2);
        Line_KeySize->setObjectName(QStringLiteral("Line_KeySize"));
        Line_KeySize->setMinimumSize(QSize(0, 32));
        Line_KeySize->setMaximumSize(QSize(140, 16777215));
        Line_KeySize->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 100);\n"
"font: 9pt \"Consolas\";"));

        horizontalLayout_2->addWidget(Line_KeySize);

        Btn_Gen = new QPushButton(page_2);
        Btn_Gen->setObjectName(QStringLiteral("Btn_Gen"));
        Btn_Gen->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);\n"
"font: 9pt \"\345\271\274\345\234\206\";"));

        horizontalLayout_2->addWidget(Btn_Gen);

        horizontalSpacer = new QSpacerItem(458, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_Pub_E = new QLabel(page_2);
        label_Pub_E->setObjectName(QStringLiteral("label_Pub_E"));
        label_Pub_E->setMaximumSize(QSize(50, 16777215));

        verticalLayout_2->addWidget(label_Pub_E);

        plain_Pub_E = new QPlainTextEdit(page_2);
        plain_Pub_E->setObjectName(QStringLiteral("plain_Pub_E"));
        plain_Pub_E->setMaximumSize(QSize(16777215, 100));
        plain_Pub_E->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 100);\n"
"font: 9pt \"Consolas\";"));
        plain_Pub_E->setLineWidth(1);

        verticalLayout_2->addWidget(plain_Pub_E);

        label_Pub_N = new QLabel(page_2);
        label_Pub_N->setObjectName(QStringLiteral("label_Pub_N"));
        label_Pub_N->setMaximumSize(QSize(50, 16777215));

        verticalLayout_2->addWidget(label_Pub_N);

        plain_Pub_N = new QPlainTextEdit(page_2);
        plain_Pub_N->setObjectName(QStringLiteral("plain_Pub_N"));
        plain_Pub_N->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 100);\n"
"font: 9pt \"Consolas\";"));
        plain_Pub_N->setLineWidth(10);

        verticalLayout_2->addWidget(plain_Pub_N);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_Pri_D = new QLabel(page_2);
        label_Pri_D->setObjectName(QStringLiteral("label_Pri_D"));
        label_Pri_D->setMaximumSize(QSize(50, 16777215));

        verticalLayout_3->addWidget(label_Pri_D);

        plain_Pri_D = new QPlainTextEdit(page_2);
        plain_Pri_D->setObjectName(QStringLiteral("plain_Pri_D"));
        plain_Pri_D->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 100);\n"
"font: 9pt \"Consolas\";"));
        plain_Pri_D->setLineWidth(6);

        verticalLayout_3->addWidget(plain_Pri_D);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_3);

        stackedWidget->addWidget(page_2);

        horizontalLayout->addWidget(stackedWidget);

        RSA_DEClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RSA_DEClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1153, 30));
        RSA_DEClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RSA_DEClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setStyleSheet(QStringLiteral("border-top-color: rgb(0, 0, 0);"));
        RSA_DEClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(RSA_DEClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RSA_DEClass->setStatusBar(statusBar);

        retranslateUi(RSA_DEClass);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(RSA_DEClass);
    } // setupUi

    void retranslateUi(QMainWindow *RSA_DEClass)
    {
        RSA_DEClass->setWindowTitle(QApplication::translate("RSA_DEClass", "RSA_DE", 0));
        Btn_GenKey_slt->setText(QApplication::translate("RSA_DEClass", "\347\224\237\346\210\220\345\257\206\351\222\245", 0));
        Btn_ED_slt->setText(QApplication::translate("RSA_DEClass", "\345\212\240\350\247\243\345\257\206", 0));
        Btn_Open_File->setText(QApplication::translate("RSA_DEClass", "\346\211\223\345\274\200\346\226\207\344\273\266", 0));
        Btn_Save_file->setText(QApplication::translate("RSA_DEClass", "\344\277\235\345\255\230\346\226\207\344\273\266", 0));
        plain_PlainText->setPlainText(QApplication::translate("RSA_DEClass", "\350\257\267\350\276\223\345\205\245\346\230\216\346\226\207\346\210\226\350\200\205\345\257\206\346\226\207...", 0));
        com_Select->clear();
        com_Select->insertItems(0, QStringList()
         << QApplication::translate("RSA_DEClass", "\345\212\240\345\257\206", 0)
         << QApplication::translate("RSA_DEClass", "\350\247\243\345\257\206", 0)
        );
        Btn_StartED->setText(QApplication::translate("RSA_DEClass", "\345\274\200\345\247\213", 0));
        Line_KeySize->setText(QString());
        Line_KeySize->setPlaceholderText(QApplication::translate("RSA_DEClass", "\350\257\267\350\276\223\345\205\245\345\257\206\351\222\245\344\275\215\346\225\260", 0));
        Btn_Gen->setText(QApplication::translate("RSA_DEClass", "\345\274\200\345\247\213\347\224\237\346\210\220", 0));
        label_Pub_E->setText(QApplication::translate("RSA_DEClass", "\345\205\254\351\222\245E", 0));
        label_Pub_N->setText(QApplication::translate("RSA_DEClass", "\345\205\254\351\222\245N", 0));
        label_Pri_D->setText(QApplication::translate("RSA_DEClass", "\347\247\201\351\222\245D", 0));
    } // retranslateUi

};

namespace Ui {
    class RSA_DEClass: public Ui_RSA_DEClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RSA_DE_H
