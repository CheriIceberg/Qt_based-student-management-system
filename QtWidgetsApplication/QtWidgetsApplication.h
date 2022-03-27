#pragma once

#include "ui_QtWidgetsApplication.h"
//#include "globalState.h"
#include <iostream>
#include <string>
#include <QPushButton>
#include <QTextCodec>
#include <QHBoxLayout>
#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QTableView>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QSpacerItem>
#include <QStandardItemModel>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QGraphicsOpacityEffect>
#include <QIcon>
#include <QFileDialog>
#include <QVariant>
#include <QMessageBox>
using namespace std;

class QtWidgetsApplication : public QWidget
{
    Q_OBJECT

public:
    QtWidgetsApplication(QWidget* parent = Q_NULLPTR);
    QTextCodec* coder = QTextCodec::codecForName("gbk");
    QPushButton* createButton;//增加学生信息按钮
    QPushButton* delButton;//删除学生信息按钮
    QPushButton* searchButton;//查询学生信息
    QPushButton* editButton;//更改学生信息
    QPushButton* printButton;//打印学生信息
    QPushButton* quitButton;//关闭程序
    QPushButton* nameRank;//名字排序
    QPushButton* numRank;//学号排序
    QGridLayout* gridLayout1;
    QGridLayout* gridLayout2;
    QGridLayout* gridLayout3;
    QVBoxLayout* verticalLayout;
    QSpacerItem* verticalSpacer1;
    QSpacerItem* verticalSpacer2;
    QSpacerItem* horizontalSpacer1;
    QSpacerItem* horizontalSpacer2;
    QTableView* tableView;//显示学生信息表格
    QStandardItemModel* tableModel;
    void delAllTable();
    void showAllTable();
private:
    Ui::QtWidgetsApplicationClass ui;
    //ui(new Ui::Widget)
protected:
    void paintEvent(QPaintEvent* event);

public slots:
    void createStu(void);
    void delStu(void);
    void closeAll(void);
    void searchStu(void);
    void showAllStu(void);
    void editStu(void);
    void num_Rank(void);
    void showStuExcel(void);
};

//extern QtWidgetsApplication w;
