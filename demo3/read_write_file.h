#include "vattu.h"
#include "MyString.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
//int convertStringToInt(string str) {
//    int resl;
//    stringstream geek(str);
//    geek >> resl;
//    return resl;
//}

bool isWhiteSpace(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

// Remove space at start, end
string removeSpaceSE(string s, string del = " ")
{
    int i = 0;
    int start, end;
    while (i < s.length()) {
        if (s.substr(i, i + 1) != " ") {
            start = i;
            i = s.length();
            break;
        }
        i++;
    }
    while (i >= 0) {
        if (s.substr(i - 1, i) != " ") {
            end = i;
            break;
        }
        i--;
    }
    return s.substr(start, end - start);
}

int numberOfLines() {
    ifstream myfile("dsvt.txt");
    string line;
    int number_of_lines = 0;

    if (myfile.is_open()) {
        while (!myfile.eof()) {
            getline(myfile, line);
            number_of_lines++;
        }
        myfile.close();
    }
    number_of_lines--;
    return number_of_lines;
}

void readGoodsFromFile(vattu* dsvt, int size) {
    ifstream filein;
    filein.open("dsvt.txt");
    for (int i = 0; i < size; i++) {
        vattu vt;
        string in;

        getline(filein, in, '|');
        vt.mvt = removeSpaceSE(in);

        getline(filein, in, '|');
        vt.ten = removeSpaceSE(in);

        getline(filein, in, '|');
        vt.loai = removeSpaceSE(in);

        getline(filein, in, '|');
        vt.DV = removeSpaceSE(in);

        getline(filein, in, '|');
        vt.ngay = convertStringToInt(in);

        getline(filein, in, '|');
        vt.thang = convertStringToInt(in);

        getline(filein, in, '|');
        vt.nam = convertStringToInt(in);

        getline(filein, in, '|');
        vt.nsx = removeSpaceSE(in);

        getline(filein, in, '|');
        vt.sl = convertStringToInt(in);

        getline(filein, in);
        vt.DG = convertStringToInt(in);

        dsvt[i] = vt;
    }
    filein.close();
}

void writeGoodsToFile(vattu* dsvt, int size) {
    fstream fileout;
    fileout.open("dsvt.txt", ios::out);
    for (int i = 0; i < size; i++)
    {
        fileout << (dsvt + i)->mvt << "|" << (dsvt + i)->ten << "|" << (dsvt + i)->loai << "|"
            << (dsvt + i)->DV << "| " << (dsvt + i)->ngay << " | " << (dsvt + i)->thang << " | "
            << (dsvt + i)->nam << " |" << (dsvt + i)->nsx << "| " << (dsvt + i)->sl << " | " << (dsvt + i)->DG << endl;
    }
    fileout.close();
}
void writeToFile(vattu* a, int size) {
    fstream fileout;
    int stt = 0;
    long total = 0;
    fileout.open("Bang_thong_ke.txt", ios::out);
    fileout << setw(35) << right << "BANG THONG KE" << endl;
    fileout << " " << endl;
    fileout << setw(5) << left << "STT";
    fileout << setw(30) << left << "TEN VAT TU";
    fileout << setw(10) << left << "LOAI";
    fileout << setw(20) << left << "SO LUONG";
    fileout << setw(20) << left << "DON GIA";
    fileout << setw(20) << left << "THANH TIEN";
    fileout << endl;

    for (int i = 0; i < size; i++)
    {
        /*fileout <<  (dsvt + i)->ten << "|" << (dsvt + i)->loai << "|"
             <<   (dsvt + i)->sl << " | " << (dsvt + i)->DG << endl;*/
     
          
                stt++;
                fileout << setw(5) << left << stt;
                fileout << setw(30) << left << a[i].ten;
                fileout << setw(10) << left << a[i].loai;
                fileout << setw(20) << left << a[i].sl;
                fileout << setw(20) << left << a[i].DG;

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

                fileout << setw(20) << left << total;
                total = 0;
                fileout << endl;

               
            
        }
    
    fileout.close();
}