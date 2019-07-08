#ifndef PATCHCOMBOBOX_H
#define PATCHCOMBOBOX_H

#include <QComboBox>
#include <QSortFilterProxyModel>
#include <QCompleter>

class PatchComboBox : public QComboBox
      {
      Q_OBJECT

      QSortFilterProxyModel* pFilterModel;
      QCompleter* completer;

public slots:

      void completerActivated(QString text);


public:
      explicit PatchComboBox(QWidget *parent = nullptr);
      void setModel(QAbstractItemModel* model);

      void setModelColumn(int visibleColumn);


      };

#endif // PATCHCOMBOBOX_H

