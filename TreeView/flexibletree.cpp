#include "flexibletree.h"
#include <QDebug>

// based on:https://stackoverflow.com/questions/21283934/qtreewidget-reordering-child-items-by-dragging



FlexibleTree::FlexibleTree()
      {

      resize(200, 300);

      setSelectionMode(QAbstractItemView::SingleSelection);
      setDragEnabled(true);
      viewport()->setAcceptDrops(true);
      setDropIndicatorShown(true);
      setDragDropMode(QAbstractItemView::InternalMove);

      QTreeWidgetItem* parentItemOne = new QTreeWidgetItem(this);
      parentItemOne->setText(0, "Test One");
      parentItemOne->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDropEnabled | Qt::ItemIsDragEnabled | Qt::ItemIsEditable);

      for(int i = 0; i < 4; ++i)
            {
            QTreeWidgetItem* pItem = new QTreeWidgetItem(parentItemOne);
            pItem->setText(0, QString("Number %1").arg(i) );
            pItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDragEnabled);
            pItem->addChild(pItem);
            }

      QTreeWidgetItem* parentItemTwo = new QTreeWidgetItem(this);
      parentItemTwo->setText(0, "Test Two");
      parentItemTwo->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDropEnabled | Qt::ItemIsDragEnabled);

      for(int i = 0; i < 4; ++i)
            {
            QTreeWidgetItem* pItem = new QTreeWidgetItem(parentItemTwo);
            pItem->setText(0, QString("Number %1").arg(i) );
            pItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDragEnabled);
            pItem->addChild(pItem);
            }

      QTreeWidgetItem* parentItemThree = new QTreeWidgetItem(this);
      parentItemThree->setText(0, "Test Three");
      parentItemThree->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDropEnabled | Qt::ItemIsDragEnabled);

      for(int i = 0; i < 4; ++i)
            {
            QTreeWidgetItem* pItem = new QTreeWidgetItem(parentItemThree);
            pItem->setText(0, QString("Number %1").arg(i) );
            pItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDragEnabled);
            pItem->addChild(pItem);
            }

      }

void FlexibleTree::dropEvent(QDropEvent * event)
      {

      QModelIndex droppedIndex = indexAt( event->pos() );
      qDebug()<<"QDropEvent dropAction: "<<event->dropAction();

      if( !droppedIndex.isValid() || event->dropAction() != Qt::MoveAction) {
            qDebug()<<"Ignore. Either not a MoveAction or droppedIndex is not valid; "<<droppedIndex;
            return;
      }

      // the default move isn't working as expected
      // Look at implementing by hand - see (for tables): https://stackoverflow.com/questions/26227885/drag-and-drop-rows-within-qtablewidget
      qDebug()<<"DropEvent source: "<<event->source();

      QTreeWidgetItem* item = itemAt(droppedIndex.row(), droppedIndex.column());
      qDebug()<<"DropEvent item at pos(): "<<item->text(0);
      qDebug()<<"Drop indicator position: "<<dropIndicatorPosition();


      QTreeWidget::dropEvent(event);

      }


