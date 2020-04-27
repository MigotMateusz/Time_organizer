#ifndef TODOLISTDIALOG_H
#define TODOLISTDIALOG_H

#include <QDialog>
#include "../utilities/dataaggregator.h"

namespace Ui {
class TodolistDialog;
}

class TodolistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TodolistDialog(DataAggregator* dmanager, QWidget *parent = nullptr);
    ~TodolistDialog();
    void refresh();
private:
    Ui::TodolistDialog *ui;
    DataAggregator *datamanager;
};

#endif // TODOLISTDIALOG_H
