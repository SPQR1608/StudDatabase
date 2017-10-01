#include "stdafx.h"
#include <locale.h>
#include <iostream>
#include <fstream>
#include <windows.h>
#include "Dbase.h"

using namespace std;

///////////////////////////////////////////////////////
// Вывод одного элемента в окно консольного приложения.
void StudBase::StudElem(int ID, SItem *Head)
{
	SItem *Curr; // Буфер
	Curr = Head;

	while(Curr->ID != ID)
	{
		if(Curr->next == NULL)
		{
			cout << "ОШИБКА! Элемента с таким номером в списке нет." << endl;
			cout << endl;
			return;
		}
		Curr = Curr->next;
	}
	cout << "\t" << "ФИО студента:" << endl;
	cout << "\t" << Curr->Surname << " " << Curr->Name << " " << Curr->Patronymic << endl;
	cout << "\t" << "Группа студента: " << Curr->GroupID << endl;
	cout << "\t" << "Курс студента: " << Curr->CoursID << endl;
	cout << "\t" << "Дата рождения: " << Curr->YearOfBir << endl;
	cout << "\t" << "Половая принадлежность: " << Curr->ManGen << endl;
	cout << "\t" << "Телефонный номер: " << Curr->PhoneNum << endl << endl;
}
////////////////////////////////////////////////////////
// Вывод всех элементов списка
void StudBase::StudList(SItem *Head)
{
	SItem *Curr;
	Curr = Head;

	while(Curr->next)
	{
		cout << "\t" << "Номер элемента: " << Curr->ID << endl;
		cout << "\t" << "ФИО студента:" << endl;
		cout << "\t" << Curr->Surname << " " << Curr->Name << " " << Curr->Patronymic << endl;
		cout << "\t" << "Группа студента: " << Curr->GroupID << endl;
		cout << "\t" << "Курс студента: " << Curr->CoursID << endl;
		cout << "\t" << "Дата рождения: " << Curr->YearOfBir << endl;
		cout << "\t" << "Половая принадлежность: " << Curr->ManGen << endl;
		cout << "\t" << "Телефонный номер: " << Curr->PhoneNum << endl << endl;
		Curr = Curr->next;
	}
	cout << "\t" << "Номер элемента: " << Curr->ID << endl;
	cout << "\t" << "ФИО студента:" << endl;
	cout << "\t" << Curr->Surname << " " << Curr->Name << " " << Curr->Patronymic << endl;		
	cout << "\t" << "Группа студента: " << Curr->GroupID << endl;
	cout << "\t" << "Курс студента: " << Curr->CoursID << endl;
	cout << "\t" << "Дата рождения: " << Curr->YearOfBir << endl;
	cout << "\t" << "Половая принадлежность: " << Curr->ManGen << endl;
	cout << "\t" << "Телефонный номер: " << Curr->PhoneNum << endl << endl;
}
////////////////////////////////////////////////////////////////
// Добавление нового элемента в список.
void StudBase::AddItem(SItem *Head, SItem *NewItem, SItem **Teil)
{
	NewItem->ID = (*Teil)->ID + 1;
	// изменение указателя next первого элемента
	if((*Teil)->ID == 0)
		Head->next = NewItem;
	NewItem->next = NULL;
	(*Teil)->next = NewItem;

	// Ввод данных
	cout << "Введите фамилию: ";
	cin >> NewItem->Surname;
	OemToAnsi(NewItem->Surname, NewItem->Surname);
	cout << "Введите имя: ";
	cin >> NewItem->Name;
	OemToAnsi(NewItem->Name, NewItem->Name);
	cout << "Введите отчество: ";
	cin >> NewItem->Patronymic;
	OemToAnsi(NewItem->Patronymic, NewItem->Patronymic);
	cout << "Введите группу: ";
	cin >> NewItem->GroupID;
	OemToAnsi(NewItem->GroupID, NewItem->GroupID);
	cout << "Введите курс: ";
	cin >> NewItem->CoursID;
	cout << "Введите день, месяц и год рождения: ";
	cin >> NewItem->YearOfBir;
	OemToAnsi(NewItem->YearOfBir, NewItem->YearOfBir);
	cout << "Введите пол: ";
	cin >> NewItem->ManGen;
	OemToAnsi(NewItem->ManGen, NewItem->ManGen);
	cout << "Введите номер телефона: ";
	cin >> NewItem->PhoneNum;
	*Teil = NewItem; // Концом списка становится новый элемент.
}
////////////////////////////////////////////////////////////////
// Сохранение списка в текстовый файл.
void StudBase::SaveList(SItem *Head)
{
	SItem *Curr;
	Curr = Head;
	
	// создаём объект txtfile
	ofstream data;
	data.open("StudDatabase.txt");
	while(Curr->next)
	{
		data << "Номер элемента: " << Curr->ID << endl;
		data << "ФИО студента:" << endl;
		data << Curr->Surname << " " << Curr->Name << " " << Curr->Patronymic << endl;		
		data << "Группа студента: " << Curr->GroupID << endl;
		data << "Курс студента: " << Curr->CoursID << endl;
		data << "Дата рождения: " << Curr->YearOfBir << endl;
		data << "Половая принадлежность: " << Curr->ManGen << endl;
		data << "Телефонный номер: " << Curr->PhoneNum << endl << endl;
		Curr = Curr->next;
	}
	data << "Номер элемента: " << Curr->ID << endl;
	data << "ФИО студента:" << endl;
	data << Curr->Surname << " " << Curr->Name << " " << Curr->Patronymic << endl;		
	data << "Группа студента: " << Curr->GroupID << endl;
	data << "Курс студента: " << Curr->CoursID << endl;
	data << "Дата рождения: " << Curr->YearOfBir << endl;
	data << "Половая принадлежность: " << Curr->ManGen << endl;
	data << "Телефонный номер: " << Curr->PhoneNum << endl << endl;
	
	cout << "Запись данных в файл завершена." << endl << endl;
	data.close();
}




