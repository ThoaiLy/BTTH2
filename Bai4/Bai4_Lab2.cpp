#include<iostream>

using namespace std;

class ThoiGian{
    private:
        int iGio, iPhut, iGiay;
    public:
        void Nhap();
        void Xuat();
        ThoiGian TinhCongThemMotGiay();
};

void ThoiGian::Nhap()
{
    while(true)
    {
        cin >> iGio >> iPhut >> iGiay;

        if(iGio < 0 || iGio > 24 || iPhut < 0 || iPhut > 60 || iGiay < 0 || iGiay > 60)
        {
            cout << "Dữ liệu nhập sai vui lòng nhập lại: ";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        if(cin.fail())
        {
            cout << "Dữ liệu nhập sai vui lòng nhập lại: ";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        break;
    }
}

void ThoiGian::Xuat()
{
    if(iGio < 10) cout << "0";
    cout << iGio << ":";

    if(iPhut < 10) cout << "0";
    cout << iPhut << ":";

    if(iGiay < 10) cout << "0";
    cout << iGiay << "\n";
}

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

int main()
{
    ThoiGian t, next;

    cout << "Nhập giờ phút giây: ";
    t.Nhap();

    cout << "Thời gian vừa nhập: ";
    t.Xuat();

    next = t.TinhCongThemMotGiay();

    cout << "Thời gian sau khi cộng 1 giây: ";
    next.Xuat();

    return 0;
}