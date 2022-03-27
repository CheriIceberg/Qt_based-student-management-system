#include "createSubDialog.h"
#include "globalState.h"
#include "QtWidgetsApplication.h"

createSubDialog::createSubDialog(QWidget* parent) :QDialog(parent)
{
	//QtWidgetsApplication* ptrMain_create = (QtWidgetsApplication*)parentWidget();
	this->setWindowTitle(coder->toUnicode("添加信息"));
	this->setWindowIcon(QIcon(":/new/pictures/creat.svg"));
	verticalLayout = new QVBoxLayout(this);
	gridLayout2 = new QGridLayout();
	label1 = new QLabel(coder->toUnicode("学号："),this);
	label1->setMaximumSize(QSize(80, 30));
	gridLayout2->addWidget(label1,0,0,1,1);
	lineEdit1 = new QLineEdit(this);//学号
	
	lineEdit1->setMaximumSize(QSize(150, 30));
	lineEdit1->setAlignment(Qt::AlignLeft);
	lineEdit1->setClearButtonEnabled(true);
	gridLayout2->addWidget(lineEdit1, 0, 1, 1, 1);
	lineEdit2 = new QLineEdit(this);//姓名
	
	lineEdit2->setMaximumSize(QSize(150, 30));
	lineEdit2->setAlignment(Qt::AlignLeft);
	lineEdit2->setClearButtonEnabled(true);
	gridLayout2->addWidget(lineEdit2, 0, 4, 1, 1);
	horizontalSpacer1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	gridLayout2->addItem(horizontalSpacer1, 0, 2, 1, 1);
	label3 = new QLabel(coder->toUnicode("姓名："));
	label3->setMaximumSize(QSize(80, 30));
	gridLayout2->addWidget(label3, 0, 3, 1, 1);
	verticalLayout->addLayout(gridLayout2);
	gridLayout1 = new QGridLayout();
	label4 = new QLabel(coder->toUnicode("学院："), this);
	gridLayout1->addWidget(label4,0, 3, 1, 1);
	lineEdit4 = new QLineEdit(this);//学院

	lineEdit4->setMaximumSize(QSize(150, 30));
	lineEdit4->setAlignment(Qt::AlignLeft);
	lineEdit4->setClearButtonEnabled(true);
	gridLayout1->addWidget(lineEdit4, 0, 4, 1, 1);
	lineEdit3 = new QLineEdit(this);//电话

	lineEdit3->setMaximumSize(QSize(150, 30));
	lineEdit3->setAlignment(Qt::AlignLeft);
	lineEdit3->setClearButtonEnabled(true);
	gridLayout1->addWidget(lineEdit3, 0, 1, 1, 1);
	label2 = new QLabel(coder->toUnicode("电话："), this);
	gridLayout1->addWidget(label2, 0, 0, 1, 1);
	horizontalSpacer2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	gridLayout1->addItem(horizontalSpacer2, 0, 2, 1, 1);
	verticalLayout->addLayout(gridLayout1);
	gridLayout3 = new QGridLayout();
	horizontalSpacer5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	gridLayout3->addItem(horizontalSpacer5,0, 4, 1, 1);
	confirmButton = new QPushButton(coder->toUnicode("确认"));
	cancelButton = new QPushButton(coder->toUnicode("取消"));
	confirmButton->setMaximumSize(QSize(120, 30));
	cancelButton->setMaximumSize(QSize(120, 30));
	gridLayout3->addWidget(cancelButton, 0, 3, 1, 1);
	gridLayout3->addWidget(confirmButton, 0, 1, 1, 1);
	horizontalSpacer4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	gridLayout3->addItem(horizontalSpacer4, 0, 0, 1, 1);
	horizontalSpacer3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	gridLayout3->addItem(horizontalSpacer3, 0, 2, 1, 1);
	verticalLayout->addLayout(gridLayout3);
	//QtWidgetsApplication* ptrMain = (QtWidgetsApplication*)parentWidget();

	//QObject::connect(cancelButton, SIGNAL(clicked(void), this, SLOT(quit(void))));
	//槽函数与信号连接
	connect(cancelButton, SIGNAL(clicked(void)), this, SLOT(closeSubDialog(void)));
	connect(confirmButton, SIGNAL(clicked(void)), this, SLOT(confirmCreate(void)));
}


//添加按钮子窗口取消按钮
void createSubDialog::closeSubDialog()
{
	close();
}

//子窗口确定按钮
void createSubDialog::confirmCreate()
{
	QtWidgetsApplication* ptrMain_create = (QtWidgetsApplication*)parentWidget();
	if ((lineEdit1->text() != "") && (lineEdit2->text() != "") && (lineEdit3->text() != "") && (lineEdit4->text() != ""))
	{
		if (stuNum == 0)
		{
			head->num = QcS->qstr2str(lineEdit1->text());
			head->name = QcS->qstr2str(lineEdit2->text());
			head->tele = QcS->qstr2str(lineEdit3->text());
			head->major = QcS->qstr2str(lineEdit4->text());
			stuNum++;
			close();
			QMessageBox::information(this, coder->toUnicode("提示"), coder->toUnicode("添加成功！"), QMessageBox::Ok, QMessageBox::Ok);
			ptrMain_create->delAllTable();
			ptrMain_create->showAllTable();
		}
		else
		{
			PLinkNode last = new LinkNode;
			last = head;
			while (last->next != nullptr) {
				last = last->next;
			}
			PLinkNode x = new LinkNode;
			x->num = QcS->qstr2str(lineEdit1->text());
			x->name = QcS->qstr2str(lineEdit2->text());
			x->tele = QcS->qstr2str(lineEdit3->text());
			x->major = QcS->qstr2str(lineEdit4->text());
			last->next = x;
			x->prev = last;
			x->next = nullptr;
			stuNum++;
			close(); 
			QMessageBox::information(this, coder->toUnicode("提示"), coder->toUnicode("添加成功！"), QMessageBox::Ok, QMessageBox::Ok);
			ptrMain_create->delAllTable();
			ptrMain_create->showAllTable();
		}
	}
	else
	{
		QMessageBox::warning(this, coder->toUnicode("提示"), coder->toUnicode("请输入完整信息！"), QMessageBox::Ok, QMessageBox::Ok);
	}
}