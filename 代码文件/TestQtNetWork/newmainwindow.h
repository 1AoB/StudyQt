#ifndef NEWMAINWINDOW_H
#define NEWMAINWINDOW_H

#include <QMainWindow>
#include <QResizeEvent>
#include <QWebEngineView>

namespace Ui {
class NewMainWindow;
}

class NewMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewMainWindow(QWidget *parent = nullptr);
    ~NewMainWindow();

    QWebEngineView *view;  //声明view
    Ui::NewMainWindow *ui;
    void resizeEvent(QResizeEvent *event);
signals:
    void changeFirst();
private slots:
    void on_pushButton_clicked();

    void on_actionReturn_triggered();

private:



};

#endif // NEWMAINWINDOW_H
