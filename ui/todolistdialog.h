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

private:
    Ui::TodolistDialog *ui;

public:
    DataAggregator *datamanager;
    explicit TodolistDialog(DataAggregator* dmanager, QWidget *parent = nullptr);
    ~TodolistDialog();
    void refresh_left_side();
public slots:
    void open_TaskGroup_dialog();
    void open_EditTaskGroup_dialog();
    void edit_selected_task();
    void delete_selected_task();
    void add_task();
    void inbox_view();
    void today_view();
    void sevendays_view();
    void taskgroup_view(Task_Group group);
};

#endif // TODOLISTDIALOG_H
