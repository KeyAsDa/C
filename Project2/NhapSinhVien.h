#include "SinhVien.h"
#include <string>

// nhập 1 sinh viên 
void nhap1SV(SinhVien& sv)
{
	cout << "MSSV: ";
	cin >> sv.MSSV;
	cout << "Ho va ten: ";
	cin.ignore();
	getline(cin, sv.hoTen);
	cout << "Gioi tinh: ";
	getline(cin, sv.gioiTinh);
	cout << "Tuoi: ";
	cin >> sv.tuoi;
	cout << "Diem tich luy: ";
	cin >> sv.diemTichLuy;
}

// nhập sinh viên
void nhapSV(DanhSach& ds)
{
	SinhVien s;
	cout << "Nhap so luong sinh vien: ";
	cin >> ds.soLuong;
	for (int i = 0; i < ds.soLuong; i++)
	{
		cout << "=== NHAP THONG TIN SINH VIEN THU " << i << " ===" << endl;
		nhap1SV(s);
		ds.sv.push_back(s);
	}
}
