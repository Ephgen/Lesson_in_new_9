#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

struct Elem
{	
	int ownerPoints;	// очки хозяина
	int oppPoints;		// очки соперника
	char Match[10];		// счет
	char Name[20];		//команда
	char Opponent[20];		// соперник

	Elem* left, * right, * parent;
};

class Three
{
	Elem* root;		// корень дерева
public:
	Three();
	~Three();
	void Print(Elem*);		// Отображение от указанного узла
	Elem* Search(Elem*, char*);	// поиск указанного узла
	Elem* Min(Elem*);		//минимум от указанноо узла
	Elem* Max(Elem*);		//----/---
	Elem* Next(Elem*);		// следующий узел
	Elem* Previous(Elem*);	// предыд
	void Insert(Elem*);		// вставка узла
	void Del(Elem* = 0);	// удаление узла (0 - удаление всего дерева)
	Elem* GetRoot();		// получение основного дерева


};

