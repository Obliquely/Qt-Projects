

#include "mixeroptionsbutton.h"
#include <QDebug>

MixerOptionsButton::MixerOptionsButton(QWidget* parent) : QToolButton (parent)
      {
      overrideOn = new QAction(tr("Alt Slider"));
      overrideOn->setCheckable(true);

      this->addAction(overrideOn);

      overrideMenu = new QMenu(this);

      panSlider = new QAction(tr("Pan"));
      reverbSlider = new QAction(tr("Reverb"));
      chorusSlider = new QAction(tr("Chorus"));

      panSlider->setCheckable(true);
      reverbSlider->setCheckable(true);
      chorusSlider->setCheckable(true);

      altSliderGroup = new QActionGroup(this);
      altSliderGroup->addAction(panSlider);
      altSliderGroup->addAction(reverbSlider);
      altSliderGroup->addAction(chorusSlider);

      overrideMenu->addAction(overrideOn);
      overrideMenu->addSeparator();

      overrideMenu->addActions({panSlider, reverbSlider, chorusSlider});


      setMenu(overrideMenu);
      setChecked(false);
      setCheckable(true);

      setText("Override: none");

      connect(this, SIGNAL(toggled(bool)), this, SLOT(overrideChecked(bool)));
      connect(panSlider, SIGNAL(triggered(bool)), this, SLOT(panSliderOption(bool)));
      connect(reverbSlider, SIGNAL(triggered(bool)), this, SLOT(reverbSliderOption(bool)));
      connect(chorusSlider, SIGNAL(triggered(bool)), this, SLOT(chorusSliderOption(bool)));

      }

void MixerOptionsButton::overrideChecked(bool state)
      {
      qDebug()<<"Override button is: "<<this->isChecked();
      overrideOn->setChecked(state);
      }

void MixerOptionsButton::panSliderOption(bool state)
      {
      qDebug()<<"panSliderOption button is: "<<this->isChecked();

      if (state == true) {
            setText(tr("Pan"));
            }



      }

void MixerOptionsButton::reverbSliderOption(bool state)
      {
      qDebug()<<"reverbSliderOption button is: "<<this->isChecked();

      if (state == true) {
            setText(tr("Reverb"));
            }
      }

void MixerOptionsButton::chorusSliderOption(bool state)
      {
      qDebug()<<"reverbSliderOption button is: "<<this->isChecked();

      if (state == true) {
            setText(tr("Chorus"));
            }
      }



