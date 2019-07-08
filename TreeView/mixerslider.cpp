#include "mixerslider.h"
#include <QStyleOptionSlider>
#include <QDebug>
#include <QPainter>
#include <QStylePainter>
#include <QApplication>

MixerSlider::MixerSlider(QWidget *parent) :
      QSlider(parent)
      {
      installEventFilter(this);
      }

MixerSlider::~MixerSlider()
      {

      }

void MixerSlider::mouseDoubleClickEvent(QMouseEvent* mouseEvent)
      {
      if (panning) {
            setValue(0);
            return;
            }

      QSlider::mouseDoubleClickEvent(mouseEvent);

      }

void MixerSlider::setSecondaryMode(bool on)
      {

      secondary = on;
      repaint();

      }

void MixerSlider::paintEvent(QPaintEvent *ev) {

     if ((false)) {     // shut up compiler warnings about unused parameter ev and then non-executed code
           QSlider::paintEvent(ev);
           }

      QColor buttonColor = QApplication::palette().color(QPalette::Button);
      QColor secondaryColor = QApplication::palette().color(QPalette::Highlight);

      if (secondary) {
            secondaryColor.setHsv(secondaryColor.hue() + 180 % 360,
                                  secondaryColor.saturation(),
                                  secondaryColor.value());
            }

      QColor grooveBackgroundColor;
      grooveBackgroundColor.setHsv(buttonColor.hue(),
                         qMin(255, static_cast<int>(buttonColor.saturation())),
                         qMin(255, static_cast<int>(buttonColor.value()*0.9)));

      QColor grooveFillColor;
      grooveFillColor.setHsv(secondaryColor.hue(),
                         qMin(255, static_cast<int>(secondaryColor.saturation() * 3)),
                         qMin(255, static_cast<int>(secondaryColor.value() * 3)));

      QColor outlineColor;
      outlineColor.setHsv(buttonColor.hue(),
                          qMin(255, static_cast<int>(buttonColor.saturation())),
                          qMin(255, static_cast<int>(buttonColor.value()*0.6)));


      QStyleOptionSlider opt;
      initStyleOption(&opt);

      QRect grooveRect = style()->subControlRect(QStyle::CC_Slider, &opt, QStyle::SC_SliderGroove, this);
      QRect handleRect = style()->subControlRect(QStyle::CC_Slider, &opt, QStyle::SC_SliderHandle, this);

      int handleMargin = 3;
      QRect lowerGroove = QRect(grooveRect.left(), grooveRect.top(), handleMargin + handleRect.left(), grooveRect.height());
      QRect upperGroove = QRect(handleRect.right() - handleMargin, grooveRect.top(), (grooveRect.right() - handleRect.right()) + handleMargin, grooveRect.height());

      QLinearGradient lowerGradient;

      lowerGradient.setStart(lowerGroove.center().x(), lowerGroove.top());
      lowerGradient.setFinalStop(lowerGroove.center().x(), lowerGroove.bottom());

      lowerGradient.setColorAt(0, grooveFillColor.darker(110));
      lowerGradient.setColorAt(1, grooveFillColor.lighter(110));

      QLinearGradient upperGradient;


      upperGradient.setStart(upperGroove.center().x(), upperGroove.top());
      upperGradient.setFinalStop(upperGroove.center().x(), upperGroove.bottom());

      upperGradient.setColorAt(0, grooveBackgroundColor.darker(110));
      upperGradient.setColorAt(1, grooveBackgroundColor.lighter(110));


      QStylePainter painter(this);
      painter.setBrush(panning ? upperGradient : lowerGradient);

      // recreate slider drawing but without adjusting color to reflect value
      painter.setRenderHint(QPainter::Antialiasing);
      painter.setPen(QPen(outlineColor)); // QApplication::palette().color(QPalette::Text)));


      painter.drawRect(lowerGroove.adjusted(1, 1, -2, -2));

      painter.setBrush(upperGradient);
      painter.drawRect(upperGroove.adjusted(1, 1, -2, -2));


      // draw the slider handle and tick marks
      opt.subControls = QStyle::SC_SliderHandle | QStyle::SC_SliderTickmarks;
      painter.drawComplexControl(QStyle::CC_Slider, opt);

      }
