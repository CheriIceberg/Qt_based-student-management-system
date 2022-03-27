#pragma once

#include <string>
#include <iostream>
#include <QString>
#include<algorithm>
using namespace std;

typedef struct LinkNode {
	string num;
	string name;
	string major;
	string tele;
	struct LinkNode* prev = nullptr;
	struct LinkNode* next = nullptr;
}LinkNode, * PLinkNode;

//QString类型转化String
class QStr2Str {
public:
	string qstr2str(const QString& qstr)
	{
		QByteArray cdata = qstr.toLocal8Bit();
		return string(cdata);
	}
};

//string类型转换Qstring
class Str2Qstr {
public:
	QString str2qstr(const string str)
	{
		return QString::fromLocal8Bit(str.data());
	}

};
extern Str2Qstr* ScQ;
extern QStr2Str* QcS;
extern int stuNum;
extern PLinkNode head;
