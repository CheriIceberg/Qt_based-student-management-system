#include "QtWidgetsApplication.h"
#include <QtWidgets/QApplication>
#include "createSubDialog.h"
#include "delSubDialog.h"
#include "searchSubDialog.h"
#include "globalState.h"
#include "editSubDialog.h"


QtWidgetsApplication::QtWidgetsApplication(QWidget* parent)
    : QWidget(parent)
{
    /*
    构造函数对ui界面进行初始化
    */
    //ui.setupUi(this);
    this->resize(960, 540);
    this->setWindowIcon(QIcon(":/new/pictures/address-book-regular.svg"));
    QPainter painter(this);
    painter.drawPixmap(QRect(), QPixmap(":/new/pictures/windowbg.jpeg"));
    /*
    * 添加背景的另一实现
    QPalette pal = this->palette();
    pal.setBrush(QPalette::Background, QBrush(QPixmap(":/new/pictures/windowbg.jpeg")));
    setPalette(pal);*/
    setWindowTitle(coder->toUnicode("学生信息管理系统"));
    createButton = new QPushButton(coder->toUnicode("添加"), this);
    delButton = new QPushButton(coder->toUnicode("删除"), this);
    searchButton = new QPushButton(coder->toUnicode("查询"), this);
    editButton = new QPushButton(coder->toUnicode("更改"), this);
    printButton = new QPushButton(coder->toUnicode("打印表格"), this);
    quitButton = new QPushButton(coder->toUnicode("退出程序"), this);
    numRank = new QPushButton(coder->toUnicode("学号排序"),this);
    nameRank = new QPushButton(coder->toUnicode("显示全部"),this);
    /*
    * 设置透明度的另一实现
    QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect;
    creatButton->setGraphicsEffect(opacityEffect);
    opacityEffect->setOpacity(0.5);*/
    QIcon create, del, search, edit, rank, print, quit,namerank;
    create.addFile(tr(":/new/pictures/creat.svg"));
    del.addFile(tr(":/new/pictures/delete.svg"));
    search.addFile(tr(":/new/pictures/magnifying-glass-solid.svg"));
    edit.addFile(tr(":/new/pictures/edit.svg"));
    rank.addFile(tr(":/new/pictures/rank.svg"));
    print.addFile(tr(":/new/pictures/print-solid.svg"));
    quit.addFile(tr(":/new/pictures/quit.svg"));
    namerank.addFile(tr(":/new/pictures/neprint.svg"));
    createButton->setIcon(create);
    delButton->setIcon(del);
    searchButton->setIcon(search);
    editButton->setIcon(edit);
    nameRank->setIcon(namerank);
    numRank->setIcon(rank);
    printButton->setIcon(print);
    quitButton->setIcon(quit);
    //设置按钮透明度
    createButton->setStyleSheet("background-color:rgba(225,225,225,0.7);");
    delButton->setStyleSheet("background-color:rgba(225,225,225,0.7);");
    searchButton->setStyleSheet("background-color:rgba(225,225,225,0.7);");
    editButton->setStyleSheet("background-color:rgba(225,225,225,0.7);");
    nameRank->setStyleSheet("background-color:rgba(225,225,225,0.7);");
    numRank->setStyleSheet("background-color:rgba(225,225,225,0.7);");
    printButton->setStyleSheet("background-color:rgba(225,225,225,0.7);");
    quitButton->setStyleSheet("background-color:rgba(225,225,225,0.7);");
    //设置按钮大小
    createButton->setMaximumSize(QSize(120, 30));
    delButton->setMaximumSize(QSize(120, 30));
    searchButton->setMaximumSize(QSize(120, 30));
    editButton->setMaximumSize(QSize(120, 30));
    printButton->setMaximumSize(QSize(120, 30));
    quitButton->setMaximumSize(QSize(120, 30));
    numRank->setMaximumSize(QSize(120, 30));
    nameRank->setMaximumSize(QSize(120, 30));
    tableView = new QTableView(this);
    tableModel = new QStandardItemModel();
    verticalLayout = new QVBoxLayout(this);
    gridLayout3 = new QGridLayout();
    horizontalSpacer1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    gridLayout3->addItem(horizontalSpacer1, 0, 0, 1, 1);
    tableView->setWindowTitle(coder->toUnicode("学生信息"));
    tableView->setMinimumSize(QSize(740, 0));//设置表格宽度
    tableView->setMaximumSize(QSize(740, 1080));
    //设置表格头
    tableModel->setHorizontalHeaderItem(0, new QStandardItem(coder->toUnicode("学号")));
    tableModel->setHorizontalHeaderItem(1, new QStandardItem(coder->toUnicode("姓名")));
    tableModel->setHorizontalHeaderItem(2, new QStandardItem(coder->toUnicode("电话")));
    tableModel->setHorizontalHeaderItem(3, new QStandardItem(coder->toUnicode("学院")));
    tableView->setModel(tableModel);
    tableView->setLineWidth(30);
    //固定表格列宽
    tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    //设置表格列宽
    tableView->setColumnWidth(0, 200);
    tableView->setColumnWidth(1, 100);
    tableView->setColumnWidth(2, 200);
    tableView->setColumnWidth(3, 200);
    tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;color: black;}");//增加表头格式
    tableView->setStyleSheet("background:transparent;border-width:0;border-style:outset");
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//取消表格可可编辑
    tableView->setAlternatingRowColors(true);//设置隔行变色
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中
    gridLayout3->addWidget(tableView, 0, 1, 1, 1);
    horizontalSpacer2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    gridLayout3->addItem(horizontalSpacer2, 0, 2, 1, 1);
    verticalLayout->addLayout(gridLayout3);
    verticalSpacer2 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Preferred);
    verticalLayout->addItem(verticalSpacer2);
    gridLayout1 = new QGridLayout();
    gridLayout1->addWidget(editButton, 0, 3, 1, 1);
    gridLayout1->addWidget(createButton, 0, 0, 1, 1);
    gridLayout1->addWidget(delButton, 0, 1, 1, 1);
    gridLayout1->addWidget(searchButton, 0, 2, 1, 1);
    verticalLayout->addLayout(gridLayout1);
    verticalSpacer1 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Preferred);
    verticalLayout->addItem(verticalSpacer1);
    gridLayout2 = new QGridLayout();
    gridLayout2->addWidget(nameRank, 0, 1, 1, 1);
    gridLayout2->addWidget(numRank, 0, 0, 1, 1);
    gridLayout2->addWidget(printButton, 0, 2, 1, 1);
    gridLayout2->addWidget(quitButton, 0, 3, 1, 1);
    verticalLayout->addLayout(gridLayout2);

    //信号于槽函数连接
    connect(createButton, SIGNAL(clicked(void)), this, SLOT(createStu(void)));
    connect(delButton, SIGNAL(clicked(void)), this, SLOT(delStu(void)));
    connect(quitButton, SIGNAL(clicked(void)), this, SLOT(closeAll(void)));
    connect(searchButton, SIGNAL(clicked(void)), this, SLOT(searchStu(void)));
    connect(nameRank, SIGNAL(clicked(void)), this, SLOT(showAllStu(void)));
    connect(editButton, SIGNAL(clicked(void)), this, SLOT(editStu(void)));
    connect(numRank, SIGNAL(clicked(void)), this, SLOT(num_Rank(void)));
    connect(printButton, SIGNAL(clicked(void)), this, SLOT(showStuExcel(void)));
}

//重写绘画事件，添加背景
void QtWidgetsApplication::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.drawPixmap(rect(), QPixmap(":/new/pictures/windowbg.jpeg"), QRect());
}


//添加学生信息窗口
void QtWidgetsApplication::createStu(void)
{
    createSubDialog* subCreate = new createSubDialog(this);
    subCreate->setModal(true);

    subCreate->show();

}


//关闭程序
void QtWidgetsApplication::closeAll(void)
{
    close();
}


//删除信息窗口
void QtWidgetsApplication::delStu(void)
{
    if (stuNum == 0)
    {
        QMessageBox::information(this, coder->toUnicode("提示"), coder->toUnicode("信息为空！"), QMessageBox::Ok, QMessageBox::Ok);
        return;
    }
    delSubDialog* delDialog = new delSubDialog(this);
    delDialog->setModal(true);

    delDialog->show();
}


//查找窗口
void QtWidgetsApplication::searchStu(void)
{
    if (stuNum == 0)
    {
        QMessageBox::information(this, coder->toUnicode("提示"), coder->toUnicode("信息为空！"), QMessageBox::Ok, QMessageBox::Ok);
        return;
    }
    searchSubDialog* searchDialog = new searchSubDialog(this);
    searchDialog->setModal(true);

    searchDialog->show();
}


//删除显示的信息
void QtWidgetsApplication::delAllTable()
{
    
    int i = 0, j = stuNum;
    if (stuNum == 1)
    {
        tableModel->removeRow(0);
    }
    else
    {
        tableModel->removeRows(0, tableModel->rowCount());
        /*for (i = 0; i < j; --j)
        {
            tableModel->removeRows(0, tableModel->rowCount());
        }*/
    }
}

//显示所有学生信息
void QtWidgetsApplication::showAllStu()
{
    delAllTable();
    int i = 0;
    PLinkNode temp = new LinkNode;
    temp = head;
    if (stuNum == 0)
    {
        QMessageBox::information(this, coder->toUnicode("提示"), coder->toUnicode("信息为空！"), QMessageBox::Ok, QMessageBox::Ok);
        return;
    }
    for (i = 0; i < stuNum; ++i)
    {
        /*tableModel->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        tableModel->item(i, 1)->setTextAlignment(Qt::AlignCenter);
        tableModel->item(i, 2)->setTextAlignment(Qt::AlignCenter);
        tableModel->item(i, 3)->setTextAlignment(Qt::AlignCenter);*/
        tableModel->setItem(i, 0, new QStandardItem(ScQ->str2qstr(temp->num)));
        tableModel->setItem(i, 1, new QStandardItem(ScQ->str2qstr(temp->name)));
        tableModel->setItem(i, 2, new QStandardItem(ScQ->str2qstr(temp->tele)));
        tableModel->setItem(i, 3, new QStandardItem(ScQ->str2qstr(temp->major)));
        temp = temp->next;
    }
    delete temp;
}

void QtWidgetsApplication::showAllTable()
{
    int i = 0;
    PLinkNode temp = new LinkNode;
    temp = head;
    for (i = 0; i < stuNum; ++i)
    {
        /*tableModel->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        tableModel->item(i, 1)->setTextAlignment(Qt::AlignCenter);
        tableModel->item(i, 2)->setTextAlignment(Qt::AlignCenter);
        tableModel->item(i, 3)->setTextAlignment(Qt::AlignCenter);*/
        tableModel->setItem(i, 0, new QStandardItem(ScQ->str2qstr(temp->num)));
        tableModel->setItem(i, 1, new QStandardItem(ScQ->str2qstr(temp->name)));
        tableModel->setItem(i, 2, new QStandardItem(ScQ->str2qstr(temp->tele)));
        tableModel->setItem(i, 3, new QStandardItem(ScQ->str2qstr(temp->major)));
        temp = temp->next;
    }
}

//修改窗口
void QtWidgetsApplication::editStu(void)
{
    if (stuNum == 0)
    {
        QMessageBox::information(this, coder->toUnicode("提示"), coder->toUnicode("信息为空！"), QMessageBox::Ok, QMessageBox::Ok);
        return;
    }
    editSubDialog* editDialog = new editSubDialog(this);
    editDialog->setModal(true);

    editDialog->show();
}

//按学号排序
void QtWidgetsApplication::num_Rank(void)
{
    if (stuNum == 0)
    {
        QMessageBox::warning(this, coder->toUnicode("提示"), coder->toUnicode("信息为空！"), QMessageBox::Ok, QMessageBox::Ok);
        return;
    }
    int i, j;
    bool flag;
    PLinkNode temp = head;
    for (int i = 1; i < stuNum; ++i)
    {
        flag = false;
        temp = head;
        for (j = 0; j < stuNum - i; ++j)
        {
            if (temp->num > temp->next->num)
            {
                swap(temp->num, temp->next->num);
                swap(temp->name, temp->next->name);
                swap(temp->tele, temp->next->tele);
                swap(temp->major, temp->next->major);
                flag = true;
            }
        }
    }
    QMessageBox::information(this, coder->toUnicode("提示"), coder->toUnicode("排序成功！"), QMessageBox::Ok, QMessageBox::Ok);
    delAllTable();
    showAllTable();
    /*delAllTable();
    showAllTable();*/
}