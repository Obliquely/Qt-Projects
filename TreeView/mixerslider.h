#ifndef MIXERSLIDER_H
#define MIXERSLIDER_H

#include <QSlider>


class MixerSlider : public QSlider
      {
      Q_OBJECT

public:
      explicit MixerSlider(QWidget *parent = nullptr);
      ~MixerSlider();

      void paintEvent(QPaintEvent *ev);

      };

#endif // MIXERSLIDER_H
