#include "mixertreewidget.h"
#include "mixertrack.h"
#include <QDebug>
#include <QHeaderView>
#include "noneditableitemdelegate.h"

MixerTreeWidget::MixerTreeWidget(QWidget *parent) :
      QTreeWidget(parent)
      {
      qDebug()<<"Creating mixer tree widget";

      setupAdditionalUi();

      connect(this, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(itemChanged(QTreeWidgetItem*, int)));
      connect(header(), SIGNAL(geometriesChanged()), this, SLOT(adjustHeaderWidths()));

//           viewport()->setAcceptDrops(true);
//           setDragEnabled(true);
//           setDropIndicatorShown(true);
//           setDragDropMode(QAbstractItemView::InternalMove);
      }


void MixerTreeWidget::setupAdditionalUi()
      {
      //setSelectionMode(QAbstractItemView::SingleSelection);
      setSelectionBehavior(QAbstractItemView::SelectRows);

      setColumnCount(2);
      header()->setSectionResizeMode(0, QHeaderView::Fixed);
      header()->setSectionResizeMode(1, QHeaderView::Fixed);

      columnToggled();
      }


void MixerTreeWidget::setTrackList(TrackList *trackList)
      {

      this->trackList = trackList;

      for (MixerTrack* mixerTrack : trackList->tracks()) {

            QTreeWidgetItem* item = mixerTrack->treeWidgetItem;

            Qt::ItemFlags itemFlags = QFlag(Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
            item->setFlags(itemFlags);
            setItemDelegateForColumn(1, new NonEditableItemDelegate (this)); // make this one non-editable

            addTopLevelItem(item);

            setItemWidget(mixerTrack->treeWidgetItem, 1, mixerTrack->mixerControl);

            if (mixerTrack->children.count() == 0)
                  continue;

            QList<MixerTrack*> children = mixerTrack->children;

            for (int index = 0; index < children.count(); index++) {
                  MixerTrack* subTrack = mixerTrack->children[index];
                  mixerTrack->treeWidgetItem->addChild(subTrack->treeWidgetItem);
                  setItemWidget(subTrack->treeWidgetItem, 1, subTrack->mixerControl);
                  }
            }
      }




void MixerTreeWidget::columnToggled()
      {

      int columnCount = this->columnCount();

      if (columnCount == 2) {

            setColumnCount(3);
            headerItem()->setText(0, "Name");
            headerItem()->setText(1, "Adjustments");
            headerItem()->setText(2, "Bonus");
            }
      else {
            setColumnCount(2);
            headerItem()->setText(0, "MTW Title");
            headerItem()->setText(1, "Volume");
            }

      adjustHeaderWidths();

      }

void MixerTreeWidget::itemChanged(QTreeWidgetItem* item, int column)
      {
      qDebug()<<"an item has changed. New text is: "<<item->text(column);

      // update the model
      // FIND the mixerTrack associated with the model
      // current design is BAD - ought to be able to pull it off the item by sublcassing
      // QTreeWidgetItem

      int index = indexOfTopLevelItem(item); // this is a bit of hack!

      QList<MixerTrack*> tracks = trackList->tracks();

      if (column == 0) {
            tracks[index]->setName(item->text(column));
            }
      else if (column == 2) {
            tracks[index]->setDescription(item->text(column));
            }

      // save it to disk
      trackList->saveData();

      }

void MixerTreeWidget::adjustHeaderWidths()
      {

      if (columnCount() == 2) {

            int width = this->width();

            double ratio = 0.4;
            int margin = 1;

            int column0 = int(double(width) * ratio) - margin;
            int column1 = int(double(width) * (1-ratio) -margin);

            if (column0 > 300) {
                  column0 = 300;
                  column1 = width - 300 - margin;
                  }

            if (column1 < 250) {
                  column1 = 250;
                  }

            header()->resizeSection(0, column0);
            header()->resizeSection(1, column1);
            }

      else if (columnCount() == 3) {

            int width = this->width();

            double ratio = 0.4;

            int margin = 5;

            int column0 = int(double(width) * ratio);
            int column1 = int(double(width) * ( (1-ratio) /2 ));
            int column2 = int(double(width) * ( (1-ratio) /2 ));

            if (column0 > 300) {
                  column0 = 300;
                  column1 = (width - 300) /2;
                  column2 = (width - 300) /2;
                  }


            if (column1 < 250) {
                  column1 = 250;
                  }

            header()->resizeSection(0, column0 - margin);
            header()->resizeSection(1, column1 - margin);
            header()->resizeSection(2, column2 - margin);
            }


      }


