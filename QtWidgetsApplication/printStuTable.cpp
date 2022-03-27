#include "QtWidgetsApplication.h"
#include <QtWidgets/QApplication>
#include "globalState.h"
#include <QAxObject>

void QtWidgetsApplication::showStuExcel(void)
{
	if (stuNum == 0)
	{
		QMessageBox::warning(this, coder->toUnicode("提示"), coder->toUnicode("信息为空！"), QMessageBox::Ok, QMessageBox::Ok);
		return;
	}
	QString filepath = QFileDialog::getSaveFileName(this, tr("studentExcel"), ".", tr("*.xlsx"));
	if (!filepath.isEmpty())
	{
		QAxObject* excel = new QAxObject(this);
		excel->setControl("Excel.Application");
		excel->dynamicCall("SetVisible(bool Visible)", "false");
		excel->setProperty("DisplayAlerts", false);
		QAxObject* workbooks = excel->querySubObject("WorkBooks");
		workbooks->dynamicCall("Add");
		QAxObject* workbook = excel->querySubObject("ActiveWorkBook");
		QAxObject* worksheets = workbook->querySubObject("Sheets");
		QAxObject* worksheet = worksheets->querySubObject("Item(int)", 1);
		QAxObject* cellA, * cellB, * cellC, * cellD;
		int cellrow = 1;
		QString A = "A" + QString::number(cellrow);
		QString B = "B" + QString::number(cellrow);
		QString C = "C" + QString::number(cellrow);
		QString D = "D" + QString::number(cellrow);
		cellA = worksheet->querySubObject("Range(QVariant,QVariant)", A);
		cellB = worksheet->querySubObject("Range(QVariant,QVariant)", B);
		cellC = worksheet->querySubObject("Range(QVariant,QVariant)", C);
		cellD = worksheet->querySubObject("Range(QVariant,QVariant)", D);
		cellA->dynamicCall("SetValue(const QVariant&)", QVariant(ScQ->str2qstr(string("学号"))));
		cellB->dynamicCall("SetValue(const QVariant&)", QVariant(ScQ->str2qstr(string("姓名"))));
		cellC->dynamicCall("SetValue(const QVariant&)", QVariant(ScQ->str2qstr(string("电话"))));
		cellD->dynamicCall("SetValue(const QVariant&)", QVariant(ScQ->str2qstr(string("学院"))));
		cellrow++;
		int rows = stuNum;
		for (int i = 0; i < rows; i++)
		{
			QString A = "A" + QString::number(cellrow);
			QString B = "B" + QString::number(cellrow);
			QString C = "C" + QString::number(cellrow);
			QString D = "D" + QString::number(cellrow);
			cellA = worksheet->querySubObject("Range(QVariant,QVariant)", A);
			cellB = worksheet->querySubObject("Range(QVariant,QVariant)", B);
			cellC = worksheet->querySubObject("Range(QVariant,QVariant)", C);
			cellD = worksheet->querySubObject("Range(QVariant,QVariant)", D);
			cellA->dynamicCall("SetValue(const QVariant&)", QVariant(this->tableModel->item(i, 0)->data(Qt::DisplayRole).toString()));
			cellB->dynamicCall("SetValue(const QVariant&)", QVariant(this->tableModel->item(i, 1)->data(Qt::DisplayRole).toString()));
			cellC->dynamicCall("SetValue(const QVariant&)", QVariant(this->tableModel->item(i, 2)->data(Qt::DisplayRole).toString()));
			cellD->dynamicCall("SetValue(const QVariant&)", QVariant(this->tableModel->item(i, 3)->data(Qt::DisplayRole).toString()));
			cellrow++;
			
		}
		workbook->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(filepath));
		workbook->dynamicCall("Close()");
		excel->dynamicCall("Quit()");
		delete excel;
		excel = NULL;
		QMessageBox::information(NULL, coder->toUnicode("提示"), coder->toUnicode("输出成功！"), QMessageBox::Ok, QMessageBox::Ok);

	}
}