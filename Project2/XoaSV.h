#include "SinhVien.h"

void xoaSV(DanhSach& ds)
{
	bool flag = false;
	string MSSV;
	cout << "Nhap MSSV cua sinh vien can xoa: ";
	cin >> MSSV;
	for (int i = 0; i < ds.sv.size(); i++)
	{
		if (ds.sv[i].MSSV.find(MSSV) != -1)
		{
			flag = true;
			ds.sv.erase(ds.sv.begin() + i);
			cout << "== XOA SINH VIEN THANH CONG ==" << endl;
			break;
		}
	}
	if (flag == false)
		cout << "KHONG CO SINH VIEN NAY" << endl;
}
