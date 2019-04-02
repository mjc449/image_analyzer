#include "image_analyzer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    image_analyzer w;
    w.show();
    return a.exec();
}
