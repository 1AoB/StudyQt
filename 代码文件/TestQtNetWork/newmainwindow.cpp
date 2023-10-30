#include "newmainwindow.h"
#include "ui_newmainwindow.h"

NewMainWindow::NewMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NewMainWindow)
{
    ui->setupUi(this);


}

NewMainWindow::~NewMainWindow()
{
    delete ui;
}

void NewMainWindow::on_pushButton_clicked()
{
    this->hide();
    emit changeFirst();
}


void NewMainWindow::on_actionReturn_triggered()
{
    //this->hide();
    emit changeFirst();
}

void NewMainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event); // 调用基类的 resizeEvent，确保正常的处理

    // 获取新的 mainwindow 大小
    QSize newSize = event->size();

    // 将新的大小应用于 view
    view->setFixedSize(newSize.width(), newSize.height());
}

