#include "mixercontrol.h"
#include "ui_mixercontrol.h"

MixerControl::MixerControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MixerControl)
{
    ui->setupUi(this);
}

MixerControl::~MixerControl()
{
    delete ui;
}
