#include "mycalendaradddialog.h"
#include "ui_mycalendaradddialog.h"
#include <QColor>
#include <QMessageBox>

MyCalendarAddDialog::MyCalendarAddDialog(MyCalendarDialog *dialog, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyCalendarAddDialog)
{
    ui->setupUi(this);
    this->calendardialog = dialog;
    QPixmap pixmap(20, 20);
    pixmap.fill(QColor(0, 0, 0));
    ui->button_color->setIcon(QIcon(pixmap));
    connect(ui->button_color, SIGNAL(released()), this, SLOT(on_button_color_click()));
    connect(ui->cancel_button, SIGNAL(released()), this, SLOT(on_button_cancel_click()));
    connect(ui->save_button, SIGNAL(released()), this, SLOT(on_button_save_click()));
}

MyCalendarAddDialog::~MyCalendarAddDialog(){
    delete ui;
}

void MyCalendarAddDialog::on_button_color_click(){
    QColor color = QColorDialog::getColor(QColor(0,0,0));
    QPixmap pixmap(20, 20);
    this->selected_color = color;
    pixmap.fill(color);
    ui->button_color->setIcon(QIcon(pixmap));
}

void MyCalendarAddDialog::on_button_cancel_click(){
    this->accept();
}

void MyCalendarAddDialog::on_button_save_click(){
    if(ui->lineEdit->text().length() < 4)
    {
        QMessageBox::critical(this, "Error", "The name must have a length greater than 3", QMessageBox::Ok);
        return;
    }
    MyCalendar newcalendar(ui->lineEdit->text().toStdString(), this->selected_color);
    calendardialog->calendars.push_back(newcalendar);
    this->calendardialog->loadMyCalendars();
    this->close();
}

