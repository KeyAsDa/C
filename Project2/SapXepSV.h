#pragma once
#include "SinhVien.h"

//HÀM HOÁN ĐỔI
void swap(SinhVien& a, SinhVien& b)
{
	SinhVien x = a;
	a = b;
	b = x;
}

// SẮP XẾP SINH VIÊN THEO ĐIỂM TÍCH LŨY
void sapXepDTL(DanhSach& ds)
{
	for (int i = 0; i < ds.sv.size() - 1; i++)
	{
		for (int j = i + 1; j < ds.sv.size(); j++)
		{
			if (ds.sv[i].diemTichLuy < ds.sv[j].diemTichLuy)
				swap(ds.sv[i], ds.sv[j]);
		}
	}
}

// SẮP XẾP SINH VIÊN THEO TÊN
void sapXepTen(DanhSach& ds)
{

}