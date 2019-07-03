#include "learning.h"
#include <QDebug>

LearningLambda::LearningLambda()
      {
     // constructor
      }

void LearningLambda::biff(QString string)
      {
      qDebug()<<"Biff says: "<<string;
      }

void LearningLambda::zipp(QString string)
      {
      qDebug()<<"Zipp says: "<<string;
      }

template <class CustomAction>
void LearningLambda::repeater(CustomAction action) {

      for (int i = 0; i < 2; i++) {
            action();
            }
      }

template <class CustomAction>
void LearningLambda::repeaterBeta(CustomAction action, int value1) {

      for (int i = 0; i < 2; i++) {
            action(value1);
            }
      }

void LearningLambda::testMe()
      {

      qDebug()<<"Learning::testMe() is starting up";

      QString greeting = "hello";

      auto customOperation = [this, greeting](){ biff(greeting); zipp("pancakes"); };

      repeater(customOperation);
      repeater([this, greeting](){ biff(greeting); zipp("fishcakes"); });
      repeater([this, greeting](){ zipp(greeting); });

      auto customOpBeta = [this](int count) -> void { biff(QString("Hello: %1:").arg(count)); };

      customOpBeta(2);
      int two = 2;
      repeaterBeta(customOpBeta, two);


      }




