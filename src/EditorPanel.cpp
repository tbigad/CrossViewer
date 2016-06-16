#include "EditorPanel.h"

EditorPanel::EditorPanel(QPixmap pix, QWidget *parent) :
    QDialog(parent,Qt::CustomizeWindowHint),
    ui(new Ui::EditorPanelUI)
{
    ui->setupUi(this);
    setFixedSize(size());
    currentPix = pix;
    setWindowModality(Qt::ApplicationModal);
    QObject::connect(ui->btn_OK, SIGNAL(clicked()), this, SLOT(edit()));
    QObject::connect(ui->pushCancel, SIGNAL(clicked()), this, SLOT(reject()));
    ui->spinBoxHeight->setValue(currentPix.height());
    ui->spinBoxWigth->setValue(currentPix.width());
}

EditorPanel::~EditorPanel()
{
    delete ui;
}

void EditorPanel::on_pushCancel_pressed()
{
    close();
}

void EditorPanel::edit()
{
    emit toSave(currentPix.scaled(ui->spinBoxWigth->value(),ui->spinBoxHeight->value()),
                ui->spinBoxPesent->value());
    accept();
}
