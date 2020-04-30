#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QBrush>
#include <QMessageBox>
#include <QDebug>
#include "todolistdialog.h"
#include "taskgroupdialog.h"
#include "taskmanager.h"
#include "edittaskgroupdialog.h"
#include "ui_todolistdialog.h"

TodolistDialog::TodolistDialog(DataAggregator *dmanager, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TodolistDialog)
{
    ui->setupUi(this);
    this->datamanager = dmanager;
    this->refresh_left_side();
    inbox_view();
    connect(ui->delete_2, SIGNAL(released()), this, SLOT(delete_selected_task()));
    connect(ui->edit, SIGNAL(released()), this, SLOT(edit_selected_task()));
    connect(ui->add, SIGNAL(released()), this, SLOT(add_task()));
}

TodolistDialog::~TodolistDialog()
{
    delete ui;
}
void TodolistDialog::refresh_left_side(){
    QVBoxLayout *layoutleft1 = new QVBoxLayout(ui->frameleft);
    QString tab[] = {"📮 Inbox", "📆 Today", "📅 Next 7 days"};
    int index = 1;
    for(auto p : tab){
       QHBoxLayout *layout = new QHBoxLayout();
       layoutleft1->addLayout(layout);
       //QLabel *label = new QLabel();
       QPushButton *button = new QPushButton();
       button->setText(p);
       button->setFont(QFont(this->font().family(), 14));
       button->setContentsMargins(10,0,0,0);
       button->setFlat(true);
       layout->addWidget(button);
       if(index == 1)
           connect(button, SIGNAL(released()), this, SLOT(inbox_view()));
       else if(index == 2)
           connect(button, SIGNAL(released()), this, SLOT(today_view()));
       else
           connect(button, SIGNAL(released()), this, SLOT(sevendays_view()));
       index++;
    }
    QVBoxLayout *layoutleft2 = new QVBoxLayout(ui->frameleft2);
    QHBoxLayout *layout = new QHBoxLayout();
    layoutleft2->addLayout(layout);
    QLabel *label = new QLabel();
    label->setText("Task Groups");
    label->setAlignment(Qt::AlignCenter);
    label->setFont(QFont(this->font().family(), 14));
    layout->addWidget(label);
    int h = 100;
    QPixmap pixmap(10,10);
    for(auto p : this->datamanager->get_TaskGroup()){
        qDebug() << p.get_name().c_str();
        ui->frameleft2->resize(300, h);
        h += 30;
        QHBoxLayout *layout = new QHBoxLayout();
        layout->setAlignment(Qt::AlignLeft);
        layoutleft2->addLayout(layout);
        QPushButton *button = new QPushButton();
        button->setText(p.get_name().c_str());
        button->setFont(QFont(this->font().family(), 12));
        button->setFlat(true);

        pixmap.fill(p.get_color());
        QLabel *pixlabel = new QLabel();
        pixlabel->setPixmap(pixmap);
        pixlabel->setContentsMargins(50,0,0,0);
        layout->addWidget(pixlabel);
        layout->addWidget(button);
        connect(button, SIGNAL(released()), this, SLOT(taskgroup_view()));
    }
    QHBoxLayout *layout1 = new QHBoxLayout();
    ui->frameleft2->resize(300, h + 40);
    layoutleft2->addLayout(layout1);
    QPushButton *label1 = new QPushButton();
    label1->setText("➕Open TaskGroup Dialog");
    label1->setFont(QFont(this->font().family(), 14));
    label1->setMinimumHeight(40);
    label1->setFlat(true);
    connect(label1, SIGNAL(released()), this, SLOT(open_TaskGroup_dialog()));
    layout1->addWidget(label1);

    QPushButton *editbutton = new QPushButton();
    editbutton->setFlat(true);
    editbutton->setMinimumHeight(40);
    editbutton->setText("Edit/Delete TaskGroup");
    editbutton->setFont(QFont(this->font().family(), 14));
    ui->frameleft2->resize(300, h + 80);

    QHBoxLayout *layoutbuttonedit = new QHBoxLayout();
    layoutleft2->addLayout(layoutbuttonedit);
    layoutbuttonedit->addWidget(editbutton);
    connect(editbutton, SIGNAL(released()), this, SLOT(open_EditTaskGroup_dialog()));
    ui->listWidget->clear();
    for(auto i : this->datamanager->get_tasks()){
       this->ui->listWidget->addItem(new QListWidgetItem(QString(i.get_name().c_str())));
    }
}
void TodolistDialog::open_TaskGroup_dialog(){
    TaskGroupDialog dialog(this);
    dialog.setModal(true);
    dialog.exec();
}

void TodolistDialog::open_EditTaskGroup_dialog(){
    EditTaskGroupDialog dialog(this);
    dialog.setModal(true);
    dialog.exec();
}

void TodolistDialog::edit_selected_task(){
    if(this->ui->listWidget->selectedItems().size() == 0){
        QMessageBox::critical(this, "Error", "No Task selected!", QMessageBox::Ok);
        return;
    }
    QString selected_category = this->ui->listWidget->selectedItems().at(0)->text();
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm", QString("Do you want to edit ") + selected_category + QString("?"),
                                  QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        TaskManager dialog(this, true,this->ui->listWidget->selectedItems().at(0)->text());
        dialog.setModal(true);
        dialog.exec();

    }
}
void TodolistDialog::delete_selected_task(){
        if(this->ui->listWidget->selectedItems().size() == 0){
            QMessageBox::critical(this, "Error", "No Task selected!", QMessageBox::Ok);
            return;
        }
        QString selected_category = this->ui->listWidget->selectedItems().at(0)->text();
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirm", QString("Do you want to delete ") + selected_category + QString("?"),
                                      QMessageBox::Yes|QMessageBox::No);
        if(reply == QMessageBox::Yes){
            this->datamanager->erase_an_element_from_tasks(selected_category);
            this->datamanager->load_Task_to_database();
            //this->refresh_left_side();
            ui->listWidget->clear();
            for(auto i : this->datamanager->get_tasks()){
               this->ui->listWidget->addItem(new QListWidgetItem(QString(i.get_name().c_str())));
            }
        }

}

void TodolistDialog::add_task(){
    TaskManager dialog(this, false);
    dialog.setModal(true);
    dialog.exec();
}
void TodolistDialog::inbox_view(){
    ui->listWidget->clear();
    QString string;
    for(auto i : this->datamanager->get_tasks()){
        QListWidgetItem* single_task = new QListWidgetItem(QString(i.get_name().c_str()));
        single_task->setBackground(i.get_TaskGroup()->get_color());
        this->ui->listWidget->addItem(single_task);
    }
    ui->label->setText("Inbox");
}
void TodolistDialog::today_view(){
    ui->listWidget->clear();
    for(auto i : this->datamanager->get_tasks()){
        if(i.get_date() == QDate::currentDate()){
            QListWidgetItem* single_task = new QListWidgetItem(QString(i.get_name().c_str()));
            single_task->setBackground(i.get_TaskGroup()->get_color());
            this->ui->listWidget->addItem(single_task);
    }
    }
    ui->label->setText("Today");
}
void TodolistDialog::sevendays_view(){
    ui->listWidget->clear();
    ui->label->setText("Next 7 Days");
    for(auto i : this->datamanager->get_tasks()){
        if((i.get_date().day() >= QDate::currentDate().day() && i.get_date().day() <= QDate::currentDate().day() + 7) &&
                i.get_date().month() == QDate::currentDate().month()){
            QListWidgetItem* single_task = new QListWidgetItem(QString(i.get_name().c_str()));
            single_task->setBackground(i.get_TaskGroup()->get_color());
            this->ui->listWidget->addItem(single_task);
    }
    }
}
void TodolistDialog::taskgroup_view(Task_Group group){
    ui->listWidget->clear();
    //ui->label->setText(QString::fromStdString(group.get_name()));
}
