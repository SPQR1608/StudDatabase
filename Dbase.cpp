#include "stdafx.h"
#include <locale.h>
#include <iostream>
#include <fstream>
#include <windows.h>
#include "Dbase.h"

using namespace std;

///////////////////////////////////////////////////////
// ����� ������ �������� � ���� ����������� ����������.
void StudBase::StudElem(int ID, SItem *Head)
{
	SItem *Curr; // �����
	Curr = Head;

	while(Curr->ID != ID)
	{
		if(Curr->next == NULL)
		{
			cout << "������! �������� � ����� ������� � ������ ���." << endl;
			cout << endl;
			return;
		}
		Curr = Curr->next;
	}
	cout << "\t" << "��� ��������:" << endl;
	cout << "\t" << Curr->Surname << " " << Curr->Name << " " << Curr->Patronymic << endl;
	cout << "\t" << "������ ��������: " << Curr->GroupID << endl;
	cout << "\t" << "���� ��������: " << Curr->CoursID << endl;
	cout << "\t" << "���� ��������: " << Curr->YearOfBir << endl;
	cout << "\t" << "������� ��������������: " << Curr->ManGen << endl;
	cout << "\t" << "���������� �����: " << Curr->PhoneNum << endl << endl;
}
////////////////////////////////////////////////////////
// ����� ���� ��������� ������
void StudBase::StudList(SItem *Head)
{
	SItem *Curr;
	Curr = Head;

	while(Curr->next)
	{
		cout << "\t" << "����� ��������: " << Curr->ID << endl;
		cout << "\t" << "��� ��������:" << endl;
		cout << "\t" << Curr->Surname << " " << Curr->Name << " " << Curr->Patronymic << endl;
		cout << "\t" << "������ ��������: " << Curr->GroupID << endl;
		cout << "\t" << "���� ��������: " << Curr->CoursID << endl;
		cout << "\t" << "���� ��������: " << Curr->YearOfBir << endl;
		cout << "\t" << "������� ��������������: " << Curr->ManGen << endl;
		cout << "\t" << "���������� �����: " << Curr->PhoneNum << endl << endl;
		Curr = Curr->next;
	}
	cout << "\t" << "����� ��������: " << Curr->ID << endl;
	cout << "\t" << "��� ��������:" << endl;
	cout << "\t" << Curr->Surname << " " << Curr->Name << " " << Curr->Patronymic << endl;		
	cout << "\t" << "������ ��������: " << Curr->GroupID << endl;
	cout << "\t" << "���� ��������: " << Curr->CoursID << endl;
	cout << "\t" << "���� ��������: " << Curr->YearOfBir << endl;
	cout << "\t" << "������� ��������������: " << Curr->ManGen << endl;
	cout << "\t" << "���������� �����: " << Curr->PhoneNum << endl << endl;
}
////////////////////////////////////////////////////////////////
// ���������� ������ �������� � ������.
void StudBase::AddItem(SItem *Head, SItem *NewItem, SItem **Teil)
{
	NewItem->ID = (*Teil)->ID + 1;
	// ��������� ��������� next ������� ��������
	if((*Teil)->ID == 0)
		Head->next = NewItem;
	NewItem->next = NULL;
	(*Teil)->next = NewItem;

	// ���� ������
	cout << "������� �������: ";
	cin >> NewItem->Surname;
	OemToAnsi(NewItem->Surname, NewItem->Surname);
	cout << "������� ���: ";
	cin >> NewItem->Name;
	OemToAnsi(NewItem->Name, NewItem->Name);
	cout << "������� ��������: ";
	cin >> NewItem->Patronymic;
	OemToAnsi(NewItem->Patronymic, NewItem->Patronymic);
	cout << "������� ������: ";
	cin >> NewItem->GroupID;
	OemToAnsi(NewItem->GroupID, NewItem->GroupID);
	cout << "������� ����: ";
	cin >> NewItem->CoursID;
	cout << "������� ����, ����� � ��� ��������: ";
	cin >> NewItem->YearOfBir;
	OemToAnsi(NewItem->YearOfBir, NewItem->YearOfBir);
	cout << "������� ���: ";
	cin >> NewItem->ManGen;
	OemToAnsi(NewItem->ManGen, NewItem->ManGen);
	cout << "������� ����� ��������: ";
	cin >> NewItem->PhoneNum;
	*Teil = NewItem; // ������ ������ ���������� ����� �������.
}
////////////////////////////////////////////////////////////////
// ���������� ������ � ��������� ����.
void StudBase::SaveList(SItem *Head)
{
	SItem *Curr;
	Curr = Head;
	
	// ������ ������ txtfile
	ofstream data;
	data.open("StudDatabase.txt");
	while(Curr->next)
	{
		data << "����� ��������: " << Curr->ID << endl;
		data << "��� ��������:" << endl;
		data << Curr->Surname << " " << Curr->Name << " " << Curr->Patronymic << endl;		
		data << "������ ��������: " << Curr->GroupID << endl;
		data << "���� ��������: " << Curr->CoursID << endl;
		data << "���� ��������: " << Curr->YearOfBir << endl;
		data << "������� ��������������: " << Curr->ManGen << endl;
		data << "���������� �����: " << Curr->PhoneNum << endl << endl;
		Curr = Curr->next;
	}
	data << "����� ��������: " << Curr->ID << endl;
	data << "��� ��������:" << endl;
	data << Curr->Surname << " " << Curr->Name << " " << Curr->Patronymic << endl;		
	data << "������ ��������: " << Curr->GroupID << endl;
	data << "���� ��������: " << Curr->CoursID << endl;
	data << "���� ��������: " << Curr->YearOfBir << endl;
	data << "������� ��������������: " << Curr->ManGen << endl;
	data << "���������� �����: " << Curr->PhoneNum << endl << endl;
	
	cout << "������ ������ � ���� ���������." << endl << endl;
	data.close();
}




