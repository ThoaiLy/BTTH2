#pragma once

class PhanSo{
    private:
        int iTu;
        int iMau;
    public:
        void Nhap();
        void Xuat();
        void RutGon();
        PhanSo TinhTong(const PhanSo &other);
        PhanSo TinhHieu(const PhanSo &other);
        PhanSo TinhTich(const PhanSo &other);
        bool TinhThuong(const PhanSo &other, PhanSo &result);
        int SoSanh(const PhanSo &other);
};