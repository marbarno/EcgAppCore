#include "ecgbaseline_gui.h"
#include "ui_ecgbaseline_gui.h"

ECGbaseline_gui::ECGbaseline_gui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ECGbaseline_gui)
{
    ui->setupUi(this);
}

ECGbaseline_gui::~ECGbaseline_gui()
{
    delete ui;
}


void ECGbaseline_gui::on_comboBox_filter_currentTextChanged(const QString &arg1)
{
    QString filter = ui->comboBox_filter->currentText();
    if(filter=="lowpass_filter"){
      ui->spinBox_lowFreq->setDisabled(true);
      ui->spinBox_highFreq->setDisabled(false);
      ui->spinBox_filOrder->setDisabled(true);
      ui->spinBox_filLength->setDisabled(true);
      ui->spinBox_stepSize->setDisabled(true);
      ui->plainTextEdit->setPlainText("aloha");
    } else if (filter=="bandpass_filter") {
        ui->spinBox_lowFreq->setDisabled(false);
        ui->spinBox_highFreq->setDisabled(false);
        ui->spinBox_filOrder->setDisabled(true);
        ui->spinBox_filLength->setDisabled(true);
        ui->spinBox_stepSize->setDisabled(true);
        ui->plainTextEdit->setPlainText("we did it1");
    } else if (filter=="Butterworth_filter") {
        ui->spinBox_lowFreq->setDisabled(false);
        ui->spinBox_highFreq->setDisabled(true);
        ui->spinBox_filOrder->setDisabled(false);
        ui->spinBox_filLength->setDisabled(true);
        ui->spinBox_stepSize->setDisabled(true);
        ui->plainTextEdit->setPlainText("we did it2");
    } else if (filter=="Chebyshev_filter") {
        ui->spinBox_lowFreq->setDisabled(false);
        ui->spinBox_highFreq->setDisabled(false);
        ui->spinBox_filOrder->setDisabled(true);
        ui->spinBox_filLength->setDisabled(true);
        ui->spinBox_stepSize->setDisabled(true);
        ui->plainTextEdit->setPlainText("we did it3");
    } else if (filter=="Savitzky’_Golay_filter") {
        ui->spinBox_lowFreq->setDisabled(true);
        ui->spinBox_highFreq->setDisabled(true);
        ui->spinBox_filOrder->setDisabled(false);
        ui->spinBox_filLength->setDisabled(false);
        ui->spinBox_stepSize->setDisabled(true);
        ui->plainTextEdit->setPlainText("we did it4");
    } else if (filter=="Keiser_filter") {
        ui->spinBox_lowFreq->setDisabled(false);
        ui->spinBox_highFreq->setDisabled(false);
        ui->spinBox_filOrder->setDisabled(true);
        ui->spinBox_filLength->setDisabled(true);
        ui->spinBox_stepSize->setDisabled(true);
        ui->plainTextEdit->setPlainText("we did it5");
    } else if (filter=="LSM_algoritm") {
        ui->spinBox_lowFreq->setDisabled(true);
        ui->spinBox_highFreq->setDisabled(true);
        ui->spinBox_filOrder->setDisabled(true);
        ui->spinBox_filLength->setDisabled(false);
        ui->spinBox_stepSize->setDisabled(true);
        ui->plainTextEdit->setPlainText("we did it6");
    }else if (filter=="Moving_average"){
        ui->spinBox_lowFreq->setDisabled(true);
        ui->spinBox_highFreq->setDisabled(true);
        ui->spinBox_filOrder->setDisabled(true);
        ui->spinBox_filLength->setDisabled(false);
        ui->spinBox_stepSize->setDisabled(false);
        ui->plainTextEdit->setPlainText("ooop");
    }
}
