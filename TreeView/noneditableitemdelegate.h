#ifndef __MIXERTREENONEDITABLEITEMDELEGATE_H__
#define __MIXERTREENONEDITABLEITEMDELEGATE_H__

#include <QStyledItemDelegate>

// Usage:
// treeWidget->setItemDelegateForColumn(column, new  MixerTreeNonEditableItemDelegate(treeWidget));
// This will turn editing OFF for the selected column when editing is ON for the item.

class NonEditableItemDelegate : public QStyledItemDelegate
      {
public:
      NonEditableItemDelegate(QObject* parent = nullptr);
      virtual QWidget* createEditor(QWidget*, const QStyleOptionViewItem&, const QModelIndex&) const;

      };

#endif // __MIXERTREENONEDITABLEITEMDELEGATE_H__
