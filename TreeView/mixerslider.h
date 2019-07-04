#ifndef MIXERSLIDER_H
#define MIXERSLIDER_H

#include <QSlider>


class MixerSlider : public QSlider
      {
      Q_OBJECT

 bool panning = false;       // used for pan-style where filling does not make sense
 bool secondary = false;

public:
      explicit MixerSlider(QWidget *parent = nullptr);
      ~MixerSlider();

      void paintEvent(QPaintEvent *ev);

      void setPanMode(bool on) { panning = on; }
      bool panMode() { return panning; }
      void setSecondaryMode (bool on);
      bool secondaryMode() { return secondary; }


      void mouseDoubleClickEvent(QMouseEvent* mouseEvent);
      };

#endif // MIXERSLIDER_H
