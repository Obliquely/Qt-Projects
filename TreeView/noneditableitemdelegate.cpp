#include "noneditableitemdelegate.h"


NonEditableItemDelegate::NonEditableItemDelegate(QObject* parent) : QStyledItemDelegate(parent)
      {
      }

QWidget* NonEditableItemDelegate::createEditor(QWidget*, const QStyleOptionViewItem&, const QModelIndex&) const
      {
      return nullptr;
      }
