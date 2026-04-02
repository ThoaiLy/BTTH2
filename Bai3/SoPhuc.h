#pragma once

class SoPhuc{
    private:
        double iThuc;
        double iAo;
    public:
        void Nhap();
        void Xuat();
        SoPhuc TinhTong(const SoPhuc &other);
        SoPhuc TinhHieu(const SoPhuc &other);
        SoPhuc TinhTich(const SoPhuc &other);
        bool TinhThuong(const SoPhuc &other, SoPhuc &result);
};