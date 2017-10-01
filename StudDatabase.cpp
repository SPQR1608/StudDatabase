////////////////////////////////////////////////////////////
// Лабораторная работа №11.
// Тема: "Использование списков для хранения информации".
// Вариант №6.
// Студент Дюльгер Д. А.
// Группа ИСТ-201.
////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <locale.h>
#include <iostream>
#include <conio.h>
#include "Dbase.h"
#include <windows.h>

using namespace std;
using namespace StudBase; // наше пространство имён
// нумерация команд меню
enum menu {EXIT, NEW_ELEM, PRINT_ELEM, PRINT_ALL, SAVE_FILE, CLEAR_CMD, END};

int Menu();// прототип

void _tmain()
{
	setlocale(LC_CTYPE, ".1251");

	SItem *Head = NULL;
	SItem **Teil;
	SItem *NewItem;
	int CmdMenu;
	int ID;
	// создание первого элемента списка		
	Head = new SItem;
	Head->ID = 0;
	Head->next = NULL;
	cout << "Введите фамилию: ";
	cin >> Head->Surname;
	OemToAnsi(Head->Surname, Head->Surname);
	cout << "Введите имя: ";
	cin >> Head->Name;
	OemToAnsi(Head->Name, Head->Name);
	cout << "Введите отчество: ";
	cin >> Head->Patronymic;
	OemToAnsi(Head->Patronymic, Head->Patronymic);
	cout << "Введите группу: ";
	cin >> Head->GroupID;
	OemToAnsi(Head->GroupID, Head->GroupID);
	cout << "Введите курс: ";
	cin >> Head->CoursID;
	cout << "Введите день, месяц и год рождения: ";
	cin >> Head->YearOfBir;
	OemToAnsi(Head->YearOfBir, Head->YearOfBir);
	cout << "Введите пол: ";
	cin >> Head->ManGen;
	OemToAnsi(Head->ManGen, Head->ManGen);
	cout << "Введите номер телефона: ";
	cin >> Head->PhoneNum;
	
	Teil = new SItem*;
	*Teil = Head;
	//==========ВЫЗОВ МЕНЮ=========//
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
				cout << "Номер элемента: ";
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
// программирование меню
int Menu()
{
	int CmdMenu;

	cout << endl << "МЕНЮ:" << endl;
	for(;;)
	{
		cout << EXIT << " - выход" << endl;
		cout << NEW_ELEM << " - новый элемент" << endl;
		cout << PRINT_ELEM << " - вывести на экран элемент" << endl;
		cout << PRINT_ALL << " - вывести на экран все элементы" << endl;
		cout << SAVE_FILE << " - сохранить в файле" << endl;
		cout << CLEAR_CMD << " - очистка экрана" << endl;
		cout << "Номер команды меню: ";
		cin >> CmdMenu;
		cout << endl;
		if(CmdMenu < 0 || CmdMenu >= END)
		{
			cout << "ОШИБКА - такой команды нет." << endl;
			continue;
		}
		else
			return CmdMenu;
	}
}

