#include "QtWidgetsApplication1.h"
#include "LoggingCategories.h"

QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    connect(ui.pushButton,   SIGNAL(clicked()), this, SLOT(ClickedSlot()));
    connect(ui.pushButton_1, SIGNAL(clicked()), this, SLOT(RepeatText()));
    connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(StickingButton()));

    //This line makes the button "sticky"
    // 
    //ui.pushButton_2->setCheckable(true);

    connect(ui.pushButton,   SIGNAL(clicked()), this, SLOT(InfoButton1()));
    connect(ui.pushButton_1, SIGNAL(clicked()), this, SLOT(InfoButton2()));
    connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(DebugButton()));
}

QtWidgetsApplication1::~QtWidgetsApplication1()
{}

void QtWidgetsApplication1::ClickedSlot()
{
    ui.lineEdit->setText("Some text");
}

void QtWidgetsApplication1::RepeatText()
{
    QString inputText = ui.lineEdit_1->text();

    if (inputText.isEmpty())
    {
        ui.lineEdit->setText("The field is empty");
    }
    else
    {
        ui.lineEdit->setText(inputText);
    }
}

void QtWidgetsApplication1::StickingButton()
{
    if (!ui.pushButton_2->isChecked())
    {
        ui.pushButton_2->setDown(true);
    }
}

void QtWidgetsApplication1::InfoButton1()
{
    qInfo(SomeText()) << "Info";
}

void QtWidgetsApplication1::InfoButton2()
{
    qInfo(Repeat()) << "Info";
}

void QtWidgetsApplication1::DebugButton()
{
    qDebug(Sticking()) << "Debug";
}