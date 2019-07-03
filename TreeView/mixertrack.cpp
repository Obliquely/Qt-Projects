#include "mixertrack.h"
#include <QDebug>
#include <QString>
#include <QtCore>
#include "ui_mixercontrol.h"

MixerTrack::MixerTrack()
      {

      }

QString MixerTrack::tooltip()
      {

      QString output = QString("MixerTrack %1. Vol = %2. MuteOn = %3. SoloOn = %4, Child Count = %5").
                  arg(_name).
                  arg(QString::number(_volume)).
                  arg(QString::number(_muteOn)).
                  arg(QString::number(_soloOn)).
                  arg(QString::number(children.count()));

      return output;
      }

void MixerTrack::setName(QString name)
      {
      _name = name;
      treeWidgetItem->setText(0, _name);
      treeWidgetItem->setWhatsThis(0, _name);
      }


void MixerTrack::setDescription(QString description)
      {
      _description = description;
      treeWidgetItem->setText(2, description);
      treeWidgetItem->setWhatsThis(0, description);
      }


void MixerTrack::setVolume(int volume)
      {
      _volume = volume;
      mixerControl->setVolume(volume);
      }

int MixerTrack::getVolume()
      {
      return _volume;
      }

void MixerTrack::setMuteOn(bool muteOn)
      {
      _muteOn = muteOn;
      mixerControl->ui->muteButton->setChecked(muteOn);
      }

bool MixerTrack::muteOn()
      {
      return _muteOn;
      }

void MixerTrack::setSoloOn(bool soloOn)
      {
      _soloOn = soloOn;
      mixerControl->ui->soloButton->setChecked(soloOn);
      }

bool MixerTrack::soloOn()
      {
      return _soloOn;
      }
