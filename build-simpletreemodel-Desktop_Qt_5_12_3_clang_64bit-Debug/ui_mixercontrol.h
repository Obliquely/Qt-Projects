/********************************************************************************
** Form generated from reading UI file 'mixercontrol.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MIXERCONTROL_H
#define UI_MIXERCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QSlider>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MixerControl
{
public:
    QGridLayout *gridLayout;
    QToolButton *muteButton;
    QToolButton *soloButton;
    QSlider *volumeSlider;

    void setupUi(QWidget *MixerControl)
    {
        if (MixerControl->objectName().isEmpty())
            MixerControl->setObjectName(QString::fromUtf8("MixerControl"));
        MixerControl->resize(183, 20);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MixerControl->sizePolicy().hasHeightForWidth());
        MixerControl->setSizePolicy(sizePolicy);
        MixerControl->setMinimumSize(QSize(0, 20));
        MixerControl->setFocusPolicy(Qt::TabFocus);
        gridLayout = new QGridLayout(MixerControl);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(-1);
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(-1, 0, -1, 0);
        muteButton = new QToolButton(MixerControl);
        muteButton->setObjectName(QString::fromUtf8("muteButton"));
        muteButton->setMaximumSize(QSize(40, 16777215));
        muteButton->setCheckable(true);
        muteButton->setToolButtonStyle(Qt::ToolButtonTextOnly);

        gridLayout->addWidget(muteButton, 0, 1, 1, 1);

        soloButton = new QToolButton(MixerControl);
        soloButton->setObjectName(QString::fromUtf8("soloButton"));
        soloButton->setMaximumSize(QSize(40, 16777215));
        soloButton->setCheckable(true);
        soloButton->setToolButtonStyle(Qt::ToolButtonTextOnly);

        gridLayout->addWidget(soloButton, 0, 2, 1, 1);

        volumeSlider = new QSlider(MixerControl);
        volumeSlider->setObjectName(QString::fromUtf8("volumeSlider"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(volumeSlider->sizePolicy().hasHeightForWidth());
        volumeSlider->setSizePolicy(sizePolicy1);
        volumeSlider->setMinimumSize(QSize(100, 0));
        volumeSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    background: lightgray;\n"
"    position: absolute; \n"
"    top: 6px; bottom: 6px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    width: 10px;\n"
"    background: gray;\n"
"	border: 1px solid;\n"
"     border-color: darkgray;\n"
"    margin: -3px 0px; \n"
"}\n"
""));
        volumeSlider->setMinimum(-63);
        volumeSlider->setMaximum(63);
        volumeSlider->setOrientation(Qt::Horizontal);
        volumeSlider->setTickPosition(QSlider::TicksAbove);
        volumeSlider->setTickInterval(64);

        gridLayout->addWidget(volumeSlider, 0, 0, 1, 1, Qt::AlignTop);


        retranslateUi(MixerControl);

        QMetaObject::connectSlotsByName(MixerControl);
    } // setupUi

    void retranslateUi(QWidget *MixerControl)
    {
        MixerControl->setWindowTitle(QApplication::translate("MixerControl", "Track Control", nullptr));
#ifndef QT_NO_WHATSTHIS
        MixerControl->setWhatsThis(QApplication::translate("MixerControl", "Track Control (what)", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        MixerControl->setAccessibleName(QApplication::translate("MixerControl", "Track Control (ac)", nullptr));
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_WHATSTHIS
        muteButton->setWhatsThis(QApplication::translate("MixerControl", "Mut button", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        muteButton->setAccessibleName(QApplication::translate("MixerControl", "Mute", nullptr));
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        muteButton->setAccessibleDescription(QApplication::translate("MixerControl", "Mutte option", nullptr));
#endif // QT_NO_ACCESSIBILITY
        muteButton->setText(QApplication::translate("MixerControl", "M", nullptr));
#ifndef QT_NO_WHATSTHIS
        soloButton->setWhatsThis(QApplication::translate("MixerControl", "Solo Button", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        soloButton->setAccessibleName(QApplication::translate("MixerControl", "Solo", nullptr));
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        soloButton->setAccessibleDescription(QApplication::translate("MixerControl", "Solo Option", nullptr));
#endif // QT_NO_ACCESSIBILITY
        soloButton->setText(QApplication::translate("MixerControl", "S", nullptr));
#ifndef QT_NO_WHATSTHIS
        volumeSlider->setWhatsThis(QApplication::translate("MixerControl", "Volume sider", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        volumeSlider->setAccessibleName(QApplication::translate("MixerControl", "Volume", nullptr));
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        volumeSlider->setAccessibleDescription(QApplication::translate("MixerControl", "Volume Option", nullptr));
#endif // QT_NO_ACCESSIBILITY
    } // retranslateUi

};

namespace Ui {
    class MixerControl: public Ui_MixerControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MIXERCONTROL_H
