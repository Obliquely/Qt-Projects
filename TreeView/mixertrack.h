#ifndef MIXERTRACK_H
#define MIXERTRACK_H

#include <QTreeWidgetItem>
#include "mixercontrol.h"

class MixerTrack
      {
public:
      MixerTrack();

      QTreeWidgetItem* treeWidgetItem = new QTreeWidgetItem();
      MixerControl* mixerControl = new MixerControl();

      QList<MixerTrack*> children;

      QString extraText();
      void setExtraText(QString);

      void setName(QString name);
      void setDescription(QString descriptions);
      QString name() {return _name; }
      QString description() { return _description; }
      QString tooltip();
      void setVolume(int);
      int getVolume();
      int getPan();

      void setMuteOn(bool);
      bool muteOn();

      void setSoloOn(bool);
      bool soloOn();

private:
      QString _name;
      QString _description;
      bool _muteOn = false;
      bool _soloOn = false;
      int _volume = 50;
      int _pan = 50;

      };

#endif // MIXERTRACK_H
