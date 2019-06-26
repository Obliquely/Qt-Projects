#ifndef MIXERCONTROL_H
#define MIXERCONTROL_H

#include <QWidget>

namespace Ui {
class MixerControl;
}

class MixerControl : public QWidget
{
    Q_OBJECT

public:
    explicit MixerControl(QWidget *parent = nullptr);
    ~MixerControl();

private:
    Ui::MixerControl *ui;
};

#endif // MIXERCONTROL_H
