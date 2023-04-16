#pragma once
#include "SinhVien.h"
#include <string>
#include "XuatSinhVien.h"

// TÌM KIẾM SINH VIÊN THEO TÊN
void timKiem(DanhSach ds)
{
	int n = ds.sv.size();
	string name;
	int count = 0;

	// khai báo mảng động chứa các giá trị tìm được
	SinhVien* a = new SinhVien[n];

	cout << "Nhap ten sinh vien can tim: ";
	cin.ignore();
	getline(cin, name);

	for (int i = 0; i < ds.sv.size(); i++)
	{
		if (ds.sv[i].hoTen.find(name) != -1) 
		{
			a[count++] = ds.sv[i];
		}
	}

	if (count != 0)
	{
		cout << endl << "=== DANH SACH SINH VIEN TIM DUOC ===" << endl;
		for (int i = 0; i < count; i++)
		{
			xuat1SV(a[i]);
		}
		cout << endl;
	}
	else
		cout << "KHONG CO SINH VIEN NAO DUOC TIM THAY" << endl;
	delete[] a;
}