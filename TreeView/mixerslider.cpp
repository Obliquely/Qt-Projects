#include "mixerslider.h"
#include <QStyleOptionSlider>
#include <QDebug>
#include <QPainter>
#include <QStylePainter>
#include <cmath>

MixerSlider::MixerSlider(QWidget *parent) :
      QSlider(parent)
      {

      }

MixerSlider::~MixerSlider()
      {

      }

void MixerSlider::paintEvent(QPaintEvent *ev) {




    QStylePainter painter(this);
    QStyleOptionSlider opt;
    initStyleOption(&opt);

    QRect handle = style()->subControlRect(QStyle::CC_Slider, &opt, QStyle::SC_SliderHandle, this);




    // draw the slider (this is basically copy/pasted from QSlider::paintEvent)
    //opt.subControls = QStyle::SC_SliderGroove;
    // painter.drawComplexControl(QStyle::CC_Slider, opt);

    // recreate slider drawing but without adjusting color to reflect value
    QRect groove_rect = style()->subControlRect(QStyle::CC_Slider, &opt, QStyle::SC_SliderGroove, this);
    groove_rect.setHeight(groove_rect.height() - 2);
    groove_rect.setTop(groove_rect.top() + 1);

    QPainterPath path;
    painter.setRenderHint(QPainter::Antialiasing);
    path.addRoundedRect(groove_rect, 2, 2);
    QPen pen(QColor("#888888"), 1);
    painter.setPen(pen);
    painter.fillPath(path, QColor("#CCCCCC"));
    painter.drawPath(path);


    // draw the slider handle
    opt.subControls = QStyle::SC_SliderHandle | QStyle::SC_SliderTickmarks;
    painter.drawComplexControl(QStyle::CC_Slider, opt);




     /* QStyleOptionSlider opt;
      initStyleOption(&opt);

      opt.subControls = QStyle::SC_SliderGroove | QStyle::SC_SliderHandle;


      if (tickPosition() != NoTicks) {
            opt.subControls |= QStyle::SC_SliderTickmarks;
            }


      //
      //  virtual QRect subControlRect(ComplexControl cc, const QStyleOptionComplex *opt, SubControl sc, const QWidget *widget = nullptr) const = 0;

      QRect groove_rect = style()->subControlRect(QStyle::CC_Slider, &opt, QStyle::SC_SliderGroove, this);

      QRect handle_rect = style()->subControlRect(QStyle::CC_Slider, &opt, QStyle::SC_SliderHandle, this);

      QRect lower_groove = QRect(groove_rect.left(), groove_rect.top() + 1, 1+ (handle_rect.left() - groove_rect.left()), groove_rect.height()-2);
      QRect upper_groove = QRect(groove_rect.right(), groove_rect.top() + 1,  (handle_rect.right() - groove_rect.right()), groove_rect.height()-2);


      qDebug() << "groove rect: "<< groove_rect;
      qDebug() << "handle rect: "<< handle_rect;


      QSlider::paintEvent(ev);      // super class

      QPainter painter(this);

      painter.fillRect(lower_groove, Qt::lightGray);
      painter.fillRect(upper_groove, Qt::lightGray);

//      QPainterPath handlePath;
//      handlePath.addRect(handle_rect);

//      QPainterPath path;
//      painter.setRenderHint(QPainter::Antialiasing);

//      path.addRoundedRect(groove_rect, 5, 2);

//      QPainterPath adjustedPath;
//      adjustedPath = path.subtracted(handlePath);


//      QPen pen(Qt::lightGray, 0.5);
//      painter.setPen(pen);
//      painter.fillPath(adjustedPath, Qt::lightGray);
//      painter.drawPath(adjustedPath);
*/
      }
