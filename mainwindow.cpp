#include <string>
#include <QDate>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mycalendardialog.h"
#include "mycalendaradddialog.h"
#include "mycalendardeletedialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->centralwidget);
    connect(ui->nextmonth_header_button, SIGNAL (released()), this, SLOT(nextmonth_cal()));
    connect(ui->prevmonth_header_button, SIGNAL (released()), this, SLOT(prevmonth_cal()));
    connect(ui->calendar, SIGNAL(selectionChanged()),this, SLOT(selected_day_label()));
    connect(ui->actionSee_calendars, SIGNAL(triggered()) ,this, SLOT(open_MyCalendarDialog()));
    connect(ui->actionDelete_calendar, SIGNAL(triggered()), this, SLOT(open_MyCalendarDeleteDialog()));
    connect(ui->actionAdd_calendar, SIGNAL(triggered()), this, SLOT(open_MyCalendarAddDialog()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::nextmonth_cal(){
    ui->calendar->showNextMonth();
    QString name_month = QDate::longMonthName(ui->calendar->monthShown());
    QString name_year = QVariant(ui->calendar->yearShown()).toString();
    ui->month_header_label->setText(name_month);
    ui->year_header_label->setText(name_year);
}
void MainWindow::prevmonth_cal(){
    ui->calendar->showPreviousMonth();
    QString name_month = QDate::longMonthName(ui->calendar->monthShown());
    QString name_year = QVariant(ui->calendar->yearShown()).toString();
    ui->month_header_label->setText(name_month);
    ui->year_header_label->setText(name_year);
}
void MainWindow::selected_day_label(){
    QDate date = ui->calendar->selectedDate();
    ui->day_number_label->setText(QVariant(date.day()).toString());
    QString numberday_week = QDate::longDayName(date.dayOfWeek());
    ui->day_of_week_label->setText(numberday_week);
    QString m_an_y = QDate::longMonthName(date.month())+ " " + QVariant(date.year()).toString();
    ui->month_and_year_label->setText(m_an_y);
    QString name_month = QDate::longMonthName(ui->calendar->monthShown());
    QString name_year = QVariant(ui->calendar->yearShown()).toString();
    ui->month_header_label->setText(name_month);
    ui->year_header_label->setText(name_year);
}
void MainWindow::open_MyCalendarDialog(){
    MyCalendarDialog myCalendarDialog;
    myCalendarDialog.setModal(true);
    myCalendarDialog.exec();
}

void MainWindow::open_MyCalendarAddDialog(){
    MyCalendarAddDialog myCalendarAddDialog;
    myCalendarAddDialog.setModal(true);
    myCalendarAddDialog.exec();
}

void MainWindow::open_MyCalendarDeleteDialog(){
    MyCalendarDeleteDialog myCalendarDeleteDialog;
    myCalendarDeleteDialog.setModal(true);
    myCalendarDeleteDialog.exec();
}
