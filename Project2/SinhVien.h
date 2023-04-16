#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct SinhVien
{
    string MSSV;
    string hoTen;
    string gioiTinh;
    int tuoi;
    double diemTichLuy;
};

struct DanhSach
{
    vector <SinhVien> sv;
    int soLuong;
};