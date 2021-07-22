#pragma once
#include "vattu.h"
#include<fstream>
class List :public vattu
{
public:
	int size;
	vattu* a;
public:
	void print(); // in danh sach vat tu
	void update(); // cap nhat 1 vat tu
	bool search(); // tim kiem 1 vat tu
	void menu(); // thuc don chuong trinh
	void ins(); // them 1 vat tu
	void del(); // xoa 1 vat tu
	void tinh();
	void sort(); // sap xep vat tu
	void printLine(int);
	bool BTHK();
	~List();
};

