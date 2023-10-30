#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newmainwindow.h"
#include "ui_newmainwindow.h"

#include <QApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QObject>
#include <QStringLiteral>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    NewMainWindow nw;
    //w.ui->pushButton
    w.show();

    QObject::connect(&w,&MainWindow::changenew,
    &nw,[&](){
        nw.view = new QWebEngineView(&nw);
        nw.view->load(QUrl(w.NewPageStr.toUtf8().constData()));
        nw.view->setFixedSize(nw.width(),nw.height());
        nw.view->showMaximized();
        nw.show();
    });
    QObject::connect(&w,&MainWindow::Closenew,
    &nw,[&](){
        nw.hide();
    });
    QObject::connect(&nw,&NewMainWindow::changeFirst,
     &w,[&](){
         w.show();
     });


    return a.exec();
}
