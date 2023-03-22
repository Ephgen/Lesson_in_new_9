#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

struct Elem
{	
	int ownerPoints;	// ���� �������
	int oppPoints;		// ���� ���������
	char Match[10];		// ����
	char Name[20];		//�������
	char Opponent[20];		// ��������

	Elem* left, * right, * parent;
};

class Three
{
	Elem* root;		// ������ ������
public:
	Three();
	~Three();
	void Print(Elem*);		// ����������� �� ���������� ����
	Elem* Search(Elem*, char*);	// ����� ���������� ����
	Elem* Min(Elem*);		//������� �� ��������� ����
	Elem* Max(Elem*);		//----/---
	Elem* Next(Elem*);		// ��������� ����
	Elem* Previous(Elem*);	// ������
	void Insert(Elem*);		// ������� ����
	void Del(Elem* = 0);	// �������� ���� (0 - �������� ����� ������)
	Elem* GetRoot();		// ��������� ��������� ������


};

