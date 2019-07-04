#ifndef MIXERTEST_H
#define MIXERTEST_H

#include <QDialog>
#include <QAbstractButton>
#include <QSplitter>
#include "ui_mixertest.h"
#include "tracklist.h"

namespace Ui {
class MixerTest;
}

class MixerTest : public QDialog, Ui::MixerTest
{
    Q_OBJECT

public:
    explicit MixerTest(QWidget *parent = nullptr);
    ~MixerTest();
    TrackList* trackList;


public slots:
    void showDetail();
    void verticalToggle();
    void qTextChanged(QString);
    void adjustHeaderWidths();
    void columnToggled();
    void itemChanged(QTreeWidgetItem*, int);

    void limitSliderMoved(int);
    void secondaryCheckBoxClicked();


private:
    Ui::MixerTest *ui;
    QSplitter* splitter;
    bool isShowingDetail;
    void updateUi();
    QList<int> lastSizes;

    void configureHeader(QTreeWidget* treeWidget);
};

#endif // MIXERTEST_H
