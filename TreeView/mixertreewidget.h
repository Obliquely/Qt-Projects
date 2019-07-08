#ifndef MIXERTREEWIDGET
#define MIXERTREEWIDGET

#include <QTreeWidget>
#include <tracklist.h>


class MixerTreeWidget : public QTreeWidget
      {
      Q_OBJECT

      TrackList* trackList;


private slots:
      void adjustHeaderWidths();
      void itemChanged(QTreeWidgetItem*, int);
      void columnToggled();


public:
      explicit MixerTreeWidget(QWidget *parent = nullptr);


      void setTrackList(TrackList* trackList);
      void setupAdditionalUi();

      };

#endif // MIXERTREEWIDGET__
