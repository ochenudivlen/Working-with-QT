#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication1.h"
#include <QPushButton>

class QtWidgetsApplication1 : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication1(QWidget *parent = nullptr);
    ~QtWidgetsApplication1();

private:
    Ui::QtWidgetsApplication1Class ui;

private slots:
    void ClickedSlot();
    void RepeatText();
    void StickingButton();

    void InfoButton1();
    void InfoButton2();
    void DebugButton();
};
