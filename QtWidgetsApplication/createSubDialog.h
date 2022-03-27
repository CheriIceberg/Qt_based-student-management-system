#pragma once

#include <iostream>
#include <string>
#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpacerItem>
#include <QVBoxLayout>
#include <QTextCodec>
#include <QIcon>
#include <QMessageBox>
//#include <QRegularExpressionValidator>
//#include "studentList.cpp"
//#include "globalState.h"
using namespace std;

class createSubDialog : public QDialog
{
	Q_OBJECT
public:
	//QtWidgetsApplication(QWidget* parent = Q_NULLPTR);
	createSubDialog(QWidget* parent = Q_NULLPTR);
	QTextCodec* coder = QTextCodec::codecForName("gbk");
	QVBoxLayout* verticalLayout;
	QGridLayout* gridLayout1;
	QGridLayout* gridLayout2;
	QGridLayout* gridLayout3;
	QLabel* label1;
	QLabel* label2;
	QLabel* label3;
	QLabel* label4;
	QLineEdit* lineEdit1;
	QLineEdit* lineEdit2;
	QLineEdit* lineEdit3;
	QLineEdit* lineEdit4;
	QSpacerItem* horizontalSpacer1;
	QSpacerItem* horizontalSpacer2;
	QSpacerItem* horizontalSpacer3;
	QSpacerItem* horizontalSpacer4;
	QSpacerItem* horizontalSpacer5;
	QPushButton* confirmButton;
	QPushButton* cancelButton;

	//信号与槽函数连接
public slots:
	void closeSubDialog();
	void confirmCreate();
};

