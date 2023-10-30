/********************************************************************************
** Form generated from reading UI file 'newmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWMAINWINDOW_H
#define UI_NEWMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewMainWindow
{
public:
    QAction *actionReturn;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuTips;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *NewMainWindow)
    {
        if (NewMainWindow->objectName().isEmpty())
            NewMainWindow->setObjectName(QString::fromUtf8("NewMainWindow"));
        NewMainWindow->resize(800, 600);
        actionReturn = new QAction(NewMainWindow);
        actionReturn->setObjectName(QString::fromUtf8("actionReturn"));
        centralwidget = new QWidget(NewMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        NewMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(NewMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuTips = new QMenu(menubar);
        menuTips->setObjectName(QString::fromUtf8("menuTips"));
        NewMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(NewMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        NewMainWindow->setStatusBar(statusbar);

        menubar->addAction(menuTips->menuAction());
        menuTips->addAction(actionReturn);

        retranslateUi(NewMainWindow);

        QMetaObject::connectSlotsByName(NewMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *NewMainWindow)
    {
        NewMainWindow->setWindowTitle(QCoreApplication::translate("NewMainWindow", "MainWindow", nullptr));
        actionReturn->setText(QCoreApplication::translate("NewMainWindow", "Return", nullptr));
        menuTips->setTitle(QCoreApplication::translate("NewMainWindow", "Tips", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewMainWindow: public Ui_NewMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWMAINWINDOW_H
