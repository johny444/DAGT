#include "vattu.h"
#include<string>
#include<iostream>
using namespace std;

bool vattu::input()
{
   /* cout << "-NHAP MA SO VAT TU:";
    cin >> mvt;
    cout << "-TEN VAT TU: ";
    cin >> ten;
    cout << "-LOAI:  ";
    cin >> loai;
    cout << "-DON VI TINH: ";
    cin >> DV;
    cout << "-NGAY NHAP:" << endl;
    cout << "NGAY:";
    cin >> ngay;
    cout << "THANG:";
    cin >> thang;
    cout << "NAM:";
    cin >> nam;
    cout << "-NHA SAN XUAT: ";
    cin >> nsx;
    cout << "-SO LUONG:  ";
    cin >> sl;
    cout << "-DON GIA: ";
    cin >> DG;*/

    cout << "-NHAP MA SO VAT TU:";
    cin.ignore();
    getline(cin, mvt);
    cout << "-TEN VAT TU: ";
    getline(cin, ten);
    cout << "-LOAI:  ";
    getline(cin, loai);
    cout << "-DON VI TINH: ";
    getline(cin, DV);
    cout << "-NHA SAN XUAT: ";
    getline(cin, nsx);
    try {
        cout << "-NGAY NHAP:" << endl;
        cout << "NGAY:";
        cin >> ngay;
        cout << "THANG:";
        cin >> thang;
        cout << "NAM:";
        cin >> nam;
        cout << "-SO LUONG:  ";
        cin >> sl;
        cout << "-DON GIA: ";
        cin >> DG;
    }
    catch (exception e) {
        cout << "Exception encounted. Please enter again (number)..." << endl;
        return false;
    }
    return true;


}

void vattu::output()
{   
    cout << "-MA SO VAT TU:" << mvt << endl;
    cout << "-TEN VAT TU:" << ten << endl;
    cout << "-LOAI:" << loai << endl;
    cout << "-DON VI TINH:" << DV << endl;
    cout << "-NGAY SAN XUAT:" << ngay << "/" << thang << "/" << nam << endl;
    cout << "-NHA SAN XUAT:" << nsx << endl;
    cout << "-SO LUONG:" << sl << endl;
    cout << "-DON GIA:" << DG << endl;




}



vattu::~vattu()
{
}

istream& operator>>(istream& i, vattu& v)
{
    cout << "NHAP MA SO VAT TU:";
    i >> v.mvt;
    cout << "TEN VAT TU: ";
    i >> v.ten;
    cout << "LOAI:  ";
    i >> v.loai;
    cout << "DON VI TINH: ";
    i >> v.DV;
    cout << "NGAY NHAP:" << endl;
    cout << "NGAY:";
    i >> v.ngay;
    cout << "THANG:";
    i >> v.thang;
    cout << "NAM:";
    i >> v.nam;
    cout << "NHA SAN XUAT: ";
    i >> v.nsx;
    cout << "SO LUONG:  ";
    i >> v.sl;
    cout << "DON GIA: ";
    i >> v.DG;


    return i;
    // TODO: insert return statement here
}

ostream& operator<<(ostream& o, const vattu& p)
{
    o << "-MA SO VAT TU:" << p.mvt << endl;
    o << "-TEN VAT TU:" << p.ten << endl;
    o << "-LOAI:" << p.loai << endl;
    o << "-DON VI TINH:" << p.DV << endl;
    o << "-NGAY SAN XUAT:" << p.ngay << "/" << p.thang << "/" << p.nam << endl;
    o << "-NHA SAN XUAT:" << p.nsx << endl;
    o << "-SO LUONG:" << p.sl << endl;
    o << "-DON GIA:" << p.DV << endl;

    // TODO: insert return statement here
    return o;
}
