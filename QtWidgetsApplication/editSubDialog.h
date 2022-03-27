#pragma once
#include <QDialog>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextCodec>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QIcon>

class editSubDialog : public QDialog
{
	Q_OBJECT
public:
    editSubDialog(QWidget* parent = Q_NULLPTR);
	QTextCodec* coder = QTextCodec::codecForName("gbk");
    QVBoxLayout* verticalLayout;
    QGridLayout* gridLayout_10;
    QGridLayout* gridLayout_8;
    QGridLayout* gridLayout_2;
    QLineEdit* preNameLine;
    QLabel* preNameLabel;
    QLabel* preMessage;
    QGridLayout* gridLayout;
    QLabel* preNumLabel;
    QLineEdit* preNumLine;
    QGridLayout* gridLayout_7;
    QGridLayout* gridLayout_6;
    QLabel* editMajor;
    QLineEdit* majorLine;
    QGridLayout* gridLayout_4;
    QLabel* editNum;
    QLineEdit* numLine;
    QGridLayout* gridLayout_3;
    QLineEdit* nameLine;
    QLabel* editName;
    QLabel* editMessage;
    QGridLayout* gridLayout_5;
    QLabel* editTel;
    QLineEdit* telLine;
    QGridLayout* gridLayout_9;
    QPushButton* confirmBtn;
    QPushButton* cancelBtn;
    int flag;

public slots:
    void confirmEdit(void);
    void cancelEdit(void);
    void enableName(void);
    void enableNum(void);

};