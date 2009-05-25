#include <QtGui/QApplication>

#include "model.h"
#include "maindialog.h"
#include "controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model      model;
    MainDialog view;
    Controller controller(&view, &model);
    controller.Start();
    return a.exec();
}
