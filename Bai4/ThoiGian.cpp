#include<iostream>
#include "ThoiGian.h"

using namespace std;

/*
Đầu vào: Không có
Đầu ra: Không có
Chức năng: Nhập giờ phút giây và kiểm tra có hợp lệ không 
*/
void ThoiGian::Nhap()
{
    while(true)
    {
        cin >> iGio >> iPhut >> iGiay;

        if(cin.fail() || cin.peek() != '\n')
        {
            cout << "Dữ liệu nhập sai vui lòng nhập lại: ";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if(iGio < 0 || iGio >= 24 || iPhut < 0 || iPhut >= 60 || iGiay < 0 || iGiay >= 60) //Mặc định 24h là 0h
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
Chức năng: In giờ phút giây
*/
void ThoiGian::Xuat()
{
    if(iGio < 10) cout << "0";
    cout << iGio << ":";

    if(iPhut < 10) cout << "0";
    cout << iPhut << ":";

    if(iGiay < 10) cout << "0";
    cout << iGiay << "\n";
}

/*
Đầu vào: Không có đầu vào
Đầu ra: Thời gian sau khi cộng thêm 1 giây vào (Kiểu ThoiGian)
Chức năng: Cộng 1 giây vào thời gian hiệ tại
*/
ThoiGian ThoiGian::TinhCongThemMotGiay()
{
    ThoiGian next = *this;
    next.iGiay++; 
    if(next.iGiay == 60)
    {
        next.iGiay = 0;
        next.iPhut++;
        if(next.iPhut == 60)
        {
            next.iPhut = 0;
            next.iGio++;
            if(next.iGio == 24)
            {
                next.iGio = 0;
            }
        }
    }
    return next;
}
