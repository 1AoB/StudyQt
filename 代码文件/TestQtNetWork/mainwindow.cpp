#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QJsonArray>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Weather"));



    manager = new QNetworkAccessManager(this);

    QUrl url("https://devapi.qweather.com/v7/weather/3d?location=101180901&key=7d5511e63aae4a1fba275834cb9b35f9"); // 替换成实际的 API 地址
    QNetworkRequest request(url);

    reply = manager->get(request);

    QObject::connect(reply, &QNetworkReply::finished, [&]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray responseData = reply->readAll();
            QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData);

            //处理json文件
            if (!jsonDocument.isNull() && jsonDocument.isObject()) {
                QJsonObject jsonObject = jsonDocument.object();
                // 现在你可以使用 jsonObject 来访问返回的 JSON 数据
                qDebug()<<jsonObject["code"].toString();//"200"
                qDebug()<<jsonObject["updateTime"].toString();//"2023-10-28T21:35+08:00"
                ui->label->setText("最近API更新时间:"+jsonObject["updateTime"].toString());
                qDebug()<<jsonObject["fxLink"].toString();//"https://www.qweather.com/weather/luoyang-101180901.html"
                NewPageStr = jsonObject["fxLink"].toString();

                QJsonArray jsonArray = jsonObject["daily"].toArray();
                QJsonObject jObj1 = jsonArray.at(0).toObject();
                QJsonObject jObj2 = jsonArray.at(0).toObject();
                QJsonObject jObj3 = jsonArray.at(0).toObject();
                qDebug()<<jObj1["fxDate"].toString();//"2023-10-28"
                ui->label_2->setText(jObj1["fxDate"].toString());
                ui->label_3->setText(jObj1["sunrise"].toString());
                ui->label_4->setText(jObj1["sunset"].toString());
                ui->label_5->setText(jObj1["moonrise"].toString());
                ui->label_6->setText(jObj1["moonset"].toString());
                ui->label_7->setText(jObj1["moonPhase"].toString());

                // 创建一个QNetworkAccessManager来下载图标
                QNetworkAccessManager* manager = new QNetworkAccessManager(this);

                QString iconUrl = "https://icons.qweather.com/assets/icons/"
                               +jObj1["moonPhaseIcon"].toString()
                               +".svg";
                // 发送GET请求来获取图标
                QNetworkRequest request;
                request.setUrl(QUrl(iconUrl));
                QNetworkReply* reply = manager->get(request);
                //
                // 处理下载完成后的回调
                connect(reply, &QNetworkReply::finished, [=]() {
                    if (reply->error() == QNetworkReply::NoError) {
                        // 读取下载的数据
                        QByteArray data = reply->readAll();

                        // 将数据转换成QPixmap
                        QPixmap pixmap;
                        pixmap.loadFromData(data);

                        // 将图标显示在QLabel中
                        ui->label_8->setPixmap(pixmap);
                    }
                    // 清理资源
                    reply->deleteLater();
                });
                //


                qDebug()<<jObj2["fxDate"].toString();//"2023-10-28"
                ui->label_9->setText(jObj2["fxDate"].toString());
                ui->label_10->setText(jObj2["sunrise"].toString());
                ui->label_11->setText(jObj2["sunset"].toString());
                ui->label_12->setText(jObj2["moonrise"].toString());
                ui->label_13->setText(jObj2["moonset"].toString());
                ui->label_14->setText(jObj2["moonPhase"].toString());


                iconUrl = "https://icons.qweather.com/assets/icons/"
                                  +jObj2["moonPhaseIcon"].toString()
                                  +".svg";
                // 发送GET请求来获取图标
                request.setUrl(QUrl(iconUrl));
                reply = manager->get(request);
                //
                // 处理下载完成后的回调
                connect(reply, &QNetworkReply::finished, [=]() {
                    if (reply->error() == QNetworkReply::NoError) {
                        // 读取下载的数据
                        QByteArray data = reply->readAll();

                        // 将数据转换成QPixmap
                        QPixmap pixmap;
                        pixmap.loadFromData(data);

                        // 将图标显示在QLabel中
                        ui->label_15->setPixmap(pixmap);
                    }
                    // 清理资源
                    reply->deleteLater();
                });
                //

                qDebug()<<jObj3["fxDate"].toString();//"2023-10-28"
                ui->label_16->setText(jObj2["fxDate"].toString());
                ui->label_17->setText(jObj2["sunrise"].toString());
                ui->label_18->setText(jObj2["sunset"].toString());
                ui->label_19->setText(jObj2["moonrise"].toString());
                ui->label_20->setText(jObj2["moonset"].toString());
                ui->label_21->setText(jObj2["moonPhase"].toString());


                iconUrl = "https://icons.qweather.com/assets/icons/"
                          +jObj2["moonPhaseIcon"].toString()
                          +".svg";
                // 发送GET请求来获取图标
                request.setUrl(QUrl(iconUrl));
                reply = manager->get(request);
                //
                // 处理下载完成后的回调
                connect(reply, &QNetworkReply::finished, [=]() {
                    if (reply->error() == QNetworkReply::NoError) {
                        // 读取下载的数据
                        QByteArray data = reply->readAll();

                        // 将数据转换成QPixmap
                        QPixmap pixmap;
                        pixmap.loadFromData(data);

                        // 将图标显示在QLabel中
                        ui->label_22->setPixmap(pixmap);
                    }
                    // 清理资源
                    reply->deleteLater();
                });
                //

            } else {
                qDebug() << "Error: Unable to parse JSON";
            }
        } else {
            qDebug() << "Error:" << reply->errorString();
        }

        reply->deleteLater();
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pushButton_clicked()
{
    //this->hide();
    emit changenew();
    //emit changenew(this->NewPageStr);
}


void MainWindow::on_pushButton_2_clicked()
{
    emit Closenew();
}

