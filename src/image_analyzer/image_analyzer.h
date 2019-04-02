#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_image_analyzer.h"

class image_analyzer : public QMainWindow
{
    Q_OBJECT

public:
    image_analyzer(QWidget *parent = Q_NULLPTR);

private:
    Ui::image_analyzerClass ui;
};
