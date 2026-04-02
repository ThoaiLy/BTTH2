#include "Ngay.h"
#include<iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(65001); //Ép thành phông UTF-8 trong trường hợp compile bị lỗi phông chữ

    Ngay cur, nextday;
    cout << "Nhập ngày hiện tại"
    << "\n" << "(Năm nhập trong khoảng [1800 - 2100]): ";
    cur.Nhap();

    cout << "\nNgày hiện tại là: ";
    cur.Xuat();

    cout << "\nNgày tiếp theo là: ";
    nextday = cur.TinhNgayThangNamTiepTheo();
    nextday.Xuat();

    return 0;
}