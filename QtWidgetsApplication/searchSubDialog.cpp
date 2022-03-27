#include "globalState.h"
#include "QtWidgetsApplication.h"
#include "searchSubDialog.h"
//#include "main.cpp"

searchSubDialog::searchSubDialog(QWidget* parent) :QDialog(parent)
{
	this->setWindowTitle(coder->toUnicode("查找信息"));
	this->setWindowIcon(QIcon(":/new/pictures/magnifying-glass-solid.svg"));
	verticalLayout = new QVBoxLayout(this);
	searchMessage = new QLabel(coder->toUnicode("任选一个查找条件"),this);
	verticalLayout->addWidget(searchMessage);
	gridLayout1 = new QGridLayout();
	nameLabel = new QLabel(coder->toUnicode("姓名："), this);
	gridLayout1->addWidget(nameLabel, 0, 0, 1, 1);
	nameLine = new QLineEdit(this);
	nameLine->setAlignment(Qt::AlignLeft);
	nameLine->setClearButtonEnabled(true);
	nameLine->setMaximumSize(QSize(150, 30));
	gridLayout1->addWidget(nameLine, 0, 1, 1, 1);
	verticalLayout->addLayout(gridLayout1);
	gridLayout2 = new QGridLayout();
	numLabel = new QLabel(coder->toUnicode("学号："), this);
	gridLayout2->addWidget(numLabel, 0, 0, 1, 1);
	numLine = new QLineEdit(this);
	numLine->setAlignment(Qt::AlignLeft);
	numLine->setClearButtonEnabled(true);
	numLine->setMaximumSize(QSize(150, 30));
	gridLayout2->addWidget(numLine, 0, 1, 1, 1);
	verticalLayout->addLayout(gridLayout2);
	gridLayout3 = new QGridLayout();
	telLabel = new QLabel(coder->toUnicode("电话："), this);
	gridLayout3->addWidget(telLabel, 0, 0, 1, 1);
	telLine = new QLineEdit(this);
	telLine->setMaximumSize(QSize(150, 30));
	telLine->setAlignment(Qt::AlignLeft);
	telLine->setClearButtonEnabled(true);
	gridLayout3->addWidget(telLine, 0, 1, 1, 1);
	verticalLayout->addLayout(gridLayout3);
	gridLayout4 = new QGridLayout();
	confirmSearchBtn = new QPushButton(coder->toUnicode("确定"), this);
	confirmSearchBtn->setMaximumSize(QSize(120, 30));
	gridLayout4->addWidget(confirmSearchBtn, 0, 0, 1, 1);
	cancelSearchBtn = new QPushButton(coder->toUnicode("取消"), this);
	cancelSearchBtn->setMaximumSize(QSize(120, 30));
	gridLayout4->addWidget(cancelSearchBtn, 0, 1, 1, 1);
	verticalLayout->addLayout(gridLayout4);
	flag = 0;
	
	


	//槽函数与信号连接
	connect(nameLine, SIGNAL(textChanged(QString)), this, SLOT(enable1()));
	connect(numLine, SIGNAL(textChanged(QString)), this, SLOT(enable2()));
	connect(telLine, SIGNAL(textChanged(QString)), this, SLOT(enable3()));
	connect(cancelSearchBtn, SIGNAL(clicked()), this, SLOT(cancelSearch()));
	connect(confirmSearchBtn, SIGNAL(clicked()), this, SLOT(confirmSearch()));
}

//string QStr2Str::qstr2str(const QString& qstr)
//{
//	QByteArray cdata = qstr.toLocal8Bit();
//	return string(cdata);
//}

void searchSubDialog::cancelSearch()
{
	close();
}

void searchSubDialog::confirmSearch()
{
	if (stuNum == 0)
	{
		QMessageBox::information(NULL, coder->toUnicode("提示"), coder->toUnicode("信息为空！"), QMessageBox::Ok, QMessageBox::Ok);
		return;
	}
	QtWidgetsApplication* ptrMain = (QtWidgetsApplication*)parentWidget();
	PLinkNode temp = new LinkNode;
	temp = head;
	
	if (flag == 1)
	{
		while (temp != nullptr)
		{
			if (temp->name == QcS->qstr2str(nameLine->text()))
			{
				close();
				QMessageBox::information(NULL, coder->toUnicode("提示"), coder->toUnicode("查找成功！"), QMessageBox::Ok, QMessageBox::Ok);
				ptrMain->delAllTable();
				ptrMain->tableModel->setItem(0, 0, new QStandardItem(ScQ->str2qstr(temp->num)));
				ptrMain->tableModel->setItem(0, 1, new QStandardItem(ScQ->str2qstr(temp->name)));
				ptrMain->tableModel->setItem(0, 2, new QStandardItem(ScQ->str2qstr(temp->tele)));
				ptrMain->tableModel->setItem(0, 3, new QStandardItem(ScQ->str2qstr(temp->major)));

				return;
			}
			temp = temp->next;
		}
		close();
		QMessageBox::warning(this, coder->toUnicode("提示"), coder->toUnicode("未查找到此信息"), QMessageBox::Ok, QMessageBox::Ok);
		
	}
	else if (flag == 2)
	{
		while(temp != nullptr)
		{
			if (temp->num == numLine->text().toStdString())
			{
				close();
				QMessageBox::information(NULL, coder->toUnicode("提示"), coder->toUnicode("查找成功！"), QMessageBox::Ok, QMessageBox::Ok);
				ptrMain->delAllTable();
				ptrMain->tableModel->setItem(0, 0, new QStandardItem(ScQ->str2qstr(temp->num)));
				ptrMain->tableModel->setItem(0, 1, new QStandardItem(ScQ->str2qstr(temp->name)));
				ptrMain->tableModel->setItem(0, 2, new QStandardItem(ScQ->str2qstr(temp->tele)));
				ptrMain->tableModel->setItem(0, 3, new QStandardItem(ScQ->str2qstr(temp->major)));
				return;
			}
			temp = temp->next;
		}
		close();
		QMessageBox::warning(NULL, coder->toUnicode("提示"), coder->toUnicode("未查找到此信息"), QMessageBox::Ok, QMessageBox::Ok);
		
	}
	else if(flag==3)
	{
		while (temp != nullptr)
		{
			if (temp->tele ==telLine->text().toStdString())
			{
				close();
				QMessageBox::information(NULL, coder->toUnicode("提示"), coder->toUnicode("查找成功！"), QMessageBox::Ok, QMessageBox::Ok);
				ptrMain->delAllTable();
				ptrMain->tableModel->setItem(0, 0, new QStandardItem(ScQ->str2qstr(temp->num)));
				ptrMain->tableModel->setItem(0, 1, new QStandardItem(ScQ->str2qstr(temp->name)));
				ptrMain->tableModel->setItem(0, 2, new QStandardItem(ScQ->str2qstr(temp->tele)));
				ptrMain->tableModel->setItem(0, 3, new QStandardItem(ScQ->str2qstr(temp->major)));
				return;
			}
			temp = temp->next;
		}
		close();
		QMessageBox::warning(NULL, coder->toUnicode("提示"), coder->toUnicode("未查找到此信息"), QMessageBox::Ok, QMessageBox::Ok);
		
	}
}

//只保留名字搜索条件
void searchSubDialog::enable1()
{
	nameLine->setEnabled(true);
	numLine->setEnabled(false);
	telLine->setEnabled(false);
	flag = 1;
}

//只保留学号搜索条件
void searchSubDialog::enable2()
{
	nameLine->setEnabled(false);
	numLine->setEnabled(true);
	telLine->setEnabled(false);
	flag = 2;
}

//只保留电话搜索条件
void searchSubDialog::enable3()
{
	nameLine->setEnabled(false);
	numLine->setEnabled(false);
	telLine->setEnabled(true);
	flag = 3;
}