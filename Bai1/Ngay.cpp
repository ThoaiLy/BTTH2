#include <iostream>
#include "Ngay.h"

using namespace std;

/*
Đầu vào: Không có đầu vào
Đầu ra: Không có giá trị đầu ra
Chức năng: Nhập vào ngày tháng năm
*/
void Ngay::Nhap()
{
	while (true)
	{
		cin >> iNgay >> iThang >> iNam;
		if (cin.fail() || cin.peek() != '\n')
        {
            cout << "Dữ liệu nhập sai. Vui lòng nhập lại ngày hiện tại: ";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

		if (iNgay <= 0 || iThang <= 0 || iThang > 12 || iNam < 1800 || iNam > 2100 ) //Năm nhập chỉ giới hạn trong khoảng [1800 - 2100]
		{
			cout << "Dữ liệu nhập sai. Vui lòng nhập lại ngày hiện tại: ";
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}

		if (iThang == 2)
		{
			if ((iNam % 4 == 0 && iNam % 100 != 0) || iNam % 400 == 0)
			{
				if (iNgay > 29)
				{
					cout << "Dữ liệu nhập sai. Vui lòng nhập lại ngày hiện tại: ";
					cin.clear();
					cin.ignore(10000, '\n');
					continue;
				}
			}
			else
			{
				if (iNgay > 28)
				{
					cout << "Dữ liệu nhập sai. Vui lòng nhập lại ngày hiện tại: ";
					cin.clear();
					cin.ignore(10000, '\n');
					continue;
				}
			}
		}

		else if (iThang == 1 || iThang == 3 || iThang == 5 || iThang == 7 || iThang == 8 || iThang == 10 || iThang == 12)
		{
			if (iNgay > 31)
			{
				cout << "Dữ liệu nhập sai. Vui lòng nhập lại ngày hiện tại: ";
				cin.clear();
				cin.ignore(10000, '\n');
				continue;
			}
		}

		else
		{
			if (iNgay > 30)
			{
				cout << "Dữ liệu nhập sai. Vui lòng nhập lại ngày hiện tại: ";
				cin.ignore(10000, '\n');
				continue;
			}
		}

		break;
	}
}

/*
Đầu vào: Không có đầu vào
Đầu ra: Không có giá trị đầu ra
Chức năng: In ngày tháng năm
*/
void Ngay::Xuat() {
	cout << iNgay << "/" << iThang << "/" << iNam << "\n";
}

/*
Đầu vào: Không có đầu vào
Đầu ra: Ngày tiếp theo (Kiểu Ngay)
Chức năng: Tính toán ngày kế tiếp của ngày vừa nhập
*/
Ngay Ngay::TinhNgayThangNamTiepTheo()
{
	Ngay next = *this;
	if (next.iThang == 2)
	{
		if ((next.iNam % 4 == 0 && next.iNam % 100 != 0) || next.iNam % 400 == 0)
		{
			if (next.iNgay == 29)
			{
				next.iNgay = 1;
				next.iThang++;
			}
			else
				next.iNgay++;
		}
		else
		{
			if (next.iNgay == 28)
			{
				next.iNgay = 1;
				next.iThang++;
			}
			else
				next.iNgay++;
		}
	}
	else if (next.iThang == 1 || next.iThang == 3 || next.iThang == 5 || next.iThang == 7 || next.iThang == 8 || next.iThang == 10 || next.iThang == 12)
	{
		if (next.iThang == 12 && next.iNgay == 31)
		{
			next.iThang = 1;
			next.iNgay = 1;
			next.iNam++;
		}
		else if (next.iNgay == 31)
		{
			next.iThang++;
			next.iNgay = 1;
		}
		else
			next.iNgay++;
	}
	else
	{
		if (next.iNgay == 30)
		{
			next.iThang++;
			next.iNgay = 1;
		}
		else
			next.iNgay++;
	}
	return next;
}