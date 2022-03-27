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
    ���캯����ui������г�ʼ��
    */
    //ui.setupUi(this);
    this->resize(960, 540);
    this->setWindowIcon(QIcon(":/new/pictures/address-book-regular.svg"));
    QPainter painter(this);
    painter.drawPixmap(QRect(), QPixmap(":/new/pictures/windowbg.jpeg"));
    /*
    * ��ӱ�������һʵ��
    QPalette pal = this->palette();
    pal.setBrush(QPalette::Background, QBrush(QPixmap(":/new/pictures/windowbg.jpeg")));
    setPalette(pal);*/
    setWindowTitle(coder->toUnicode("ѧ����Ϣ����ϵͳ"));
    createButton = new QPushButton(coder->toUnicode("���"), this);
    delButton = new QPushButton(coder->toUnicode("ɾ��"), this);
    searchButton = new QPushButton(coder->toUnicode("��ѯ"), this);
    editButton = new QPushButton(coder->toUnicode("����"), this);
    printButton = new QPushButton(coder->toUnicode("��ӡ���"), this);
    quitButton = new QPushButton(coder->toUnicode("�˳�����"), this);
    numRank = new QPushButton(coder->toUnicode("ѧ������"),this);
    nameRank = new QPushButton(coder->toUnicode("��ʾȫ��"),this);
    /*
    * ����͸���ȵ���һʵ��
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
    //���ð�ť͸����
    createButton->setStyleSheet("background-color:rgba(225,225,225,0.7);");
    delButton->setStyleSheet("background-color:rgba(225,225,225,0.7);");
    searchButton->setStyleSheet("background-color:rgba(225,225,225,0.7);");
    editButton->setStyleSheet("background-color:rgba(225,225,225,0.7);");
    nameRank->setStyleSheet("background-color:rgba(225,225,225,0.7);");
    numRank->setStyleSheet("background-color:rgba(225,225,225,0.7);");
    printButton->setStyleSheet("background-color:rgba(225,225,225,0.7);");
    quitButton->setStyleSheet("background-color:rgba(225,225,225,0.7);");
    //���ð�ť��С
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
    tableView->setWindowTitle(coder->toUnicode("ѧ����Ϣ"));
    tableView->setMinimumSize(QSize(740, 0));//���ñ����
    tableView->setMaximumSize(QSize(740, 1080));
    //���ñ��ͷ
    tableModel->setHorizontalHeaderItem(0, new QStandardItem(coder->toUnicode("ѧ��")));
    tableModel->setHorizontalHeaderItem(1, new QStandardItem(coder->toUnicode("����")));
    tableModel->setHorizontalHeaderItem(2, new QStandardItem(coder->toUnicode("�绰")));
    tableModel->setHorizontalHeaderItem(3, new QStandardItem(coder->toUnicode("ѧԺ")));
    tableView->setModel(tableModel);
    tableView->setLineWidth(30);
    //�̶�����п�
    tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    //���ñ���п�
    tableView->setColumnWidth(0, 200);
    tableView->setColumnWidth(1, 100);
    tableView->setColumnWidth(2, 200);
    tableView->setColumnWidth(3, 200);
    tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;color: black;}");//���ӱ�ͷ��ʽ
    tableView->setStyleSheet("background:transparent;border-width:0;border-style:outset");
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//ȡ�����ɿɱ༭
    tableView->setAlternatingRowColors(true);//���ø��б�ɫ
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);//����ѡ��
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

    //�ź��ڲۺ�������
    connect(createButton, SIGNAL(clicked(void)), this, SLOT(createStu(void)));
    connect(delButton, SIGNAL(clicked(void)), this, SLOT(delStu(void)));
    connect(quitButton, SIGNAL(clicked(void)), this, SLOT(closeAll(void)));
    connect(searchButton, SIGNAL(clicked(void)), this, SLOT(searchStu(void)));
    connect(nameRank, SIGNAL(clicked(void)), this, SLOT(showAllStu(void)));
    connect(editButton, SIGNAL(clicked(void)), this, SLOT(editStu(void)));
    connect(numRank, SIGNAL(clicked(void)), this, SLOT(num_Rank(void)));
    connect(printButton, SIGNAL(clicked(void)), this, SLOT(showStuExcel(void)));
}

//��д�滭�¼�����ӱ���
void QtWidgetsApplication::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.drawPixmap(rect(), QPixmap(":/new/pictures/windowbg.jpeg"), QRect());
}


//���ѧ����Ϣ����
void QtWidgetsApplication::createStu(void)
{
    createSubDialog* subCreate = new createSubDialog(this);
    subCreate->setModal(true);

    subCreate->show();

}


//�رճ���
void QtWidgetsApplication::closeAll(void)
{
    close();
}


//ɾ����Ϣ����
void QtWidgetsApplication::delStu(void)
{
    if (stuNum == 0)
    {
        QMessageBox::information(this, coder->toUnicode("��ʾ"), coder->toUnicode("��ϢΪ�գ�"), QMessageBox::Ok, QMessageBox::Ok);
        return;
    }
    delSubDialog* delDialog = new delSubDialog(this);
    delDialog->setModal(true);

    delDialog->show();
}


//���Ҵ���
void QtWidgetsApplication::searchStu(void)
{
    if (stuNum == 0)
    {
        QMessageBox::information(this, coder->toUnicode("��ʾ"), coder->toUnicode("��ϢΪ�գ�"), QMessageBox::Ok, QMessageBox::Ok);
        return;
    }
    searchSubDialog* searchDialog = new searchSubDialog(this);
    searchDialog->setModal(true);

    searchDialog->show();
}


//ɾ����ʾ����Ϣ
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

//��ʾ����ѧ����Ϣ
void QtWidgetsApplication::showAllStu()
{
    delAllTable();
    int i = 0;
    PLinkNode temp = new LinkNode;
    temp = head;
    if (stuNum == 0)
    {
        QMessageBox::information(this, coder->toUnicode("��ʾ"), coder->toUnicode("��ϢΪ�գ�"), QMessageBox::Ok, QMessageBox::Ok);
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

//�޸Ĵ���
void QtWidgetsApplication::editStu(void)
{
    if (stuNum == 0)
    {
        QMessageBox::information(this, coder->toUnicode("��ʾ"), coder->toUnicode("��ϢΪ�գ�"), QMessageBox::Ok, QMessageBox::Ok);
        return;
    }
    editSubDialog* editDialog = new editSubDialog(this);
    editDialog->setModal(true);

    editDialog->show();
}

//��ѧ������
void QtWidgetsApplication::num_Rank(void)
{
    if (stuNum == 0)
    {
        QMessageBox::warning(this, coder->toUnicode("��ʾ"), coder->toUnicode("��ϢΪ�գ�"), QMessageBox::Ok, QMessageBox::Ok);
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
    QMessageBox::information(this, coder->toUnicode("��ʾ"), coder->toUnicode("����ɹ���"), QMessageBox::Ok, QMessageBox::Ok);
    delAllTable();
    showAllTable();
    /*delAllTable();
    showAllTable();*/
}