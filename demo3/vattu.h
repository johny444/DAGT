#pragma once
#include<iostream>
#include"Date.h"
using namespace std;
class vattu :public Date
{
public:
	string mvt;
	int sl;
	string ten, loai, DV, nsx;
	int DG;
public:
	bool input();
	void output();
	friend istream& operator>>(istream&, vattu&);
	friend ostream& operator<<(ostream&, const vattu&);
	~vattu();
};
