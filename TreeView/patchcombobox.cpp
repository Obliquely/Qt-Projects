#include "patchcombobox.h"
#include <QLineEdit>

PatchComboBox::PatchComboBox(QWidget* parent) : QComboBox(parent)
      {

      setFocusPolicy(Qt::StrongFocus);
      setEditable(true);

      // add a filter model to filter matching items
      pFilterModel = new QSortFilterProxyModel(this);
      pFilterModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
      pFilterModel->setSourceModel(model());

      // add a completer, which uses the filter model
      completer = new QCompleter(pFilterModel, this);

      // always show all (filtered) completions
      completer->setCompletionMode(QCompleter::UnfilteredPopupCompletion);


      // connect signals
      connect(lineEdit(), SIGNAL(textEdited(QString)), pFilterModel, SLOT(setFilterFixedString(QString)));

      connect(completer, SIGNAL(activated(QString)), this, SLOT(completerActivated(QString)));

      // this.lineEdit().textEdited[unicode].connect(this.pFilterModel.setFilterFixedString);
      //  this.completer.activated.connect(this.on_completer_activated);

      }


// on selection of an item from the completer, select the corresponding item from combobox
void PatchComboBox::completerActivated(QString text)
      {
      if (!text.isEmpty()) {
            int index = findText(text);
            setCurrentIndex(index);
            }
      }

// on model change, update the models of the filter and completer as well
void PatchComboBox::setModel(QAbstractItemModel* model)
      {
      QComboBox::setModel(model);

      pFilterModel->setSourceModel(model);
      completer->setModel(pFilterModel);


      //super(ExtendedComboBox, this).setModel(model)
      // this.pFilterModel.setSourceModel(model)
      // this.completer.setModel(this.pFilterModel)
      }


// on model column change, update the model column of the filter and completer as well
void PatchComboBox::setModelColumn(int column)
      {
      completer->setCompletionColumn(column);
      pFilterModel->setFilterKeyColumn(column);
      QComboBox::setModelColumn(column);
      }

//      this.completer.setCompletionColumn(column)
//    this.pFilterModel.setFilterKeyColumn(column)
//    super(ExtendedComboBox, this).setModelColumn(column)


    /*
    if __name__ == "__main__":
    import sys
    from PyQt4.QtGui import QStringListModel, QApplication

                                              app = QApplication(sys.argv)

    string_list = ['hola muchachos', 'adios amigos', 'hello world', 'good bye']

      combo = ExtendedComboBox()

    // either fill the standard model of the combobox
    combo.addItems(string_list)

    // or use another model
    //combo.setModel(QStringListModel(string_list))

    combo.resize(300, 40)
      combo.show()

    sys.exit(app.exec_())


    }*/
