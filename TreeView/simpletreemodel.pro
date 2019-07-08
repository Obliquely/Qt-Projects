QT += widgets
requires(qtConfig(treeview))

HEADERS     = treeitem.h \
              flexibletree.h \
              learning.h \
              mixercontrol.h \
              mixeroptionsbutton.h \
              mixerslider.h \
              mixertest.h \
              mixertrack.h \
              mixertreewidget.h \
              noneditableitemdelegate.h \
              patchcombobox.h \
              tracklist.h \
              treemodel.h
RESOURCES   = simpletreemodel.qrc
SOURCES     = treeitem.cpp \
              flexibletree.cpp \
              learningLambda.cpp \
              mixercontrol.cpp \
              mixeroptionsbutton.cpp \
              mixerslider.cpp \
              mixertest.cpp \
              mixertrack.cpp \
              mixertreewidget.cpp \
              noneditableitemdelegate.cpp \
              patchcombobox.cpp \
              tracklist.cpp \
              treemodel.cpp \
              main.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/itemviews/simpletreemodel
INSTALLS += target

FORMS += \
    mixercontrol.ui \
    mixertest.ui \
    mixertreewidget.ui
