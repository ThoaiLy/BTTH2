#include<iostream>
#include <cmath>

using namespace std;

class SoPhuc{
    private:
        double iThuc;
        double iAo;
    public:
        void Nhap();
        void Xuat();
        SoPhuc Tong(const SoPhuc &other);
        SoPhuc Hieu(const SoPhuc &other);
        SoPhuc Tich(const SoPhuc &other);
        SoPhuc Thuong(const SoPhuc &other);
};

void SoPhuc::Nhap()
{
    while(true)
    {
        cin >> iThuc >> iAo;
        if (cin.fail())
        {
            cout << "Dữ liệu nhập sai vui lòng nhập lại: ";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        break;
    }
}

void SoPhuc::Xuat(){
    cout << iThuc;
    if(iAo >= 0)
        cout << " + " << iAo << "i";
    else
        cout << " - " << fabs(iAo) << "i";
}

SoPhuc SoPhuc::Tong(const SoPhuc &other){
    SoPhuc tmp;

    tmp.iThuc = iThuc + other.iThuc;
    tmp.iAo = iAo + other.iAo;

    return tmp;
}

SoPhuc SoPhuc::Hieu(const SoPhuc &other){
    SoPhuc tmp;

    tmp.iThuc = iThuc - other.iThuc;
    tmp.iAo = iAo - other.iAo;

    return tmp;
}

SoPhuc SoPhuc::Tich(const SoPhuc &other){
    SoPhuc tmp;

    tmp.iThuc = iThuc * other.iThuc - iAo * other.iAo;
    tmp.iAo = iThuc * other.iAo + iAo * other.iThuc;

    return tmp;
}

SoPhuc SoPhuc::Thuong(const SoPhuc &other){
    SoPhuc tmp;

    if (other.iThuc == 0 && other.iAo == 0)
    {
        cout << "Không thể chia!\n";
    }

    cout << "\na / b = ";
    tmp.iThuc = (iThuc * other.iThuc + iAo * other.iAo) / (other.iThuc * other.iThuc + other.iAo * other.iAo);
    tmp.iAo = (iAo * other.iThuc - iThuc * other.iAo)  / (other.iThuc * other.iThuc + other.iAo * other.iAo);

    return tmp;
}

int main()
{
    SoPhuc a, b, c;
    cout << "Nhập số phức thứ nhất: ";
    a.Nhap();
    cout << "Nhập số phức thứ hai: ";
    b.Nhap();

    cout << "\na = ";
    a.Xuat();

    cout << "\nb = ";
    b.Xuat();

    cout << "\na + b = ";
    c = a.Tong(b);
    c.Xuat();

    cout << "\na - b = ";
    c = a.Hieu(b);
    c.Xuat();

    cout << "\na * b = ";
    c = a.Tich(b);
    c.Xuat();

    c = a.Thuong(b);
    c.Xuat();

    return 0;
}