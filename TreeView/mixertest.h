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

     QList<QString> allPatchItems;

public:
    explicit MixerTest(QWidget *parent = nullptr);
    ~MixerTest();
    TrackList* trackList;


public slots:
    void showDetail();
    void verticalToggle();
    void qTextChanged(QString);

    void limitSliderMoved(int);
    void secondaryCheckBoxClicked();

    void patchFilterChanged(QString);
    void clearPatchFilter();

private:
    Ui::MixerTest *ui;
    QSplitter* splitter;
    bool isShowingDetail;
    void updateUi();
    QList<int> lastSizes;
    void setupFilterCombo();
    void setupSplitter();
    void setupSignalsAndSlots();

};

#endif // MIXERTEST_H
