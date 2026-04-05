#include<iostream>
#include<algorithm>
#include <numeric>
#include "PhanSo.h"

using namespace std;

/*
Đầu vào: Không có
Đầu ra: Không có
Chức năng: Nhập dữ liệu từ bàn phím và kiểm tra dữ liệu hợp lệ chưa
*/
void PhanSo::Nhap()
{
    while(true)
    {
        cin >> iTu >> iMau;
        if(iMau == 0 || cin.fail() || cin.peek() != '\n')
        {
            cout << "Dữ liệu nhập sai. Vui lòng nhập lại: ";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        break;
    }
}

/*
Đầu vào: Không có
Đầu ra: Không có
Chức năng: Rút gọn và chuẩn hóa lại dấu phân số
*/
void PhanSo::RutGon()
{
    if(iMau < 0)
    {
        iTu = -iTu;
        iMau = -iMau;
    }
    int g = gcd(abs(iTu), abs(iMau));
    iTu = iTu / g;
    iMau = iMau / g;
}

/*
Đầu vào: Không có
Đầu ra: Không có
Chức năng: In phân số
*/
void PhanSo::Xuat()
{
    if(iTu == 0)
        cout << 0 << "\n";
    else if(iMau == 1)
        cout << iTu << "\n";
    else
        cout << iTu << "/" << iMau << "\n";
}

/*
Đầu vào: Một phân số (other) kiểu PhanSo
Đầu ra: Một phân số (tmp) kiểu PhanSo là kết quả của tổng 2 phân số other và phân số gốc đã gọi hàm
Chức năng: Cộng hai phân số
*/
PhanSo PhanSo::TinhTong(const PhanSo &other)
{
    PhanSo tmp;
    tmp.iTu = iTu * other.iMau + iMau * other.iTu;
    tmp.iMau = iMau * other.iMau;

    tmp.RutGon();
    return tmp;
}

/*
Đầu vào: Một phân số (other) kiểu PhanSo
Đầu ra: Một phân số (tmp) kiểu PhanSo là kết quả của hiệu 2 phân số other và phân số gốc đã gọi hàm
Chức năng: Trừ hai phân số
*/
PhanSo PhanSo::TinhHieu(const PhanSo &other)
{
    PhanSo tmp;
    tmp.iTu = iTu * other.iMau - iMau * other.iTu;
    tmp.iMau = iMau * other.iMau;

    tmp.RutGon();
    return tmp;
}

/*
Đầu vào: Một phân số (other) kiểu PhanSo
Đầu ra: Một phân số (tmp) kiểu PhanSo là kết quả của tích 2 phân số other và phân số gốc đã gọi hàm
Chức năng: Nhân hai phân số
*/
PhanSo PhanSo::TinhTich(const PhanSo &other)
{
    PhanSo tmp;
    tmp.iTu = iTu * other.iTu;
    tmp.iMau = iMau * other.iMau;

    tmp.RutGon();
    return tmp;
}

/*
Đầu vào: Một phân số (other) kiểu PhanSo, và một phân số result để lưu kết quả
Đầu ra: true hoặc false cho biết có chia được không
Chức năng: Chia hai phân số và lưu kết quả vào result nếu chia được
*/
bool PhanSo::TinhThuong(const PhanSo &other, PhanSo &result)
{
    if(other.iTu == 0)
        return false;

    result.iTu = iTu * other.iMau;
    result.iMau = iMau * other.iTu;

    result.RutGon();
    return true;
}

/*
Đầu vào: Một phân số (other) kiểu PhanSo
Đầu ra: Số nguyên biểu thị cho kết quả so sáng hai phân số
        1: >
        -1: <
        0: =
Chức năng: So sánh hai phân số
*/
int PhanSo::SoSanh(const PhanSo &other)
{
    int a_numer = iTu * other.iMau;
    int b_numer = other.iTu * iMau;
    if(a_numer > b_numer)
        return 1;
    else if(a_numer < b_numer)
        return -1;
    else
        return 0;
}
