#include "mixercontrol.h"
#include "ui_mixercontrol.h"

MixerControl::MixerControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MixerControl)
{
    ui->setupUi(this);
    ui->muteButton->setStyleSheet("QToolButton{background: white; color: black; font-weight: bold; border: 1px solid gray;} QToolButton:checked, QToolButton:pressed { color: white; background: red;}");
    ui->soloButton->setStyleSheet("QToolButton{background: white; color: black; font-weight: bold; border: 1px solid gray;} QToolButton:checked, QToolButton:pressed { color: white; background: green; }");
}

MixerControl::~MixerControl()
{
    delete ui;
}

void MixerControl::setVolume(int volume)
    {
    ui->volumeSlider->setValue(volume);
    }

int MixerControl::getVolume()
{
    return ui->volumeSlider->value();
}
