////////////////////////////////////////////////////////////
// ������������ ������ �11.
// ����: "������������� ������� ��� �������� ����������".
// ������� �6.
// ������� ������� �. �.
// ������ ���-201.
////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <locale.h>
#include <iostream>
#include <conio.h>
#include "Dbase.h"
#include <windows.h>

using namespace std;
using namespace StudBase; // ���� ������������ ���
// ��������� ������ ����
enum menu {EXIT, NEW_ELEM, PRINT_ELEM, PRINT_ALL, SAVE_FILE, CLEAR_CMD, END};

int Menu();// ��������

void _tmain()
{
	setlocale(LC_CTYPE, ".1251");

	SItem *Head = NULL;
	SItem **Teil;
	SItem *NewItem;
	int CmdMenu;
	int ID;
	// �������� ������� �������� ������		
	Head = new SItem;
	Head->ID = 0;
	Head->next = NULL;
	cout << "������� �������: ";
	cin >> Head->Surname;
	OemToAnsi(Head->Surname, Head->Surname);
	cout << "������� ���: ";
	cin >> Head->Name;
	OemToAnsi(Head->Name, Head->Name);
	cout << "������� ��������: ";
	cin >> Head->Patronymic;
	OemToAnsi(Head->Patronymic, Head->Patronymic);
	cout << "������� ������: ";
	cin >> Head->GroupID;
	OemToAnsi(Head->GroupID, Head->GroupID);
	cout << "������� ����: ";
	cin >> Head->CoursID;
	cout << "������� ����, ����� � ��� ��������: ";
	cin >> Head->YearOfBir;
	OemToAnsi(Head->YearOfBir, Head->YearOfBir);
	cout << "������� ���: ";
	cin >> Head->ManGen;
	OemToAnsi(Head->ManGen, Head->ManGen);
	cout << "������� ����� ��������: ";
	cin >> Head->PhoneNum;
	
	Teil = new SItem*;
	*Teil = Head;
	//==========����� ����=========//
	for(;;)
	{
		CmdMenu = Menu();
		switch (CmdMenu)
		{
			case EXIT:
				return;
				break;
			case NEW_ELEM:
				NewItem = new SItem;
				AddItem(Head, NewItem, Teil);
				break;
			case PRINT_ELEM:
				cout << "����� ��������: ";
				cin >> ID;
				cout << endl;
				StudElem(ID, Head);
				break;
			case PRINT_ALL:
				StudList(Head);
				break;
			case SAVE_FILE:
				SaveList(Head);
				break;
			case CLEAR_CMD:
				system("cls");
				break;
		}
	}
}
// ���������������� ����
int Menu()
{
	int CmdMenu;

	cout << endl << "����:" << endl;
	for(;;)
	{
		cout << EXIT << " - �����" << endl;
		cout << NEW_ELEM << " - ����� �������" << endl;
		cout << PRINT_ELEM << " - ������� �� ����� �������" << endl;
		cout << PRINT_ALL << " - ������� �� ����� ��� ��������" << endl;
		cout << SAVE_FILE << " - ��������� � �����" << endl;
		cout << CLEAR_CMD << " - ������� ������" << endl;
		cout << "����� ������� ����: ";
		cin >> CmdMenu;
		cout << endl;
		if(CmdMenu < 0 || CmdMenu >= END)
		{
			cout << "������ - ����� ������� ���." << endl;
			continue;
		}
		else
			return CmdMenu;
	}
}

