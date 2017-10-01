#ifndef __DBASE_H__
#define __DBASE_H__

// ��������� 
struct SItem
{
	int ID;
	int CoursID;
	char GroupID[50];
	char Name[25];
	char Surname[25];
	char Patronymic[25];
	char YearOfBir[25];
	char ManGen[20];
	long long int PhoneNum;
	SItem *next;
};
// ���� ������������ ��� //
namespace StudBase
{
	// =========��������� �������============
	void StudElem(int ID, SItem *Head);
	void StudList(SItem *Head);
	void AddItem(SItem *Head, SItem *NewItem, SItem **Teil);
	void SaveList(SItem *Head);
}
#endif