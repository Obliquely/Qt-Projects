/********************************************************************************
** Form generated from reading UI file 'mixertest.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MIXERTEST_H
#define UI_MIXERTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>
#include "mixeroptionsbutton.h"
#include "mixerslider.h"

QT_BEGIN_NAMESPACE

class Ui_MixerTest
{
public:
    QWidget *secondaryWidget;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QSlider *horizontalSlider;
    QLabel *label_10;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    MixerSlider *chorusSlider;
    QSpinBox *spinBox;
    QDial *dial;
    QSpinBox *spinBox_4;
    QFormLayout *formLayout;
    QLabel *label_9;
    MixerOptionsButton *toolButton;
    QLabel *label_3;
    QLabel *label_5;
    QSpinBox *spinBox_6;
    QLineEdit *smartQ;
    QLabel *label_7;
    MixerSlider *limitedSlider;
    QSpinBox *spinBox_5;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *radioButton_3;
    QLabel *label_11;
    QRadioButton *radioButton_2;
    QSpinBox *limitSpinBox;
    QLabel *label_4;
    QLabel *label_8;
    QSlider *horizontalSlider_2;
    QComboBox *patchComboBox;
    QSpinBox *spinBox_2;
    QWidget *mainWidget;
    QGridLayout *gridLayout_2;
    QTreeWidget *mixerTreeWidget;
    QGridLayout *gridLayout;
    QPushButton *verticalButton;
    QPushButton *showDetailsButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *columnToggle;
    QCheckBox *secondaryCheckBox;

    void setupUi(QDialog *MixerTest)
    {
        if (MixerTest->objectName().isEmpty())
            MixerTest->setObjectName(QString::fromUtf8("MixerTest"));
        MixerTest->resize(627, 594);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MixerTest->sizePolicy().hasHeightForWidth());
        MixerTest->setSizePolicy(sizePolicy);
        MixerTest->setMinimumSize(QSize(289, 301));
        secondaryWidget = new QWidget(MixerTest);
        secondaryWidget->setObjectName(QString::fromUtf8("secondaryWidget"));
        secondaryWidget->setGeometry(QRect(320, 30, 294, 347));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(secondaryWidget->sizePolicy().hasHeightForWidth());
        secondaryWidget->setSizePolicy(sizePolicy1);
        secondaryWidget->setMinimumSize(QSize(270, 261));
        secondaryWidget->setMaximumSize(QSize(350, 16777215));
        secondaryWidget->setFocusPolicy(Qt::TabFocus);
        gridLayout_3 = new QGridLayout(secondaryWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_2 = new QLabel(secondaryWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_2, 5, 2, 1, 1);

        horizontalSlider = new QSlider(secondaryWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMinimumSize(QSize(0, 20));
        horizontalSlider->setMinimum(-63);
        horizontalSlider->setMaximum(63);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(64);

        gridLayout_3->addWidget(horizontalSlider, 6, 1, 1, 2);

        label_10 = new QLabel(secondaryWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_10, 8, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 11, 1, 1, 1);

        label = new QLabel(secondaryWidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label, 5, 0, 1, 1);

        chorusSlider = new MixerSlider(secondaryWidget);
        chorusSlider->setObjectName(QString::fromUtf8("chorusSlider"));
        chorusSlider->setMaximum(127);
        chorusSlider->setPageStep(16);
        chorusSlider->setOrientation(Qt::Horizontal);
        chorusSlider->setTickPosition(QSlider::TicksBelow);
        chorusSlider->setTickInterval(16);

        gridLayout_3->addWidget(chorusSlider, 3, 1, 1, 2);

        spinBox = new QSpinBox(secondaryWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimumSize(QSize(0, 20));

        gridLayout_3->addWidget(spinBox, 5, 1, 1, 1);

        dial = new QDial(secondaryWidget);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setMinimumSize(QSize(0, 30));
        dial->setMinimum(-63);
        dial->setMaximum(63);
        dial->setNotchTarget(15.000000000000000);
        dial->setNotchesVisible(true);

        gridLayout_3->addWidget(dial, 8, 1, 1, 2);

        spinBox_4 = new QSpinBox(secondaryWidget);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setMinimumSize(QSize(40, 0));
        spinBox_4->setMaximumSize(QSize(40, 16777215));

        gridLayout_3->addWidget(spinBox_4, 7, 3, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_9 = new QLabel(secondaryWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_9);

        toolButton = new MixerOptionsButton(secondaryWidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setMinimumSize(QSize(80, 0));
        QFont font;
        font.setPointSize(13);
        font.setBold(false);
        font.setWeight(50);
        toolButton->setFont(font);
        toolButton->setPopupMode(QToolButton::MenuButtonPopup);
        toolButton->setToolButtonStyle(Qt::ToolButtonTextOnly);
        toolButton->setAutoRaise(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, toolButton);


        gridLayout_3->addLayout(formLayout, 13, 0, 1, 4);

        label_3 = new QLabel(secondaryWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_3, 6, 0, 1, 1);

        label_5 = new QLabel(secondaryWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_5, 2, 0, 1, 1);

        spinBox_6 = new QSpinBox(secondaryWidget);
        spinBox_6->setObjectName(QString::fromUtf8("spinBox_6"));
        spinBox_6->setMinimumSize(QSize(40, 0));
        spinBox_6->setMaximumSize(QSize(40, 16777215));

        gridLayout_3->addWidget(spinBox_6, 3, 3, 1, 1);

        smartQ = new QLineEdit(secondaryWidget);
        smartQ->setObjectName(QString::fromUtf8("smartQ"));
        smartQ->setMinimumSize(QSize(0, 36));
        QFont font1;
        font1.setPointSize(24);
        smartQ->setFont(font1);

        gridLayout_3->addWidget(smartQ, 0, 1, 1, 3);

        label_7 = new QLabel(secondaryWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_7, 4, 0, 1, 1);

        limitedSlider = new MixerSlider(secondaryWidget);
        limitedSlider->setObjectName(QString::fromUtf8("limitedSlider"));
        limitedSlider->setMinimum(-63);
        limitedSlider->setMaximum(63);
        limitedSlider->setPageStep(16);
        limitedSlider->setOrientation(Qt::Horizontal);
        limitedSlider->setTickPosition(QSlider::TicksBelow);
        limitedSlider->setTickInterval(16);

        gridLayout_3->addWidget(limitedSlider, 4, 1, 1, 2);

        spinBox_5 = new QSpinBox(secondaryWidget);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));
        spinBox_5->setMinimumSize(QSize(40, 0));
        spinBox_5->setMaximumSize(QSize(40, 16777215));

        gridLayout_3->addWidget(spinBox_5, 5, 3, 1, 1);

        label_6 = new QLabel(secondaryWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_6, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        radioButton_3 = new QRadioButton(secondaryWidget);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(radioButton_3->sizePolicy().hasHeightForWidth());
        radioButton_3->setSizePolicy(sizePolicy3);
        radioButton_3->setMinimumSize(QSize(60, 20));

        horizontalLayout_4->addWidget(radioButton_3);


        gridLayout_3->addLayout(horizontalLayout_4, 1, 1, 1, 1);

        label_11 = new QLabel(secondaryWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_11, 3, 0, 1, 1);

        radioButton_2 = new QRadioButton(secondaryWidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        sizePolicy3.setHeightForWidth(radioButton_2->sizePolicy().hasHeightForWidth());
        radioButton_2->setSizePolicy(sizePolicy3);
        radioButton_2->setMinimumSize(QSize(80, 20));

        gridLayout_3->addWidget(radioButton_2, 1, 2, 1, 2);

        limitSpinBox = new QSpinBox(secondaryWidget);
        limitSpinBox->setObjectName(QString::fromUtf8("limitSpinBox"));
        limitSpinBox->setMinimum(-63);
        limitSpinBox->setMaximum(63);

        gridLayout_3->addWidget(limitSpinBox, 4, 3, 1, 1);

        label_4 = new QLabel(secondaryWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_4, 7, 0, 1, 1);

        label_8 = new QLabel(secondaryWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_8, 0, 0, 1, 1);

        horizontalSlider_2 = new QSlider(secondaryWidget);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setMinimumSize(QSize(0, 20));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_2->setTickInterval(16);

        gridLayout_3->addWidget(horizontalSlider_2, 7, 1, 1, 2);

        patchComboBox = new QComboBox(secondaryWidget);
        patchComboBox->setObjectName(QString::fromUtf8("patchComboBox"));
        patchComboBox->setMinimumSize(QSize(0, 20));

        gridLayout_3->addWidget(patchComboBox, 2, 1, 1, 3);

        spinBox_2 = new QSpinBox(secondaryWidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setMinimumSize(QSize(40, 0));
        spinBox_2->setMaximumSize(QSize(40, 16777215));

        gridLayout_3->addWidget(spinBox_2, 8, 3, 1, 1);

        mainWidget = new QWidget(MixerTest);
        mainWidget->setObjectName(QString::fromUtf8("mainWidget"));
        mainWidget->setGeometry(QRect(50, 280, 268, 251));
        mainWidget->setMinimumSize(QSize(268, 235));
        gridLayout_2 = new QGridLayout(mainWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        mixerTreeWidget = new QTreeWidget(mainWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        mixerTreeWidget->setHeaderItem(__qtreewidgetitem);
        mixerTreeWidget->setObjectName(QString::fromUtf8("mixerTreeWidget"));
        mixerTreeWidget->setMinimumSize(QSize(300, 0));
        mixerTreeWidget->setMaximumSize(QSize(16777215, 16777215));
        mixerTreeWidget->setFocusPolicy(Qt::StrongFocus);
        mixerTreeWidget->setTabKeyNavigation(true);
        mixerTreeWidget->setSelectionBehavior(QAbstractItemView::SelectItems);

        gridLayout_2->addWidget(mixerTreeWidget, 2, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalButton = new QPushButton(mainWidget);
        verticalButton->setObjectName(QString::fromUtf8("verticalButton"));
        verticalButton->setCheckable(true);

        gridLayout->addWidget(verticalButton, 0, 1, 1, 1);

        showDetailsButton = new QPushButton(mainWidget);
        showDetailsButton->setObjectName(QString::fromUtf8("showDetailsButton"));
        showDetailsButton->setCheckable(true);
        showDetailsButton->setChecked(false);

        gridLayout->addWidget(showDetailsButton, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 1);

        columnToggle = new QPushButton(mainWidget);
        columnToggle->setObjectName(QString::fromUtf8("columnToggle"));
        columnToggle->setCheckable(true);

        gridLayout->addWidget(columnToggle, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        secondaryCheckBox = new QCheckBox(mainWidget);
        secondaryCheckBox->setObjectName(QString::fromUtf8("secondaryCheckBox"));

        gridLayout_2->addWidget(secondaryCheckBox, 0, 0, 1, 1);

        QWidget::setTabOrder(mixerTreeWidget, columnToggle);
        QWidget::setTabOrder(columnToggle, verticalButton);
        QWidget::setTabOrder(verticalButton, showDetailsButton);
        QWidget::setTabOrder(showDetailsButton, smartQ);
        QWidget::setTabOrder(smartQ, radioButton_3);
        QWidget::setTabOrder(radioButton_3, radioButton_2);
        QWidget::setTabOrder(radioButton_2, patchComboBox);
        QWidget::setTabOrder(patchComboBox, limitedSlider);
        QWidget::setTabOrder(limitedSlider, limitSpinBox);
        QWidget::setTabOrder(limitSpinBox, spinBox);
        QWidget::setTabOrder(spinBox, spinBox_5);
        QWidget::setTabOrder(spinBox_5, horizontalSlider);
        QWidget::setTabOrder(horizontalSlider, horizontalSlider_2);
        QWidget::setTabOrder(horizontalSlider_2, spinBox_4);

        retranslateUi(MixerTest);

        QMetaObject::connectSlotsByName(MixerTest);
    } // setupUi

    void retranslateUi(QDialog *MixerTest)
    {
        MixerTest->setWindowTitle(QApplication::translate("MixerTest", "Mixer Test", nullptr));
#ifndef QT_NO_WHATSTHIS
        secondaryWidget->setWhatsThis(QApplication::translate("MixerTest", "Mixer Details", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        secondaryWidget->setAccessibleName(QApplication::translate("MixerTest", "Mixer Tea Details", nullptr));
#endif // QT_NO_ACCESSIBILITY
        label_2->setText(QApplication::translate("MixerTest", "Channel:", nullptr));
        label_10->setText(QApplication::translate("MixerTest", "Pan:", nullptr));
        label->setText(QApplication::translate("MixerTest", "Ports:", nullptr));
        label_9->setText(QApplication::translate("MixerTest", "Alt Slider", nullptr));
        toolButton->setText(QApplication::translate("MixerTest", "Pan", nullptr));
        label_3->setText(QApplication::translate("MixerTest", "Reverb:", nullptr));
        label_5->setText(QApplication::translate("MixerTest", "Patch:", nullptr));
        smartQ->setText(QApplication::translate("MixerTest", "\"Hello\" ", nullptr));
        label_7->setText(QApplication::translate("MixerTest", "Pan", nullptr));
        label_6->setText(QApplication::translate("MixerTest", "Style:", nullptr));
        radioButton_3->setText(QApplication::translate("MixerTest", "Drumset", nullptr));
        label_11->setText(QApplication::translate("MixerTest", "Chorus", nullptr));
        radioButton_2->setText(QApplication::translate("MixerTest", "Instrument", nullptr));
        label_4->setText(QApplication::translate("MixerTest", "Chorus", nullptr));
        label_8->setText(QApplication::translate("MixerTest", "Smart Q", nullptr));
#ifndef QT_NO_WHATSTHIS
        mainWidget->setWhatsThis(QApplication::translate("MixerTest", "Mixer Tree", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        mainWidget->setAccessibleName(QApplication::translate("MixerTest", "Mixer Tea Tree", nullptr));
#endif // QT_NO_ACCESSIBILITY
        verticalButton->setText(QApplication::translate("MixerTest", "Position", nullptr));
        showDetailsButton->setText(QApplication::translate("MixerTest", "Detail", nullptr));
        columnToggle->setText(QApplication::translate("MixerTest", "Columns", nullptr));
        secondaryCheckBox->setText(QApplication::translate("MixerTest", "Secondary Slider", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MixerTest: public Ui_MixerTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MIXERTEST_H
