#include "QtWidgetsApplication.h"
#include "createSubDialog.h"
#include <QtWidgets/QApplication>
#include "globalState.h"


int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    QtWidgetsApplication* w = new QtWidgetsApplication();
    //w.setWindowTitle("ѧ����Ϣ����ϵͳ");
    
    w->show();
    return a.exec();
}
