#include <QHBoxLayout>
#include <QLabel>
#include <QRectF>
#include <QAction>
#include <QPalette>
#include <QTableView>
#include <QHBoxLayout>
#include "agendadialog.h"
#include "ui_agendadialog.h"

AgendaDialog::AgendaDialog(DataAggregator *dman, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AgendaDialog)
{
    ui->setupUi(this);
    this->datamanager = dman;
    int w=600, h=0;
    QPixmap pixmap(10,10);
    QVBoxLayout *mainlayout = new QVBoxLayout(this);
    for(auto i : this->datamanager->get_events()){
        if(QDate::currentDate().month() == i.get_date().date().month() &&
                QDate::currentDate().day() <= i.get_date().date().day()){
            //pixmap.fill(i.getcalendar()->getColor());
            QPalette pal;

            pal.setColor(QPalette::Background,i.getcalendar()->getColor());
            this->resize(w,h);
            QHBoxLayout *layout = new QHBoxLayout();
            mainlayout->addLayout(layout);
            QLabel *label = new QLabel();
            QLabel *event = new QLabel();
            event->setText(i.get_name().c_str());
            event->setPalette(pal);
            event->setFont(QFont(this->font().family(), 14));
            event->setAutoFillBackground(true);
            event->setContentsMargins(10,0,0,0);
            label->setText(i.get_date().toString());
            label->setFont(QFont(this->font().family(), 14));
           /* label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
            label->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
            label->setGeometry(QRect(0,h/2,600,40));
            */
            layout->addWidget(label);
            layout->addWidget(event);
            h += 50;

        }
    }
}

AgendaDialog::~AgendaDialog()
{
    delete ui;
}
