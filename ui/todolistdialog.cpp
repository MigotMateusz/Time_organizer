#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QBrush>
#include "todolistdialog.h"
#include "ui_todolistdialog.h"

TodolistDialog::TodolistDialog(DataAggregator *dmanager, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TodolistDialog)
{
    ui->setupUi(this);
    this->datamanager = dmanager;
    this->refresh();
    QVBoxLayout *layoutleft1 = new QVBoxLayout(ui->frameleft);
    QString tab[] = {"📮 Inbox", "📆 Today", "📅 Next 7 days"};

    for(auto p : tab){
       QHBoxLayout *layout = new QHBoxLayout();
       layoutleft1->addLayout(layout);
       QLabel *label = new QLabel();
       label->setText(p);
       label->setFont(QFont(this->font().family(), 14));
       label->setContentsMargins(10,0,0,0);
       layout->addWidget(label);
    }
    QVBoxLayout *layoutleft2 = new QVBoxLayout(ui->frameleft2);
    QHBoxLayout *layout = new QHBoxLayout();
    layoutleft2->addLayout(layout);
    QLabel *label = new QLabel();
    label->setText("Task Groups");
    label->setFont(QFont(this->font().family(), 14));
    layout->addWidget(label);
    int h = 100;
    QPixmap pixmap(10,10);
    for(auto p : this->datamanager->get_TaskGroup()){
        ui->frameleft2->resize(300, h);
        h+=30;
        QHBoxLayout *layout = new QHBoxLayout();
        layout->setAlignment(Qt::AlignLeft);
        layoutleft2->addLayout(layout);
        QLabel *label = new QLabel();
        label->setText(p.get_name().c_str());
        label->setFont(QFont(this->font().family(), 12));
        pixmap.fill(p.get_color());
        QLabel *pixlabel = new QLabel();
        pixlabel->setPixmap(pixmap);
        pixlabel->setContentsMargins(30,0,0,0);
        layout->addWidget(pixlabel);
        layout->addWidget(label);
    }
    QHBoxLayout *layout1 = new QHBoxLayout();
    ui->frameleft2->resize(300, h + 30);
    layoutleft2->addLayout(layout1);
    QLabel *label1 = new QLabel();
    label1->setText("➕ Add Task Group");
    label1->setFont(QFont(this->font().family(), 14));
    layout1->addWidget(label1);
}

TodolistDialog::~TodolistDialog()
{
    delete datamanager;
    delete ui;
}
void TodolistDialog::refresh(){
    /*ui->listWidget->clear();
    for(auto pom : this->datamanager->get_tasks()){
        ui->listWidget->addItem(new QListWidgetItem(QString(pom.get_name().c_str())));
    }*/

}
