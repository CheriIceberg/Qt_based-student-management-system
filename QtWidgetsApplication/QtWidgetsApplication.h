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
    QPushButton* createButton;//����ѧ����Ϣ��ť
    QPushButton* delButton;//ɾ��ѧ����Ϣ��ť
    QPushButton* searchButton;//��ѯѧ����Ϣ
    QPushButton* editButton;//����ѧ����Ϣ
    QPushButton* printButton;//��ӡѧ����Ϣ
    QPushButton* quitButton;//�رճ���
    QPushButton* nameRank;//��������
    QPushButton* numRank;//ѧ������
    QGridLayout* gridLayout1;
    QGridLayout* gridLayout2;
    QGridLayout* gridLayout3;
    QVBoxLayout* verticalLayout;
    QSpacerItem* verticalSpacer1;
    QSpacerItem* verticalSpacer2;
    QSpacerItem* horizontalSpacer1;
    QSpacerItem* horizontalSpacer2;
    QTableView* tableView;//��ʾѧ����Ϣ���
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
