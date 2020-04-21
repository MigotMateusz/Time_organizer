#include "keyshortcutsdialog.h"
#include "ui_keyshortcutsdialog.h"

KeyShortcutsDialog::KeyShortcutsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KeyShortcutsDialog)
{
    ui->setupUi(this);
}

KeyShortcutsDialog::~KeyShortcutsDialog()
{
    delete ui;
}
