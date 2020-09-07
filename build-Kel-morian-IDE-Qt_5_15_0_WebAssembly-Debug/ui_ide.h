/********************************************************************************
** Form generated from reading UI file 'ide.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IDE_H
#define UI_IDE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IDE
{
public:
    QWidget *centralwidget;
    QRadioButton *radioButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *IDE)
    {
        if (IDE->objectName().isEmpty())
            IDE->setObjectName(QString::fromUtf8("IDE"));
        IDE->resize(797, 532);
        centralwidget = new QWidget(IDE);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(210, 160, 84, 19));
        IDE->setCentralWidget(centralwidget);
        menubar = new QMenuBar(IDE);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 797, 20));
        IDE->setMenuBar(menubar);
        statusbar = new QStatusBar(IDE);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        IDE->setStatusBar(statusbar);

        retranslateUi(IDE);

        QMetaObject::connectSlotsByName(IDE);
    } // setupUi

    void retranslateUi(QMainWindow *IDE)
    {
        IDE->setWindowTitle(QCoreApplication::translate("IDE", "MainWindow", nullptr));
        radioButton->setText(QCoreApplication::translate("IDE", "RadioButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IDE: public Ui_IDE {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IDE_H
