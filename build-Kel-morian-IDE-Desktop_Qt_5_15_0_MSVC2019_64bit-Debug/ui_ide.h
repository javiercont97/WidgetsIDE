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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IDE
{
public:
    QAction *actionNew_Project;
    QAction *actionOpen_Project;
    QAction *actionCloses_Project;
    QAction *actionExit_program;
    QAction *actionSave;
    QAction *actionExit_program_2;
    QAction *actionRun;
    QAction *actionDeply;
    QAction *actionHelp;
    QAction *actionAbout;
    QWidget *centralwidget;
    QSplitter *splitter;
    QListWidget *widgetsList;
    QGraphicsView *uiCanvas;
    QFrame *verticalFrame;
    QVBoxLayout *verticalLayout;
    QTreeView *structView;
    QTreeView *propertyView;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuBuild;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *IDE)
    {
        if (IDE->objectName().isEmpty())
            IDE->setObjectName(QString::fromUtf8("IDE"));
        IDE->resize(825, 545);
        actionNew_Project = new QAction(IDE);
        actionNew_Project->setObjectName(QString::fromUtf8("actionNew_Project"));
        actionOpen_Project = new QAction(IDE);
        actionOpen_Project->setObjectName(QString::fromUtf8("actionOpen_Project"));
        actionCloses_Project = new QAction(IDE);
        actionCloses_Project->setObjectName(QString::fromUtf8("actionCloses_Project"));
        actionExit_program = new QAction(IDE);
        actionExit_program->setObjectName(QString::fromUtf8("actionExit_program"));
        actionSave = new QAction(IDE);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionExit_program_2 = new QAction(IDE);
        actionExit_program_2->setObjectName(QString::fromUtf8("actionExit_program_2"));
        actionRun = new QAction(IDE);
        actionRun->setObjectName(QString::fromUtf8("actionRun"));
        actionDeply = new QAction(IDE);
        actionDeply->setObjectName(QString::fromUtf8("actionDeply"));
        actionHelp = new QAction(IDE);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        actionAbout = new QAction(IDE);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralwidget = new QWidget(IDE);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(130, 20, 512, 192));
        splitter->setOrientation(Qt::Horizontal);
        widgetsList = new QListWidget(splitter);
        widgetsList->setObjectName(QString::fromUtf8("widgetsList"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetsList->sizePolicy().hasHeightForWidth());
        widgetsList->setSizePolicy(sizePolicy);
        splitter->addWidget(widgetsList);
        uiCanvas = new QGraphicsView(splitter);
        uiCanvas->setObjectName(QString::fromUtf8("uiCanvas"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(5);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(uiCanvas->sizePolicy().hasHeightForWidth());
        uiCanvas->setSizePolicy(sizePolicy1);
        splitter->addWidget(uiCanvas);
        verticalFrame = new QFrame(splitter);
        verticalFrame->setObjectName(QString::fromUtf8("verticalFrame"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(verticalFrame->sizePolicy().hasHeightForWidth());
        verticalFrame->setSizePolicy(sizePolicy2);
        verticalLayout = new QVBoxLayout(verticalFrame);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        structView = new QTreeView(verticalFrame);
        structView->setObjectName(QString::fromUtf8("structView"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(structView->sizePolicy().hasHeightForWidth());
        structView->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(structView);

        propertyView = new QTreeView(verticalFrame);
        propertyView->setObjectName(QString::fromUtf8("propertyView"));

        verticalLayout->addWidget(propertyView);

        splitter->addWidget(verticalFrame);
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

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuBuild->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew_Project);
        menuFile->addAction(actionOpen_Project);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionCloses_Project);
        menuFile->addSeparator();
        menuFile->addAction(actionExit_program_2);
        menuBuild->addAction(actionRun);
        menuBuild->addAction(actionDeply);
        menuHelp->addAction(actionHelp);
        menuHelp->addAction(actionAbout);

        retranslateUi(IDE);

        QMetaObject::connectSlotsByName(IDE);
    } // setupUi

    void retranslateUi(QMainWindow *IDE)
    {
        IDE->setWindowTitle(QCoreApplication::translate("IDE", "MainWindow", nullptr));
        actionNew_Project->setText(QCoreApplication::translate("IDE", "New Project", nullptr));
        actionOpen_Project->setText(QCoreApplication::translate("IDE", "Open Project", nullptr));
        actionCloses_Project->setText(QCoreApplication::translate("IDE", "Close Project", nullptr));
        actionExit_program->setText(QCoreApplication::translate("IDE", "Exit program", nullptr));
        actionSave->setText(QCoreApplication::translate("IDE", "Save", nullptr));
        actionExit_program_2->setText(QCoreApplication::translate("IDE", "Exit program", nullptr));
        actionRun->setText(QCoreApplication::translate("IDE", "Run", nullptr));
        actionDeply->setText(QCoreApplication::translate("IDE", "Deploy", nullptr));
        actionHelp->setText(QCoreApplication::translate("IDE", "Help", nullptr));
        actionAbout->setText(QCoreApplication::translate("IDE", "About", nullptr));
        menuFile->setTitle(QCoreApplication::translate("IDE", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("IDE", "Edit", nullptr));
        menuBuild->setTitle(QCoreApplication::translate("IDE", "Build", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("IDE", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IDE: public Ui_IDE {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IDE_H
