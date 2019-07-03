#ifndef FLEXIBLETREE_H
#define FLEXIBLETREE_H

#include <QObject>
#include <QTreeWidget>
#include <QTreeView>
#include <QDropEvent>


class FlexibleTree : public QTreeWidget
      {
public:
      FlexibleTree();

private:
  virtual void  dropEvent(QDropEvent * event);

      };

#endif // FLEXIBLETREE_H








