#include<iostream>
#include <Windows.h> //Thư viện dùng để dùng hàm chuyển phông chữ
#include "PhanSo.h"

using namespace std;


int main()
{
    SetConsoleOutputCP(65001); //Ép thành phông UTF-8 trong trường hợp compile bị lỗi phông chữ

    PhanSo a, b, c;

    cout<<"Nhập phân số a: ";
    a.Nhap(); a.RutGon();
    cout<<"Nhập phân số b: ";
    b.Nhap(); b.RutGon();

    cout << "\nPhân số a: ";
    a.Xuat();
    cout << "Phân số b: ";
    b.Xuat();

    cout << "\nTổng 2 phân số: ";
    c = a.TinhTong(b);
    c.Xuat();

    cout << "Hiệu 2 phân số: ";
    c = a.TinhHieu(b);
    c.Xuat();

    cout << "Tích 2 phân số: ";
    c = a.TinhTich(b);
    c.Xuat();

    if(a.TinhThuong(b, c))
    {
        cout << "Thương 2 phân số: ";
        c.Xuat();
    }
    else
    {
        cout << "Không thể chia!\n";
    }

    int cmp = a.SoSanh(b);

    if(cmp == 1)
        cout << "a > b";
    else if(cmp == -1)
        cout << "a < b";
    else
        cout << "a = b";
    
    return 0;
}