#include<iostream>
#include <Windows.h>
#include "ThoiGian.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(65001); //Ép thành phông UTF-8 trong trường hợp compile bị lỗi phông chữ

    ThoiGian t, next;

    cout << "Nhập giờ phút giây: ";
    t.Nhap();

    cout << "\nThời gian vừa nhập: ";
    t.Xuat();

    next = t.TinhCongThemMotGiay();

    cout << "\nThời gian sau khi cộng 1 giây: ";
    next.Xuat();

    return 0;
}