#include "List.h"
#include "read_write_file.h"
#include "sort.h"
#include"MyString.h"
#include<iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
void List::print()
{
	
	cout << setw(85) << right <<"DANH SACH VAT TU"<< endl;
	cout << " "<<endl;

	cout << setw(5) << left << "STT";
	cout << setw(20) << left << "MA SO VAT TU";
	cout << setw(30) << left << "TEN VAT TU";
	cout << setw(10) << left << "LOAI";
	cout << setw(20) << left << "DON VI TINH";
	cout << setw(20) << left << "NGAY SAN XUAT";
	cout << setw(20) << left << "NHA SAN XUAT";
	cout << setw(20) << left << "SO LUONG";
	cout << setw(10) << left << "DON GIA";
	cout << endl;

	for (int i = 0; i < this->size; i++) {

		cout << setw(5) << left << i + 1;
		cout << setw(20) << left << a[i].mvt;
		cout << setw(30) << left << a[i].ten;
		cout << setw(10) << left << a[i].loai;
		cout << setw(20) << left << a[i].DV;
		cout  << a[i].ngay << "/" << a[i].thang << "/" << a[i].nam << setw(20) << left;
		cout << setw(20) << right << a[i].nsx;
		cout << setw(20) << right << a[i].sl;
		cout << setw(20) << right << a[i].DG;
		cout << endl;

		

	}
	printLine(120);
	cout << endl;

}

void List::update()
{
	int c;
	cout << "Nhap vi tri can cap nhat:";
	cin >> c;
	a[c - 1].input();
	cout << "!!!!!!!!!CAP NHAT THANH CONG!!!!!!!!!" << endl;
	writeGoodsToFile(a, this->size);
	output();
}

bool List::search()
{
	int t;
	bool isExist = false;
	while (1)
	{   
		cout << "\n******************************MENU******************************";
		cout << "\n*          Chon cong viec can thuc hien :                      *";
		cout << "\n*          1. Tim kiem theo ten vat tu .                       *";
		cout << "\n*          2. Tim kiem theo ma vat tu .                        *";
		cout << "\n*          3. Tim kiem theo loai vat tu .                      *";
		cout << "\n****************************************************************";
		cout << "\nchon n : ";
		cin >> t;
		string ast;
		if (t < 1 || t > 3)
			cout << "\nchon chua hop le, chon lai.";
		switch (t)
		{
		case 1:
		{
			string tn;
			cout << "NHAP TEN VAT TU CAN TIM:";
			cin.ignore();
			getline(cin, tn);
			string TN = To_upper(tn);
			string TEN;
			for (int i = 0; i < this->size; i++)
			{
				
				TEN = To_upper(a[i].ten);

				if (TN.compare(TEN) == 0)
				{
				
					printLine(35);
					a[i].output();
					isExist = true;
				}
			}
			break;
		}
		case 2:
		{
			string ms;
			cout << "NHAP MA VAT TU CAN TIM:";
			cin >> ms;
			string MS = To_upper(ms);
			string MVT;
			for (int i = 0; i < this->size; i++)
			{
				MVT = To_upper(a[i].mvt);
				
				
				if (MS.compare(MVT)==0)
				{
					
					printLine(35);
					a[i].output();
					isExist = true;
				}
			}
			break;
		}
		case 3:
		{
			string l;
			cout << "NHAP LOAI VAT TU CAN TIM:";
			cin.ignore();
			getline(cin, l);
			string L = To_upper(l);
			string LOAI;
			int d = 0;
			//bool b=NULL;
			for (int i = 0; i < this->size; i++)
			{
				LOAI = To_upper(a[i].loai);
				/*if (a[i].mvt == ms)*/
				d = i;
				if (L.compare(LOAI) == 0)
				{
					/*cout << "****************************************************************" << endl;
					if (L.compare(LOAI) != 0) { continue; }

					a[i].output();*/
					printLine(35);
					a[i].output();
					isExist = true;


				}
				/*return true;
				cout << d << endl;*/
				//if (d == i && L.compare(LOAI) == 0) { return true; }


			}break;
		
		}

		}
		return isExist;
	}
}

void List::menu()
{
	int chon;
	do
	{
		this->size = numberOfLines();
		this->a = new vattu[this->size];
		readGoodsFromFile(a, this->size);
		system("cls");
		cout << "\n******************************MENU******************************";
		cout << "\n*          Chon cong viec can thuc hien                        *";
		cout << "\n*          1. Cap nhat thong tin vat tu .                      *";
		cout << "\n*          2. Xuat thong tin vat tu .                          *";
		cout << "\n*          3. Tim kiem vat tu .                                *";
		cout << "\n*          4. In bang thong ke theo loai vat tu.               *";
		cout << "\n*          5. Sap xep vat tu.                                  *";
		cout << "\n*          6. Chen mau tin van duoc sap xep thu tu             *";
		cout << "\n*          7. Xoa vat tu.                                      *";
		cout << "\n*          0. Thoat ra.                                        *";
		cout << "\n****************************************************************";
		cout << endl;

		cout << "Chon cong viec can thuc hien:";
		cin >> chon;
		switch (chon)
		{
		case 1:
		{
			update();
			system("pause");
			break;
		}
		case 2:
		{
			print();
			system("pause");
			break;
		}
		case 3:
		{

			if (search() == true)
			{   
				
				cout << "\nTIM THAY THANH CONG\n" << endl;

				
			}
			else {
			
				cout << "\nVAT TU NAY KHONG TON TAI\n" << endl;
				
			
			}system("pause");
			break;
				
		}
		system("pause");
		break;
		case 0:
		{
			
			exit(1);
			system("pause");
		}
		case 4:
		{
			int t = 0;

			if (BTHK() == true)
			{
				cout << "\n**************************************************************************************************" << endl;
				cout << "\nTIM THAY THANH CONG\n" << endl;
				cout << "CO CAN XUAT RA BANG THONG KE THANH FILE HAY KHONG(1:CO | 0:KHONG):" << endl;
				cin >> t;
				if (t == 1) {
					writeToFile(a, this->size);
					cout << "*************************XUAT FILE THANH CONG*************************" << endl;
				}
				else { system("pause"); }


			}
			else {
				cout << "\n**************************************************************************************************" << endl;
				cout << "VAT TU NAY KHONG TON TAI" << endl;

			}

			system("pause");
			break;
		}
		case 7:
		{
			del();
			system("pause");
			break;
		}
		case 5:
		{
			sort();
			system("pause");
			break;
		}

		}
	} while (chon != 0);
}

void List::ins()
{
	int k;
	cin >> k;
	vattu h;
	cout << "Nhap thong tin sach can them:";
	h.input();
	vattu* b = new vattu[this->size];
	for (int i = 0; i < this->size; i++)
	{
		b[i] = a[i];
	}

	a = new vattu[this->size + 1];
	for (int i = 0; i < this->size; i++)
	{
		a[i] = b[i];
	}
	for (int i = this->size; i >= k; i--)
	{
		a[i] = b[i - 1];
	}
	a[k - 1] = h;
	this->size = size + 1;
	delete[] b;
	print();
}

void List::del()
{
	if (this->size == 1)
	{
		cout << "Xoa thanh cong,Ban da xoa het Doi Toung" << endl;
		this->size--;
		system("pause");
	}
	else
	{
		for (int i = 0; i < this->size - 1; i++)
		{
			*(this->a + i) = *(this->a + i + 1);
		}
		this->size--;
	}
}

void List::tinh()
{
	long thanhtien = 0;
	for (int i = 0; i < this->size; i++)
	{
		if (a[i].sl > 200)
		{
			
			thanhtien = thanhtien + a[i].DG * a[i].sl * 0.25;
		}
		else if (a[i].sl > 100 && a[i].sl <= 200)
		{
			
			thanhtien = thanhtien + a[i].DG * a[i].sl * 0.1;
		}
		else if (a[i].sl <= 100)
		{
			
			thanhtien = thanhtien + a[i].DG * a[i].sl;
		}
		cout << endl;
	}
	cout << "Tong tien=" << thanhtien << endl;
}

void List::sort()
{
	bool t = true;
	while (t)
	{
		int choose;
		cout << "\n******************************MENU******************************";
		cout << "\n*          Chon loai sap xep can thuc hien :                   *";
		cout << "\n*          1. Sap xep theo ngay nhap .                         *";
		cout << "\n*          2. Sap xep theo ten vat tu .                        *";
		cout << "\n*          3. Sap xep theo so luong .                          *";
		cout << "\n*          4. Sap xep theo don gia .                           *";
		cout << "\n*          0. Ve menu chinh .                                  *";
		cout << "\n****************************************************************";
		cout << "\nchon loai sap xep : ";
		cin >> choose;
		if (choose < 0 || choose > 4)
			cout << "\nchon chua hop le, chon lai .";
		switch (choose)
		{
		case 0:
			t = false;
			break;
		case 1:
		{
			int choose;
			cout << "\n******************************MENU******************************";
			cout << "\n*          Sap xep theo so luong :                             *";
			cout << "\n*          1. Tang .                                           *";
			cout << "\n*          2. Giam .                                           *";
			cout << "\n****************************************************************";
			cout << "\nchon phuong thuc : ";
			cin >> choose;
			switch (choose)
			{
			case 1:
			{
				sapxeptheongaynhap(this->a, 1, this->size);
				break;
			}
			case 2:
			{
				sapxeptheongaynhap(this->a, 2, this->size);
				break;
			}
			default:
			{
				cout << "Chon lai .";
				system("pause");
				break;
			}
			}
			break;
		}
		case 2:
		{

			break;
		}
		case 3:
		{
			int choose;
			cout << "\n******************************MENU******************************";
			cout << "\n*          Sap xep theo so luong :                             *";
			cout << "\n*          1. Tang .                                           *";
			cout << "\n*          2. Giam .                                           *";
			cout << "\n****************************************************************";
			cout << "\nchon phuong thuc : ";
			cin >> choose;
			switch (choose)
			{
			case 1:
			{
				sapxeptheosl(this->a, 1, this->size);
				break;
			}
			case 2:
			{
				sapxeptheosl(this->a, 2, this->size);
				break;
			}
			default:
			{
				cout << "Chon lai .";
				system("pause");
				break;
			}
			}
			break;
		}
		case 4:
		{
			int choose;
			cout << "\n******************************MENU******************************";
			cout << "\n*          Sap xep theo don gia :                              *";
			cout << "\n*          1. Tang .                                           *";
			cout << "\n*          2. Giam .                                           *";
			cout << "\n****************************************************************";
			cout << "\nchon phuong thuc : ";
			cin >> choose;
			switch (choose)
			{
			case 1:
			{
				sapxeptheodongia(this->a, 1, this->size);
				break;
			}
			case 2:
			{
				sapxeptheodongia(this->a, 2, this->size);
				break;
			}
			default:
			{
				cout << "Chon lai .";
				system("pause");
				break;
			}
			}
			break;
		}
		}
	}
}

void List::printLine(int n)
{
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << "_";
	}
	cout << endl;
}

bool List::BTHK()
{
	string l;
	long total=0;
	bool isExist = false;
	int stt = 0;
	cout << "Nhap loai vat tu can thong ke:";
	cin.ignore();
	getline(cin, l);
	cout << endl;
	string L = To_upper(l);
	string LOAI;
	cout << "**************************************************************************************************" << endl;
			cout << setw(25) << right << "BANG THONG KE" << endl;
			cout << " " << endl;
			cout << setw(5) << left << "STT";
			cout << setw(30) << left << "TEN VAT TU";
			cout << setw(10) << left << "LOAI";			
			cout << setw(20) << left << "SO LUONG";
			cout << setw(20) << left << "DON GIA";
			cout << setw(20) << left << "THANH TIEN";
			cout << endl;
			for (int i = 0; i < this->size; i++)
			{
				LOAI = To_upper(a[i].loai);


				if (L.compare(LOAI) == 0)
				{
					stt++;
					cout << setw(5) << left << stt;
					cout << setw(30) << left << a[i].ten;
					cout << setw(10) << left << a[i].loai;
					cout << setw(20) << left << a[i].sl;
					cout << setw(20) << left << a[i].DG;

					if (a[i].sl > 200)
					{

						total = total + a[i].DG * a[i].sl * 0.25;
					}
					else if (a[i].sl > 100 && a[i].sl <= 200)
					{

						total = total + a[i].DG * a[i].sl * 0.1;
					}
					else if (a[i].sl <= 100)
					{

						total = total + a[i].DG * a[i].sl;
					}

					cout << setw(20) << left << total;
					total = 0;
					cout << endl;

					isExist = true;
				}
			}
	
			return isExist;

}

// End code by Huy
List::~List()
{
	delete[] this->a;
}
