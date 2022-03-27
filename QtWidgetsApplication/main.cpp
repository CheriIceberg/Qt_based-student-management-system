#include "QtWidgetsApplication.h"
#include "createSubDialog.h"
#include <QtWidgets/QApplication>
#include "globalState.h"


int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    QtWidgetsApplication* w = new QtWidgetsApplication();
    //w.setWindowTitle("学生信息管理系统");
    
    w->show();
    return a.exec();
}
