#include <string>
#include <QDate>
#include <QLocale>
#include <QListWidget>
#include <QDesktopServices>
#include <QCalendarWidget>
#include <QToolTip>
#include <QDebug>
#include <QUrl>
#include <functional>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mycalendardialog.h"
#include "mycalendaradddialog.h"
#include "agendadialog.h"
#include "keyshortcutsdialog.h"
#include "todolistdialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->centralwidget);
    this->selected_day_label();
    connect(ui->nextmonth_header_button, SIGNAL (released()), this, SLOT(nextmonth_cal()));
    connect(ui->prevmonth_header_button, SIGNAL (released()), this, SLOT(prevmonth_cal()));
    connect(ui->calendar, SIGNAL(selectionChanged()),this, SLOT(selected_day_label()));
    connect(ui->calendar, SIGNAL(selectionChanged()),this, SLOT(refresh_dynamic_label()));
    connect(ui->actionSee_Agenda, SIGNAL(triggered()), this, SLOT(open_agendaDialog()));
    connect(ui->actionSee_calendars, SIGNAL(triggered()) ,this, SLOT(open_MyCalendarDialog()));
    connect(ui->actionEvent_Manager, SIGNAL(triggered()),this, SLOT(open_EventDialog()));
    connect(ui->actionTutorial, SIGNAL(triggered()), this, SLOT(open_github_in_webbrowser()));
    connect(ui->actionKey_shortcuts, SIGNAL(triggered()), this, SLOT(open_keyshortcutDialog()));
    connect(ui->todo_button, SIGNAL(released()), this, SLOT(open_todolist()));
    datamanager = new DataAggregator;
    try {
        datamanager->load_MyCalendar_from_database();

    } catch (std::invalid_argument& e) {
        QMessageBox::critical(this, "Error", e.what() , QMessageBox::Ok);
        return;
    }
    try {
        datamanager->load_Event_from_database();
    } catch (std::invalid_argument& e) {
        QMessageBox::critical(this, "Error", e.what() , QMessageBox::Ok);
        return;
    }
    try {
        datamanager->load_GroupTask_from_database();
    } catch (std::invalid_argument& e) {
        QMessageBox::critical(this, "Error", e.what() , QMessageBox::Ok);
        return;
    }
    try {
        datamanager->load_Task_from_database();
    } catch (std::invalid_argument& e) {
        QMessageBox::critical(this, "Error", e.what() , QMessageBox::Ok);
        return;
    }
    this->refresh_dynamic_label();
}

MainWindow::~MainWindow()
{
    delete datamanager;
    delete ui;
}

void MainWindow::nextmonth_cal(){
    ui->calendar->showNextMonth();
    //QString name_month = QDate::longMonthName(ui->calendar->monthShown());
    QLocale locale(QLocale::English);
    QString name_month_year = locale.toString(QDate(ui->calendar->yearShown(),ui->calendar->monthShown(),1),"MMMM yyyy");
    //QString name_year = QVariant(ui->calendar->yearShown()).toString();
    ui->month_header_label->setText(name_month_year);
}
void MainWindow::prevmonth_cal(){
    ui->calendar->showPreviousMonth();
    QLocale locale(QLocale::English);
    QString name_month_year = locale.toString(QDate(ui->calendar->yearShown(),ui->calendar->monthShown(),1),"MMMM yyyy");
    ui->month_header_label->setText(name_month_year);
    //ui->year_header_label->setText(name_year);
}
void MainWindow::selected_day_label(){
    QLocale locale(QLocale::English);
    QDate date = ui->calendar->selectedDate();
    ui->day_number_label->setText(QVariant(date.day()).toString());
    QString numberday_week = locale.dayName(date.dayOfWeek());
    ui->day_of_week_label->setText(numberday_week);
    QString m_an_y = locale.toString(QDate(ui->calendar->yearShown(),ui->calendar->monthShown(),1),"MMMM yyyy");
    ui->month_and_year_label->setText(m_an_y);
    QString name_month_year = locale.toString(QDate(ui->calendar->yearShown(),ui->calendar->monthShown(),1),"MMMM yyyy");
    ui->month_header_label->setText(name_month_year);

}
void MainWindow::open_MyCalendarDialog(){
    MyCalendarDialog myCalendarDialog(this->datamanager);
    myCalendarDialog.setModal(true);
    myCalendarDialog.exec();
}
void MainWindow::open_EventDialog(){
    EventDialog eventDialog(this->datamanager);
    eventDialog.setModal(true);
    eventDialog.exec();
    this->refresh_dynamic_label();
}
void MainWindow::refresh_dynamic_label(){
    ui->dynamic_label->clear();
    QPixmap pixmap1(20,10);
    for(auto cal : this->datamanager->get_calendars()){
        QPixmap pixmap(15, 15);
        pixmap1.fill(QColor(255,255,255));
        pixmap.fill(cal.getColor());

        bool naglowek = false;
        for(auto pom : this->datamanager->get_events()){
           if(pom.get_date().date() == ui->calendar->selectedDate() && pom.getcalendar()->getName() == cal.getName()){
                if(naglowek == false)
                     ui->dynamic_label->addItem(new QListWidgetItem(QIcon(pixmap), QString(cal.getName().c_str())));
                naglowek = true;
                pixmap1.fill(pom.getcalendar()->getColor());
                QListWidgetItem* single_event = new QListWidgetItem(QIcon(pixmap1), QString(pom.get_name().c_str()));
                QString message = QString("<p>") + QString(pom.get_description().c_str()) + QString("</p>") +
                        QString("<p>Place: ") + QString(pom.get_place().c_str()) + QString("</p>") +
                        QString("<p>Time: ") + QString(pom.get_date().toString()) + QString("</p");
                single_event->setToolTip(message);
                single_event->setBackground(pom.getcalendar()->getColor());

                ui->dynamic_label->addItem(single_event);
            }
        }
        naglowek = false;

    }
    bool naglowek = false;
    for(auto pom : this->datamanager->get_tasks()){
        if(pom.get_date().day() == ui->calendar->selectedDate().day() &&
                pom.get_date().month() == ui->calendar->selectedDate().month()){
            qDebug() << "XD: " << pom.get_name().c_str();

            if(naglowek==false){
                ui->dynamic_label->addItem(new QListWidgetItem());
                ui->dynamic_label->addItem(new QListWidgetItem(QString("TASKS: ")));
                naglowek = true;
            }
            QListWidgetItem *single_task = new QListWidgetItem(QString(pom.get_name().c_str()));
            ui->dynamic_label->addItem(single_task);
            single_task->setBackground(pom.get_TaskGroup()->get_color());
        }
    }
}
void MainWindow::open_agendaDialog(){
    AgendaDialog agenda(datamanager);
    agenda.setModal(true);
    agenda.exec();
}

void MainWindow::open_github_in_webbrowser(){
    QDesktopServices::openUrl(QUrl("https://github.com/MigotMateusz/Time_organizer"));
}

void MainWindow::open_keyshortcutDialog(){
    KeyShortcutsDialog dialog;
    dialog.setModal(true);
    dialog.exec();
}
void MainWindow::open_todolist(){
    TodolistDialog dialog(this->datamanager);
    dialog.setModal(true);
    dialog.exec();
}
