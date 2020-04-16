#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void nextmonth_cal();
    void prevmonth_cal();
    void selected_day_label();
    void open_MyCalendarDialog();
    void open_MyCalendarAddDialog();
    void open_MyCalendarDeleteDialog();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
