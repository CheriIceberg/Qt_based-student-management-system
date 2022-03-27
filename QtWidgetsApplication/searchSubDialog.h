#pragma once

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QTextCodec>
#include <QString>
#include <QMessageBox>


class searchSubDialog : public QDialog
{
	Q_OBJECT
public:
	searchSubDialog(QWidget* parent = Q_NULLPTR);
	QTextCodec* coder = QTextCodec::codecForName("gbk");
	QVBoxLayout* verticalLayout;
	QGridLayout* gridLayout1;
	QGridLayout* gridLayout2;
	QGridLayout* gridLayout3;
	QGridLayout* gridLayout4;
	QLabel* searchMessage;
	QLabel* nameLabel;
	QLabel* numLabel;
	QLabel* telLabel;
	QPushButton* confirmSearchBtn;
	QPushButton* cancelSearchBtn;
	QLineEdit* numLine;
	QLineEdit* telLine;
	QLineEdit* nameLine;
	int flag;
	//QtWidgetsApplication* ptrMain;

public slots:
	void confirmSearch();
	void cancelSearch();
	void enable1();
	void enable2();
	void enable3();
};

