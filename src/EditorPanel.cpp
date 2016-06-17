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
    pixSize = pix.size();
    connect(ui->spinBoxHeight,static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), [=](int h){
        if(ui->btn_lock->isChecked()){
            ui->spinBoxWigth->blockSignals(true);
            QSize newSize(ui->spinBoxHeight->value(),h);
            QSize diffSize = (QSize(pixSize.width(),h) - pixSize);
            pixSize.scale(newSize, diffSize.isValid() ? Qt::KeepAspectRatioByExpanding : Qt::KeepAspectRatio);
            ui->spinBoxWigth->setValue(pixSize.width());
            ui->spinBoxWigth->blockSignals(false);
        }
    });
    connect(ui->spinBoxWigth,static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), [=](int w){
        if(ui->btn_lock->isChecked()){
            ui->spinBoxHeight->blockSignals(true);
            QSize newSize(w,ui->spinBoxHeight->value());
            QSize diffSize = (QSize(w,pixSize.height()) - pixSize);
            pixSize.scale(newSize, diffSize.isValid() ? Qt::KeepAspectRatioByExpanding : Qt::KeepAspectRatio);
            ui->spinBoxHeight->setValue(pixSize.height());
            ui->spinBoxWigth->blockSignals(false);
        }
    });
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
