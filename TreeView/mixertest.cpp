#include "mixertest.h"
#include "ui_mixertest.h"
#include "mixercontrol.h"
#include <QTreeView>
#include <QPushButton>
#include <QAbstractButton>

#include <QDebug>
#include <QtCore>
#include <QtGui>
#include <QSplitter>

MixerTest::MixerTest(QWidget *parent) :
      QDialog(parent),
      ui(new Ui::MixerTest)
      {
      setupUi(this);

      setupFilterCombo();
      setupSplitter();

      trackList = new TrackList();
      trackList->recoverData();

      mixerTreeWidget->setupAdditionalUi();
      mixerTreeWidget->setTrackList(trackList);

      panSlider->setPanMode(true);

      setupSignalsAndSlots();
      }

MixerTest::~MixerTest()
      {
      delete ui;
      }


void MixerTest::setupSignalsAndSlots()
      {
      connect(showDetailsButton, SIGNAL(clicked()), this, SLOT(showDetail()));
      connect(verticalButton, SIGNAL(clicked()), this, SLOT(verticalToggle()));
      connect(smartQ, SIGNAL(textChanged(QString)), this, SLOT(qTextChanged(QString)));
      connect(columnToggle, SIGNAL(clicked()), mixerTreeWidget, SLOT(columnToggled()));
      connect(secondaryCheckBox, SIGNAL(clicked()), this, SLOT(secondaryCheckBoxClicked()));
      connect(limitedSlider, SIGNAL(valueChanged(int)), this, SLOT(limitSliderMoved(int)));
      }

void MixerTest::setupSplitter()
      {

      QGridLayout* gridLayout = new QGridLayout(this);
      gridLayout->setMargin(0);

      // put the two widgets in a QSplitter
      splitter = new QSplitter();
      gridLayout->addWidget(splitter);

      splitter->addWidget(mainWidget);
      splitter->addWidget(secondaryWidget);

      splitter->setCollapsible(0, false);
      splitter->setCollapsible(1, false);

      splitter->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
      splitter->adjustSize();
      }

void MixerTest::setupFilterCombo() {


      patchCombo->addItems({"Abc", "Def", "Ghi", "Piano", "Pianoforte", "Trumpet", "Trombone", "Piccolo", "Fortepiano"});

      allPatchItems = {"Trumpet", "Violin 1", "Violin 2", "Violincello", "Fortepiano", "Piano", "Kawai Piano", "Trombone", "Viola", "EMS2", "Electic Guitar", "Bass Guitar", "Double Bass", "Violin 3", "Oboe", "Clarinet", "Saxophone", "French Horn"};

      clearPatchFilter();

      connect(filterBox, SIGNAL(textEdited(QString)), this, SLOT(patchFilterChanged(QString)));
      connect(clearFilter, SIGNAL(clicked()), this, SLOT(clearPatchFilter()));


      }

void MixerTest::patchFilterChanged(QString filter) {
      qDebug()<<"patchFilterChanged";
      QList<QString> filteredList;

      for (QString string : allPatchItems) {

            if (string.contains(filter, Qt::CaseInsensitive)) {
                  filteredList.append(string);
                  }
            }

      standardPatchCombo->clear();
      standardPatchCombo->addItems(filteredList);


      int count = standardPatchCombo->count();
      bool isAllItems = (count == allPatchItems.count());

      QString suffix = (count == 1) ? "patch" : "patches";
      QString prefix = isAllItems ? "All" : QString::number(count);

      QString formattedCount = QString("%1  %2").arg(prefix).arg(suffix);

      patchCount->setText(formattedCount);

      clearFilter->setEnabled(!isAllItems);


      }

void MixerTest::clearPatchFilter()
      {

      filterBox->setText("");
      patchFilterChanged("");

      }

void MixerTest::secondaryCheckBoxClicked()
      {
      qDebug()<<"secondaryCheckBoxClicked new state = "<<secondaryCheckBox->isChecked();
      limitedSlider->setSecondaryMode(secondaryCheckBox->isChecked());
      panSlider->setSecondaryMode(secondaryCheckBox->isChecked());

      }

void MixerTest::limitSliderMoved(int value)
      {

      if (value <25) {
            limitedSlider->setValue(25);
            }

      if (value > 105) {
            limitedSlider->setValue(105);
            }

      limitSpinBox->setValue(value);

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

