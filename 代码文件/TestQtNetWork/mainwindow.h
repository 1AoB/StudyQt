#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString NewPageStr;
public:
    Ui::MainWindow *ui;

signals:
    void changenew();
    //void changenew(QString);
    void Closenew();
private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    QNetworkAccessManager *manager;
    QNetworkReply *reply;


};
#endif // MAINWINDOW_H
