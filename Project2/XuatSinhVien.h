#pragma once
#include "SinhVien.h"

// xuất 1 sinh viên
void xuat1SV(const SinhVien sv)
{
	cout << "MSSV: " << sv.MSSV << endl;
	cout << "Ho va ten: " << sv.hoTen << endl;
	cout << "Gioi tinh: " << sv.gioiTinh << endl;
	cout << "Tuoi: " << sv.tuoi << endl;
	cout << "Diem tich luy: " << sv.diemTichLuy << endl;
	cout << "-----------------------------------" << endl;
}

// xuất sinh viên
void xuatSV(DanhSach ds)
{
	int i = 0;
	// sử dụng for-each cho mảng hoặc các cấu trúc tương tự 
	for (SinhVien& data : ds.sv)
	{
		cout << "=== SINH VIEN THU " << i << " ===" << endl;
		xuat1SV(data);
		i++;
	}
}