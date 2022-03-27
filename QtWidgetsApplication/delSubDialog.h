#pragma once

#include <QDialog>
#include <QTextCodec>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>


class delSubDialog : public QDialog
{
	Q_OBJECT
public:
	delSubDialog(QWidget* parent = Q_NULLPTR);
	QTextCodec* coder = QTextCodec::codecForName("gbk");
	QPushButton* confirmDelBtn;
	QPushButton* cancelDelBtn;
	QLabel* delMessage;
	QLabel* delNum;
	QLineEdit* numLine;
	QVBoxLayout* veiticalLayout;
	QGridLayout* gridLayout4;
	QGridLayout* gridLayout5;

public slots:
	void confirmdel();
	void canceldel();
};