#include<iostream>
#include <cmath>
#include "SoPhuc.h"

using namespace std;

/*
Đầu vào: Không có
Đầu ra: Không có
Chức năng: Nhập dữ liệu từ bàn phím và kiểm tra dữ liệu hợp lệ chưa
*/
void SoPhuc::Nhap()
{
    while(true)
    {
        cin >> iThuc >> iAo;
        if (cin.fail() || cin.peek() != '\n')
        {
            cout << "Dữ liệu nhập sai vui lòng nhập lại: ";
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
Chức năng: In ra số phức
*/
void SoPhuc::Xuat(){
    cout << iThuc;
    if(iAo > 0)
    {
        if(iAo != 1)
            cout << " + " << iAo << "i" << "\n";
        else
            cout << " + i" << "\n";
    }
    else if(iAo < 0)
    {
        if(iAo != -1)
            cout << " - " << abs(iAo) << "i" << "\n";
        else
            cout << " - i" << "\n";
    }
    else
        cout << "\n";
}

/*
Đầu vào: Một số phức (other) kiểu SoPhuc
Đầu ra: Một số phức (tmp) kiểu SoPhuc là kết quả của tổng 2 số phức other và số phức gốc đã gọi hàm
Chức năng: Cộng hai số phức
*/
SoPhuc SoPhuc::TinhTong(const SoPhuc &other){
    SoPhuc tmp;

    tmp.iThuc = iThuc + other.iThuc;
    tmp.iAo = iAo + other.iAo;

    return tmp;
}

/*
Đầu vào: Một số phức (other) kiểu SoPhuc
Đầu ra: Một số phức (tmp) kiểu SoPhuc là kết quả của hiệu 2 số phức other và số phức gốc đã gọi hàm
Chức năng: Trừ hai số phức
*/
SoPhuc SoPhuc::TinhHieu(const SoPhuc &other){
    SoPhuc tmp;

    tmp.iThuc = iThuc - other.iThuc;
    tmp.iAo = iAo - other.iAo;

    return tmp;
}

/*
Đầu vào: Một số phức (other) kiểu SoPhuc
Đầu ra: Một số phức (tmp) kiểu SoPhuc là kết quả của tích 2 số phức other và số phức gốc đã gọi hàm
Chức năng: Nhân hai số phức
*/
SoPhuc SoPhuc::TinhTich(const SoPhuc &other){
    SoPhuc tmp;

    tmp.iThuc = iThuc * other.iThuc - iAo * other.iAo;
    tmp.iAo = iThuc * other.iAo + iAo * other.iThuc;

    return tmp;
}

/*
Đầu vào: Một số phức (other) kiểu SoPhuc, và một số phức result để lưu kết quả
Đầu ra: true hoặc false cho biết có chia được không
Chức năng: Chia hai số phức và lưu kết quả vào result nếu chia được
*/

bool SoPhuc::TinhThuong(const SoPhuc &other, SoPhuc &result)
{
    if (other.iThuc == 0 && other.iAo == 0)
    {
        return false;
    }

    result.iThuc = (iThuc * other.iThuc + iAo * other.iAo) / (other.iThuc * other.iThuc + other.iAo * other.iAo);
    result.iAo = (iAo * other.iThuc - iThuc * other.iAo)  / (other.iThuc * other.iThuc + other.iAo * other.iAo);

    return true;
}