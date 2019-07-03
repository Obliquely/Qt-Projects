#ifndef MIXEROPTIONSBUTTON_H
#define MIXEROPTIONSBUTTON_H

#include <QToolButton>
#include <QAction>
#include <QActionGroup>
#include <QMenu>
#include <QObject>

class MixerOptionsButton : public QToolButton
      {
      Q_OBJECT

      QMenu* overrideMenu;
      QAction* overrideOn;
      QAction* panSlider;
      QAction* reverbSlider;
      QAction* chorusSlider;
      QActionGroup* altSliderGroup;

   public slots:
      void overrideChecked(bool state);
      void panSliderOption(bool state);
      void reverbSliderOption(bool state);
      void chorusSliderOption(bool state);


public:
      MixerOptionsButton(QWidget *parent = nullptr);




      };

#endif // MIXEROPTIONSBUTTON_H
