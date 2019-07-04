#include "mixertest.h"
#include "ui_mixertest.h"
#include "mixercontrol.h"
#include <QTreeView>
#include <QPushButton>
#include <QAbstractButton>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QDebug>
#include <QtCore>
#include <QtGui>
#include <QSplitter>
#include "noneditableitemdelegate.h"

MixerTest::MixerTest(QWidget *parent) :
      QDialog(parent),
      ui(new Ui::MixerTest)
      {
      setupUi(this);

      limitedSlider->setPanMode(true);

      trackList = new TrackList();
      trackList->recoverData();

      QGridLayout* gridLayout = new QGridLayout(this);
      gridLayout->setMargin(0);

      // put the two widgets in a QSplitter
      splitter = new QSplitter();
      gridLayout->addWidget(splitter);

      splitter->addWidget(mainWidget);
      splitter->addWidget(secondaryWidget);

      splitter->setCollapsible(0, false);
      splitter->setCollapsible(1, false);

      connect(showDetailsButton, SIGNAL(clicked()), this, SLOT(showDetail()));
      connect(verticalButton, SIGNAL(clicked()), this, SLOT(verticalToggle()));
      connect(smartQ, SIGNAL(textChanged(QString)), this, SLOT(qTextChanged(QString)));
      connect(columnToggle, SIGNAL(clicked()), this, SLOT(columnToggled()));
      connect(secondaryCheckBox, SIGNAL(clicked()), this, SLOT(secondaryCheckBoxClicked()));

      connect(mixerTreeWidget, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(itemChanged(QTreeWidgetItem*, int)));

      connect(limitedSlider, SIGNAL(valueChanged(int)), this, SLOT(limitSliderMoved(int)));

      splitter->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
      splitter->adjustSize();


      mixerTreeWidget->setDragEnabled(true);

      mixerTreeWidget->setSelectionMode(QAbstractItemView::SingleSelection);
      mixerTreeWidget->viewport()->setAcceptDrops(true);
      mixerTreeWidget->setDropIndicatorShown(true);
      mixerTreeWidget->setDragDropMode(QAbstractItemView::InternalMove);

      configureHeader(mixerTreeWidget);

      for (MixerTrack* mixerTrack : trackList->tracks()) {

            QTreeWidgetItem* item = mixerTrack->treeWidgetItem;
            item->setFlags(Qt::ItemIsEditable | Qt::ItemIsEnabled);
            mixerTreeWidget->setItemDelegateForColumn(1, new NonEditableItemDelegate (mixerTreeWidget)); // make this one non-editable


            mixerTreeWidget->addTopLevelItem(item);

            mixerTreeWidget->setItemWidget(mixerTrack->treeWidgetItem, 1, mixerTrack->mixerControl);

            if (mixerTrack->children.count() == 0)
                  continue;

            QList<MixerTrack*> children = mixerTrack->children;

            for (int index = 0; index < children.count(); index++) {
                  MixerTrack* subTrack = mixerTrack->children[index];
                  mixerTrack->treeWidgetItem->addChild(subTrack->treeWidgetItem);
                  mixerTreeWidget->setItemWidget(subTrack->treeWidgetItem, 1, subTrack->mixerControl);
                  }

            }

      }

MixerTest::~MixerTest()
      {
      delete ui;
      }

void MixerTest::secondaryCheckBoxClicked()
      {
      qDebug()<<"secondaryCheckBoxClicked new state = "<<secondaryCheckBox->isChecked();
      chorusSlider->setSecondaryMode(secondaryCheckBox->isChecked());
      limitedSlider->setSecondaryMode(secondaryCheckBox->isChecked());

      }

void MixerTest::limitSliderMoved(int value)
      {

      if (value <-50) {

            limitedSlider->setValue(-50);
            }

      limitSpinBox->setValue(value);

      }


void MixerTest::itemChanged(QTreeWidgetItem* item, int column)
      {
      qDebug()<<"an item has changed. New text is: "<<item->text(column);

      // update the model
      // FIND the mixerTrack associated with the model
      // current design is BAD - ought to be able to pull it off the item by sublcassing
      // QTreeWidgetItem

      int index = mixerTreeWidget->indexOfTopLevelItem(item); // this is a bit of hack!

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

void MixerTest::adjustHeaderWidths()
      {
      QTreeWidget* treeWidget = mixerTreeWidget;
      QHeaderView* header = treeWidget->header();

      if (treeWidget->columnCount() == 2) {

            int width = treeWidget->width();

            double ratio = 0.4;
            int margin = 1;

            int column0 = int(double(width) * ratio) - margin;
            int column1 = int(double(width) * (1-ratio) -margin);

            if (column0 > 300) {
                  column0 = 300;
                  column1 = width - 300 - margin;
                  }

            header->resizeSection(0, column0);
            header->resizeSection(1, column1);
            }

      else if (treeWidget->columnCount() == 3) {

            int width = treeWidget->width();

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

            header->resizeSection(0, column0 - margin);
            header->resizeSection(1, column1 - margin);
            header->resizeSection(1, column2 - margin);
            }


      }

void MixerTest::configureHeader(QTreeWidget* treeWidget)
      {
      treeWidget->setColumnCount(2);
      QHeaderView* header = treeWidget->header();
      header->setSectionResizeMode(0, QHeaderView::Fixed);
      header->setSectionResizeMode(1, QHeaderView::Fixed);

      connect(header, SIGNAL(geometriesChanged()), this, SLOT(adjustHeaderWidths()));
      adjustHeaderWidths();
      }


void MixerTest::qTextChanged(QString string)
      {
      qDebug()<<"qTextChanged (1): |"<<string<<"|";
      QString previous ="";
      QString next = "";
      QString replacement = "";

      for (int i = 0; i < string.size(); ++i) {
            next = i + 1 < string.size() ? string.at(i+1) : QString("");

            QString current = string.at(i); // "Hello"
            if (current ==  "\"")
                  {
                        qDebug()<<"QUOTE at "<<i;
                  }

            bool doubleQuote = string.at(i) == "\"";
            bool singleQuote = string.at(i) == "'";

            if (!singleQuote && !doubleQuote)
                  continue;

            if (previous.isEmpty() || previous == " ") {
                  replacement = doubleQuote ? "“" : "‘";
                  }
            else {
                  replacement = doubleQuote ? "”" : "’";
                  }
            string.replace(i, 1, replacement);
            previous = string.at(i);
         }

      smartQ->setText(string);
      }




void MixerTest::columnToggled()
      {

      int columnCount = mixerTreeWidget->columnCount();

      if (columnCount == 2) {

            mixerTreeWidget->setColumnCount(3);
            QTreeWidgetItem* headerItem = mixerTreeWidget->headerItem();
            qDebug()<<"headeritem = "<<mixerTreeWidget->headerItem();
            headerItem->setText(0, "Name");
            headerItem->setText(1, "Adjustments");
            headerItem->setText(2, "Bonus");
            }
      else {
            mixerTreeWidget->setColumnCount(2);

            QTreeWidgetItem* headerItem = mixerTreeWidget->headerItem();
            qDebug()<<"headeritem = "<<mixerTreeWidget->headerItem();
            headerItem->setText(0, "Title");
            headerItem->setText(1, "Volume");
            }

      adjustHeaderWidths();


      }

#define MAX_WIDGET_LENGTH 16777215


void MixerTest::showDetail()
      {

      qDebug("Show Detailclicked");

      isShowingDetail = !isShowingDetail;

      secondaryWidget->setVisible(isShowingDetail);


      // borrowed code

      secondaryWidget->setVisible( ! secondaryWidget->isVisible() );

      if( not secondaryWidget->isVisible() )
            {
            lastSizes = splitter->sizes();
            splitter->setSizes( QList< int >{ mainWidget->width(), 0 } );
            }
      else
            {
            splitter->setSizes( lastSizes );
            }


      }


void MixerTest::verticalToggle()
      {
      Qt::Orientation current = splitter->orientation();

      if (current == Qt::Vertical) {
            splitter->setOrientation(Qt::Horizontal);
            int minWidth = mainWidget->minimumWidth() + 32;
            if (secondaryWidget->isVisible())
                  minWidth += secondaryWidget->minimumWidth() + 32;
            splitter->setMinimumWidth(minWidth);
            splitter->setMinimumHeight(mainWidget->minimumHeight() + 32);
            }
      else  {
            splitter->setOrientation(Qt::Vertical);
            int minHeight = mainWidget->minimumHeight() + 20;
            if (secondaryWidget->isVisible())
                  minHeight += secondaryWidget->minimumHeight() + 32;
            splitter->setMinimumHeight(minHeight);
            splitter->setMinimumWidth(mainWidget->minimumWidth() + 32);
            }

      splitter->adjustSize();

      }

/*

      int treeWidgetWidth = mixerTreeWidget->width();
      int treeWidgetHeight = mixerTreeWidget->height();

      if (isShowingDetail == true) {
            // seek to constrain the size

            // case where it's OK to get wider

            // pin the height and width of the treeView
            mixerTreeWidget->setMaximumHeight(treeWidgetHeight);
            mixerTreeWidget->setMinimumHeight(treeWidgetHeight);
            mixerTreeWidget->setMinimumWidth(treeWidgetWidth);
            mixerTreeWidget->setMaximumWidth(treeWidgetWidth);

            // add the details view
            updateUi();
            qDebug()<<"SHOW DETAILS treeWidgetWidth before:"<<treeWidgetWidth<<" and after: "<<mixerTreeWidget->width();
            this->adjustSize();

            mixerTreeWidget->setMinimumHeight(200);
            mixerTreeWidget->setMaximumHeight(MAX_WIDGET_LENGTH);
            mixerTreeWidget->setMinimumWidth(200);
            mixerTreeWidget->setMaximumWidth(MAX_WIDGET_LENGTH);
            }
      else {
            // case where we want to get narrower, but keep the size of the treeWidget
            mixerTreeWidget->setMaximumHeight(treeWidgetHeight);
            mixerTreeWidget->setMinimumHeight(treeWidgetHeight);
            mixerTreeWidget->setMinimumWidth(treeWidgetWidth);
            mixerTreeWidget->setMaximumWidth(treeWidgetWidth);
            updateUi();
            this->adjustSize();
            qDebug()<<"HIDE DETAILS treeWidgetWidth before:"<<treeWidgetWidth<<" and after: "<<mixerTreeWidget->width();
            mixerTreeWidget->setMinimumHeight(200);
            mixerTreeWidget->setMaximumHeight(MAX_WIDGET_LENGTH);
            mixerTreeWidget->setMinimumWidth(200);
            mixerTreeWidget->setMaximumWidth(MAX_WIDGET_LENGTH);
            }
      }
*/
