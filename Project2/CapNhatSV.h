#pragma once
#include "SinhVien.h"
#include "NhapSinhVien.h"
#include <string>

// CẬP NHẬT SINH VIÊN THEO MSSV
void capNhatSV(DanhSach& ds)
{
	bool flag = false;
	string MSSV;
	cout << "Nhap MSSV cua sinh vien can thay doi: ";
	cin >> MSSV;
	for (int i = 0; i < ds.sv.size(); i++)
	{
		if (ds.sv[i].MSSV.find(MSSV) != -1)
		{
			flag = true;
			cout << "== CAP NHAT THONG TIN SINH VIEN THU " << i << " ==" << endl;
			nhap1SV(ds.sv[i]);
			cout << endl << "CAP NHAT THANH CONG" << endl;
			break;
		}
	}
	if(flag == false)
		cout << "KHONG CO SINH VIEN NAY" << endl;
}