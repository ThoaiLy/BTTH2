#include<iostream>
#include<iomanip>
#include <Windows.h>
#include "SoPhuc.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(65001);

    SoPhuc a, b, c;
    cout << "Nhập số phức thứ nhất: ";
    a.Nhap();
    cout << "Nhập số phức thứ hai: ";
    b.Nhap();

    cout << "\nSố phức thứ nhất a = ";
    a.Xuat();

    cout << "Số phức thứ hai b = ";
    b.Xuat();

    cout <<"\na + b = ";
    c = a.TinhTong(b);
    c.Xuat();

    cout << "a - b = ";
    c = a.TinhHieu(b);
    c.Xuat();

    cout << "a * b = ";
    c = a.TinhTich(b);
    c.Xuat();

    if(a.TinhThuong(b, c))
    {
        cout << "a / b = ";
        cout << fixed << setprecision(2);
        c.Xuat();
    }
    else
        cout << "Không chia được!";

    return 0;
}