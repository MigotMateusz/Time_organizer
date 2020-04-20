#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "eventdialog.h"
#include "dataaggregator.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    DataAggregator *datamanager;

private slots:
    void nextmonth_cal();
    void prevmonth_cal();
    void selected_day_label();
    void open_MyCalendarDialog();
    void open_EventDialog();
    void refresh_dynamic_label();
    void open_agendaDialog();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
