#include "globalState.h"
#include "QtWidgetsApplication.h"
#include "editSubDialog.h"


editSubDialog::editSubDialog(QWidget* parent) :QDialog(parent)
{
	this->setWindowTitle(coder->toUnicode("编辑信息"));
	this->setWindowIcon(QIcon(":/new/pictures/edit.svg"));
    verticalLayout = new QVBoxLayout(this);
    gridLayout_10 = new QGridLayout();
    gridLayout_8 = new QGridLayout();
    gridLayout_2 = new QGridLayout();
    preNameLine = new QLineEdit(this);
    preNameLine->setMaximumSize(QSize(150, 23));
    gridLayout_2->addWidget(preNameLine, 1, 1, 1, 1);
    preNameLabel = new QLabel(coder->toUnicode("姓名："),this);
    gridLayout_2->addWidget(preNameLabel, 1, 0, 1, 1);
    preMessage = new QLabel(coder->toUnicode("任选一项进行搜索"),this);
    preMessage->setMaximumSize(QSize(200, 30));
    gridLayout_2->addWidget(preMessage, 0, 1, 1, 1);
    gridLayout_8->addLayout(gridLayout_2, 0, 0, 1, 1);
    gridLayout = new QGridLayout();
    preNumLabel = new QLabel(coder->toUnicode("学号："),this);
    gridLayout->addWidget(preNumLabel, 0, 0, 1, 1);
    preNumLine = new QLineEdit(this);
    preNumLine->setMaximumSize(QSize(150, 23));
    gridLayout->addWidget(preNumLine, 0, 1, 1, 1);
    gridLayout_8->addLayout(gridLayout, 1, 0, 1, 1);
    gridLayout_10->addLayout(gridLayout_8, 0, 0, 1, 1);
    gridLayout_7 = new QGridLayout();
    gridLayout_6 = new QGridLayout();
    editMajor = new QLabel(coder->toUnicode("学院："),this);
    gridLayout_6->addWidget(editMajor, 0, 0, 1, 1);
    majorLine = new QLineEdit(this);
    majorLine->setMaximumSize(QSize(150, 30));
    gridLayout_6->addWidget(majorLine, 0, 1, 1, 1);
    gridLayout_7->addLayout(gridLayout_6, 3, 0, 1, 1);
    gridLayout_4 = new QGridLayout();
    editNum = new QLabel(coder->toUnicode("学号："),this);
    gridLayout_4->addWidget(editNum, 0, 0, 1, 1);
    numLine = new QLineEdit(this);
    numLine->setMaximumSize(QSize(150, 30));
    gridLayout_4->addWidget(numLine, 0, 1, 1, 1);
    gridLayout_7->addLayout(gridLayout_4, 1, 0, 1, 1);
    gridLayout_3 = new QGridLayout();
    nameLine = new QLineEdit(this);
    nameLine->setMaximumSize(QSize(150, 30));
    gridLayout_3->addWidget(nameLine, 1, 1, 1, 1);
    editName = new QLabel(coder->toUnicode("姓名："),this);
    gridLayout_3->addWidget(editName, 1, 0, 1, 1);
    editMessage = new QLabel(coder->toUnicode("要修改的信息"),this);
    editMessage->setMaximumSize(QSize(200, 30));
    gridLayout_3->addWidget(editMessage, 0, 1, 1, 1);
    gridLayout_7->addLayout(gridLayout_3, 0, 0, 1, 1);
    gridLayout_5 = new QGridLayout();
    editTel = new QLabel(coder->toUnicode("电话："),this);
    gridLayout_5->addWidget(editTel, 0, 0, 1, 1);
    telLine = new QLineEdit(this);
    telLine->setMaximumSize(QSize(150, 30));
    gridLayout_5->addWidget(telLine, 0, 1, 1, 1);
    gridLayout_7->addLayout(gridLayout_5, 2, 0, 1, 1);
    gridLayout_10->addLayout(gridLayout_7, 0, 1, 1, 1);
    verticalLayout->addLayout(gridLayout_10);
    gridLayout_9 = new QGridLayout();
    confirmBtn = new QPushButton(coder->toUnicode("确认"),this);
    confirmBtn->setMaximumSize(QSize(120, 30));
    gridLayout_9->addWidget(confirmBtn, 0, 0, 1, 1);
    cancelBtn = new QPushButton(coder->toUnicode("取消"),this);
    cancelBtn->setMaximumSize(QSize(120, 30));
    gridLayout_9->addWidget(cancelBtn, 0, 1, 1, 1);
    verticalLayout->addLayout(gridLayout_9);
    flag = 0;

    connect(cancelBtn, SIGNAL(clicked(void)), this, SLOT(cancelEdit(void)));
    connect(confirmBtn, SIGNAL(clicked(void)), this, SLOT(confirmEdit(void)));
    connect(preNumLine, SIGNAL(textChanged(QString)), this, SLOT(enableNum(void)));
    connect(preNameLine, SIGNAL(textChanged(QString)), this, SLOT(enableName(void)));
}

void editSubDialog::confirmEdit()
{
    QtWidgetsApplication* ptrMain = (QtWidgetsApplication*)parentWidget();
    PLinkNode temp = new LinkNode;
    temp = head;
    if (flag == 1)//查姓名更改
    {
        while (temp != nullptr)
        {
            if (temp->name == QcS->qstr2str(preNameLine->text()))
            {
                
                if (nameLine->text() != "") temp->name = QcS->qstr2str(nameLine->text());
                if (numLine->text() != "") temp->num = QcS->qstr2str(numLine->text());
                if (telLine->text() != "") temp->tele = QcS->qstr2str(telLine->text());
                if (majorLine->text() != "") temp->major = QcS->qstr2str(majorLine->text());
                close();
                QMessageBox::information(NULL, coder->toUnicode("提示"), coder->toUnicode("修改成功！"), QMessageBox::Ok, QMessageBox::Ok);
                ptrMain->delAllTable();
                ptrMain->showAllTable();
                return;
            }
            temp = temp->next;
        }
        close();
        QMessageBox::warning(this, coder->toUnicode("提示"), coder->toUnicode("未查找到此信息"), QMessageBox::Ok, QMessageBox::Ok);
    }
    else if (flag == 2)
    {
        while (temp != nullptr)
        {
            if (temp->num ==preNumLine->text().toStdString())
            {
                
                if (nameLine->text() != "") temp->name = QcS->qstr2str(nameLine->text());
                if (numLine->text() != "") temp->num = QcS->qstr2str(numLine->text());
                if (telLine->text() != "") temp->tele = QcS->qstr2str(telLine->text());
                if (majorLine->text() != "") temp->major = QcS->qstr2str(majorLine->text());
                close();
                QMessageBox::information(NULL, coder->toUnicode("提示"), coder->toUnicode("修改成功！"), QMessageBox::Ok, QMessageBox::Ok);
                ptrMain->delAllTable();
                ptrMain->showAllTable();

                return;
            }
            temp = temp->next;
        }
        close();
        QMessageBox::warning(this, coder->toUnicode("提示"), coder->toUnicode("未查找到此信息"), QMessageBox::Ok, QMessageBox::Ok);
    }
}

void editSubDialog::cancelEdit()
{
    close();
}

void editSubDialog::enableName()
{
    preNameLine->setEnabled(true);
    preNumLine->setEnabled(false);
    flag = 1;
}

void editSubDialog::enableNum()
{
    preNameLine->setEnabled(false);
    preNumLine->setEnabled(true);
    flag = 2;
}