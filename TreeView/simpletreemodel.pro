QT += widgets
requires(qtConfig(treeview))

HEADERS     = treeitem.h \
              mixertest.h \
              treemodel.h
RESOURCES   = simpletreemodel.qrc
SOURCES     = treeitem.cpp \
              mixertest.cpp \
              treemodel.cpp \
              main.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/itemviews/simpletreemodel
INSTALLS += target

FORMS += \
    mixertest.ui
