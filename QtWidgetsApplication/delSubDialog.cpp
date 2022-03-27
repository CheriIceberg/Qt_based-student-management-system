#include "delSubDialog.h"
#include "globalState.h"
#include "QtWidgetsApplication.h"

delSubDialog::delSubDialog(QWidget* parent) :QDialog(parent)
{
	this->setWindowTitle(coder->toUnicode("删除信息"));
	this->setWindowIcon(QIcon(":/new/pictures/delete.svg"));
	veiticalLayout = new QVBoxLayout(this);
	delMessage = new QLabel(coder->toUnicode("请输入要删除的学号"), this);
	delMessage->setAlignment(Qt::AlignCenter);
	veiticalLayout->addWidget(delMessage);
	gridLayout4 = new QGridLayout();
	numLine = new QLineEdit(this);
	numLine->setMaximumSize(QSize(150, 30));
	gridLayout4->addWidget(numLine, 0, 1, 1, 1);
	delNum = new QLabel(coder->toUnicode("学号："),this);
	delNum->setMaximumSize(QSize(80, 30));
	gridLayout4->addWidget(delNum, 0, 0, 1, 1);
	veiticalLayout->addItem(gridLayout4);
	gridLayout5 = new QGridLayout();
	confirmDelBtn = new QPushButton(coder->toUnicode("确定"),this);
	confirmDelBtn->setMaximumSize(QSize(80, 30));
	cancelDelBtn = new QPushButton(coder->toUnicode("取消"), this);
	cancelDelBtn->setMaximumSize(QSize(80, 30));
	gridLayout5->addWidget(confirmDelBtn, 0, 0, 1, 1);
	gridLayout5->addWidget(cancelDelBtn, 0, 1, 1, 1);
	veiticalLayout->addLayout(gridLayout5);
	//QtWidgetsApplication* ptrMain = (QtWidgetsApplication*)parentWidget();
	//槽函数与信号连接
	connect(cancelDelBtn, SIGNAL(clicked()), this, SLOT(canceldel()));
	connect(confirmDelBtn, SIGNAL(clicked()), this, SLOT(confirmdel()));
}

void delSubDialog::confirmdel()
{
	QtWidgetsApplication* ptrMain_del = (QtWidgetsApplication*)parentWidget();
	PLinkNode temp = new LinkNode;
	temp = head;
	if (stuNum==0)
	{
		QMessageBox::warning(this, coder->toUnicode("提示"), coder->toUnicode("未查找到此信息"), QMessageBox::Ok, QMessageBox::Ok);
	}
	else
	{
		while (temp->next != nullptr && temp->num != QcS->qstr2str(numLine->text()))
		{
			temp = temp->next;
		}
		if (temp->num != QcS->qstr2str(numLine->text()))
		{
			QMessageBox::warning(this, coder->toUnicode("提示"), coder->toUnicode("未查找到此信息"), QMessageBox::Ok, QMessageBox::Ok);
		}
		else
		{
			if (temp->prev == nullptr)
			{
				head = head->next;

			}
			else
			{
				if (temp->next == nullptr) {
					temp->prev->next = nullptr;
				}
				else {
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
				}
			}
			delete temp;
			stuNum--;
			QMessageBox::information(this, coder->toUnicode("提示"), coder->toUnicode("删除成功！"), QMessageBox::Ok, QMessageBox::Ok);
			close();
			ptrMain_del->delAllTable();
			ptrMain_del->showAllTable();
		}
	}
}

void delSubDialog::canceldel()
{
	close();
}