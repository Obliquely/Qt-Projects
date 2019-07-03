#ifndef LEARNING_H
#define LEARNING_H

#include <QString>

class LearningLambda
      {

      template <class CustomAction>
      void repeater(CustomAction lambda);
      template <class CustomAction>
      void repeaterBeta(CustomAction lambda, int value);

      void biff(QString string);
      void zipp(QString string);

public:
      LearningLambda();

      void testMe();
      };

#endif // LEARNING_H
