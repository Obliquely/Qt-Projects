#ifndef MIXERTEST_H
#define MIXERTEST_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class MixerTest;
}

class MixerTest : public QDialog
{
    Q_OBJECT

public:
    explicit MixerTest(QWidget *parent = nullptr);
    ~MixerTest();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::MixerTest *ui;
};

#endif // MIXERTEST_H
