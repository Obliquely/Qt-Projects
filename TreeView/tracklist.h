#ifndef TRACKLIST_H
#define TRACKLIST_H

#include <QObject>
#include "mixertrack.h"

class TrackList : public QObject
      {
      Q_OBJECT
      QList<MixerTrack*> _tracks;
      void dataFromString(QString source);
      QString stringFromNode(MixerTrack* mixerTrack, QString indent);
public:
      explicit TrackList(QObject *parent = nullptr);
      QList<MixerTrack*> tracks() { return _tracks; }
      void importTestData();
      void resetTree();
      void saveData();
      void recoverData();
      QString stringFromData();

signals:

public slots:
      };

#endif // TRACKLIST_H
