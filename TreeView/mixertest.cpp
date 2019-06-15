#include "mixertest.h"
#include "ui_mixertest.h"
#include <QFile>
#include "treemodel.h"
#include <QTreeView>
#include <QPushButton>
#include <QAbstractButton>

MixerTest::MixerTest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MixerTest)
{
    ui->setupUi(this);

    QFile file(":/default.txt");
    file.open(QIODevice::ReadOnly);
    TreeModel* model = new TreeModel(file.readAll());
    file.close();

    ui->mixerTree->setModel(model);
   // ui->mixerTree->show();

    ui->testField->setText("Check One");
}

MixerTest::~MixerTest()
{
    delete ui;
}

void MixerTest::on_buttonBox_clicked(QAbstractButton *button)
{
    QPushButton* push = static_cast<QPushButton*>(button);

    if(push == ui->buttonBox->button(QDialogButtonBox::Reset) ){
        qDebug("Reset button clicked");
        return;
    }

    if(push == ui->buttonBox->button(QDialogButtonBox::RestoreDefaults) ){
        qDebug("Restore Defaults button clicked");
        return;
    }

}
