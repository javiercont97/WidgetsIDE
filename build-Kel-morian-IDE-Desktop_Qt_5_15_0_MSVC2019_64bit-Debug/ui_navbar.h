/********************************************************************************
** Form generated from reading UI file 'navbar.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAVBAR_H
#define UI_NAVBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NavBar
{
public:
    QHBoxLayout *horizontalLayout_2;
    QLabel *icon;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *navs;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnUser;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *NavBar)
    {
        if (NavBar->objectName().isEmpty())
            NavBar->setObjectName(QString::fromUtf8("NavBar"));
        NavBar->resize(971, 82);
        horizontalLayout_2 = new QHBoxLayout(NavBar);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        icon = new QLabel(NavBar);
        icon->setObjectName(QString::fromUtf8("icon"));

        horizontalLayout_2->addWidget(icon);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        navs = new QHBoxLayout();
        navs->setObjectName(QString::fromUtf8("navs"));

        horizontalLayout->addLayout(navs);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnUser = new QPushButton(NavBar);
        btnUser->setObjectName(QString::fromUtf8("btnUser"));

        horizontalLayout->addWidget(btnUser);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(NavBar);

        QMetaObject::connectSlotsByName(NavBar);
    } // setupUi

    void retranslateUi(QWidget *NavBar)
    {
        NavBar->setWindowTitle(QCoreApplication::translate("NavBar", "Form", nullptr));
        icon->setText(QCoreApplication::translate("NavBar", "TextLabel", nullptr));
        btnUser->setText(QCoreApplication::translate("NavBar", "Username", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NavBar: public Ui_NavBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVBAR_H
