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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "editor/codeeditor.h"

QT_BEGIN_NAMESPACE

class Ui_IDE
{
public:
    QAction *actionNew_Project;
    QAction *actionOpen_Project;
    QAction *actionSave;
    QAction *actionExit_program_2;
    QAction *actionRun;
    QAction *actionDeploy;
    QAction *actionHelp;
    QAction *actionAbout;
    QAction *actionCopy;
    QAction *actionCut;
    QAction *actionPaste;
    QAction *actionSelect_all;
    QWidget *centralwidget;
    CodeEditor *plainTextEdit;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuBuild;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *IDE)
    {
        if (IDE->objectName().isEmpty())
            IDE->setObjectName(QString::fromUtf8("IDE"));
        IDE->resize(825, 545);
        actionNew_Project = new QAction(IDE);
        actionNew_Project->setObjectName(QString::fromUtf8("actionNew_Project"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew_Project->setIcon(icon);
        actionOpen_Project = new QAction(IDE);
        actionOpen_Project->setObjectName(QString::fromUtf8("actionOpen_Project"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_Project->setIcon(icon1);
        actionSave = new QAction(IDE);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionExit_program_2 = new QAction(IDE);
        actionExit_program_2->setObjectName(QString::fromUtf8("actionExit_program_2"));
        actionRun = new QAction(IDE);
        actionRun->setObjectName(QString::fromUtf8("actionRun"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun->setIcon(icon3);
        actionDeploy = new QAction(IDE);
        actionDeploy->setObjectName(QString::fromUtf8("actionDeploy"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/box.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDeploy->setIcon(icon4);
        actionHelp = new QAction(IDE);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        actionAbout = new QAction(IDE);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionCopy = new QAction(IDE);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon5);
        actionCut = new QAction(IDE);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon6);
        actionPaste = new QAction(IDE);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon7);
        actionSelect_all = new QAction(IDE);
        actionSelect_all->setObjectName(QString::fromUtf8("actionSelect_all"));
        centralwidget = new QWidget(IDE);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        plainTextEdit = new CodeEditor(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(210, 50, 256, 192));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(4);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy);
        IDE->setCentralWidget(centralwidget);
        menubar = new QMenuBar(IDE);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 825, 20));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuBuild = new QMenu(menubar);
        menuBuild->setObjectName(QString::fromUtf8("menuBuild"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        IDE->setMenuBar(menubar);
        statusbar = new QStatusBar(IDE);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        IDE->setStatusBar(statusbar);
        toolBar = new QToolBar(IDE);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        IDE->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuBuild->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew_Project);
        menuFile->addAction(actionOpen_Project);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionExit_program_2);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionPaste);
        menuEdit->addSeparator();
        menuEdit->addAction(actionSelect_all);
        menuBuild->addAction(actionRun);
        menuBuild->addAction(actionDeploy);
        menuHelp->addAction(actionHelp);
        menuHelp->addAction(actionAbout);
        toolBar->addAction(actionNew_Project);
        toolBar->addAction(actionOpen_Project);
        toolBar->addAction(actionSave);
        toolBar->addSeparator();
        toolBar->addAction(actionRun);
        toolBar->addAction(actionDeploy);
        toolBar->addSeparator();
        toolBar->addAction(actionCopy);
        toolBar->addAction(actionCut);
        toolBar->addAction(actionPaste);

        retranslateUi(IDE);

        QMetaObject::connectSlotsByName(IDE);
    } // setupUi

    void retranslateUi(QMainWindow *IDE)
    {
        IDE->setWindowTitle(QCoreApplication::translate("IDE", "MainWindow", nullptr));
        actionNew_Project->setText(QCoreApplication::translate("IDE", "New", nullptr));
#if QT_CONFIG(tooltip)
        actionNew_Project->setToolTip(QCoreApplication::translate("IDE", "New", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionNew_Project->setShortcut(QCoreApplication::translate("IDE", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen_Project->setText(QCoreApplication::translate("IDE", "Open", nullptr));
#if QT_CONFIG(tooltip)
        actionOpen_Project->setToolTip(QCoreApplication::translate("IDE", "Open", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionOpen_Project->setShortcut(QCoreApplication::translate("IDE", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("IDE", "Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("IDE", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit_program_2->setText(QCoreApplication::translate("IDE", "Exit program", nullptr));
#if QT_CONFIG(shortcut)
        actionExit_program_2->setShortcut(QCoreApplication::translate("IDE", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRun->setText(QCoreApplication::translate("IDE", "Run", nullptr));
#if QT_CONFIG(shortcut)
        actionRun->setShortcut(QCoreApplication::translate("IDE", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDeploy->setText(QCoreApplication::translate("IDE", "Make Package", nullptr));
#if QT_CONFIG(shortcut)
        actionDeploy->setShortcut(QCoreApplication::translate("IDE", "Ctrl+K, Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionHelp->setText(QCoreApplication::translate("IDE", "Help", nullptr));
        actionAbout->setText(QCoreApplication::translate("IDE", "About", nullptr));
        actionCopy->setText(QCoreApplication::translate("IDE", "Copy", nullptr));
#if QT_CONFIG(shortcut)
        actionCopy->setShortcut(QCoreApplication::translate("IDE", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCut->setText(QCoreApplication::translate("IDE", "Cut", nullptr));
#if QT_CONFIG(shortcut)
        actionCut->setShortcut(QCoreApplication::translate("IDE", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPaste->setText(QCoreApplication::translate("IDE", "Paste", nullptr));
#if QT_CONFIG(shortcut)
        actionPaste->setShortcut(QCoreApplication::translate("IDE", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSelect_all->setText(QCoreApplication::translate("IDE", "Select all", nullptr));
        menuFile->setTitle(QCoreApplication::translate("IDE", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("IDE", "Edit", nullptr));
        menuBuild->setTitle(QCoreApplication::translate("IDE", "Build", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("IDE", "Help", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("IDE", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IDE: public Ui_IDE {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IDE_H
