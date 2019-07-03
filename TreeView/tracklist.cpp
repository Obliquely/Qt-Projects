#include "tracklist.h"
#include <QFile>
#include <QDebug>
#include <QStandardPaths>

TrackList::TrackList(QObject *parent) : QObject(parent)
      {

      }


void TrackList::saveData()
      {
      QString path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);

      QFile file(path.append("/userTree.txt"));
      if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug()<<"could not open file "<<file.fileName();
            return;
            }

      QString test = stringFromData();

      file.write(test.toUtf8());
      // QTextStream out(&file);
      //out << test;

      file.close();

      qDebug()<<"saved data: "<<test;
      }

void TrackList::recoverData()
      {
      QString path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);

      QFile file(path.append("/userTree.txt"));
      if (!file.exists()) {
            qDebug()<<"Desktop file not found. Using defaults.";
            importTestData();
            saveData();
            return;
            }

      if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug()<<"Desktop file exists but cannot be opened.";
            importTestData();
            saveData();
            return;
            }

      QString recovered = file.readAll();
      file.close();
      qDebug()<<"recoverData has read: "<<recovered;

      dataFromString(recovered);

      }


void TrackList::importTestData()
      {
      _tracks.clear();

      QFile file(":/default.txt");
      file.open(QIODevice::ReadOnly);
      QString source = file.readAll();
      file.close();

      dataFromString(source);

      for (MixerTrack* mixerTrack : _tracks) {
            qDebug()<<mixerTrack->name();
            }
      }



QString TrackList::stringFromNode(MixerTrack* node, QString indent) {

      return QString("%1%2; %3; %4; %5; %6\n")
                  .arg(indent)
                  .arg(node->name())
                  .arg(QString::number(node->getVolume()))
                  .arg(node->muteOn() ? "MuteOn" : "MuteOff")
                  .arg(node->soloOn() ? "SoloOn" : "SoloOff")
                  .arg(node->description());
      }

QString TrackList::stringFromData()
      {

      QString output = "";

      for (MixerTrack* node : _tracks) {

            output.append(stringFromNode(node, ""));

            for (MixerTrack* childNode : node->children) {
                  output.append(stringFromNode(childNode, "    "));

                  }
            }

      return output;

      }

void TrackList::dataFromString(const QString source)
      {
      QList<int> indentations;

      QStringList lines = source.split(QString("\n"));

      MixerTrack* currentItem = nullptr;

      int number = 0;

      while (number < lines.count()) {
            int position = 0;
            while (position < lines[number].length()) {
                  if (lines[number].at(position) != ' ')
                        break;
                  position++;
                  }

            QString lineData = lines[number].mid(position).trimmed();

            if (!lineData.isEmpty()) {
                  // Read the column data from the rest of the line.
                  QStringList columnStrings = lineData.split(";", QString::SkipEmptyParts);
                  qDebug()<<columnStrings;
                  QList<QVariant> columnData;
                  for (int column = 0; column < columnStrings.count(); ++column)
                        columnData << columnStrings[column];

                  QString name = columnStrings[0];
                  QString controlPlaceholder = "";
                  MixerTrack * node = new MixerTrack();
                  node->setName(name.trimmed());

                  if (columnStrings.count() >= 2) {
                        int volume = int(columnStrings[1].trimmed().toFloat());
                        qDebug()<<"Volume for '"<<name<<"' is: "<<volume;
                        node->setVolume(volume);
                        }

                  if (columnStrings.count() >= 3) {
                        bool muteOn = columnStrings[2].trimmed() == "MuteOn";
                        qDebug()<<"muteOn for '"<<name<<"' is: "<<muteOn;
                        node->setMuteOn(muteOn);
                        }

                  if (columnStrings.count() >= 4) {
                        bool soloOn = columnStrings[3].trimmed() == "SoloOn";
                        qDebug()<<"soloOn for '"<<name<<"' is: "<<soloOn;
                        node->setSoloOn(soloOn);
                        }

                  if (columnStrings.count() >= 5) {
                        QString description = columnStrings[4].trimmed();
                        qDebug()<<"description for '"<<name<<"' is: "<<description;
                        node->setDescription(description);
                        }


                  if (position >= 4) {
                        // indented, so treat as child
                        if (currentItem)
                              currentItem->children.append(node);

                        }
                  else {
                        // we're at the same level
                        currentItem = node;
                        _tracks.append(node);
                        }
                  }
            ++number;
            }
      }

void TrackList::resetTree()
      {
      for (MixerTrack* mixerTrack : _tracks) {

            mixerTrack->setVolume(25);
            mixerTrack->setMuteOn(false);
            mixerTrack->setSoloOn(false);

            if (mixerTrack->children.count() == 0)
                  continue;

            QList<MixerTrack*> children = mixerTrack->children;

            for (int index = 0; index < children.count(); index++) {
                  MixerTrack* subTrack = mixerTrack->children[index];
                  subTrack->setVolume(25);
                  subTrack->setMuteOn(false);
                  subTrack->setSoloOn(false);
                  }
            }
      }


