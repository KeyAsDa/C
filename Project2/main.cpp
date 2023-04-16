#include "taoMenu.h"
#include "docFileSV.h"
#include "GhiDuLieuVaoFile.h"
#include "XuatSinhVien.h"
#include "ThemSinhVien.h"
#include "CapNhatSV.h"
#include "XoaSV.h"
#include "TimKiem.h"
#include "SapXepSV.h"
#include <Windows.h>

void xuLy(int n, DanhSach& ds)
{
	switch (n)
	{
	case 1:
		cout << "== THEM SINH VIEN VAO DANH SACH ==" << endl;
		themSinhVien(ds);
		system("pause");
		system("cls");
		break;
	case 2:
		xuatSV(ds);
		cout << endl;
		capNhatSV(ds);
		ghiFile(ds);
		system("pause");
		system("cls");
		break;
	case 3:
		xuatSV(ds);
		cout << endl;
		xoaSV(ds);
		ghiFile(ds);
		system("pause");
		system("cls");
		break;
	case 4:
		xuatSV(ds);
		timKiem(ds);
		system("pause");
		system("cls");
		break;
	case 5:
		cout << "=== DANH SACH TRUOC KHI SAP XEP === " << endl << endl;
		xuatSV(ds);
		cout << endl;
		cout << "=== DANH SACH SAU KHI SAP XEP THEO DIEM === " << endl << endl;
		sapXepDTL(ds);
		xuatSV(ds);
		ghiFile(ds);
		system("pause");
		system("cls");
		break;
	case 6:
		cout << "=== DANH SACH TRUOC KHI SAP XEP === " << endl << endl;
		xuatSV(ds);
		cout << endl;
		cout << "=== DANH SACH SAU KHI SAP XEP THEO TEN === " << endl << endl;
		sapXepTen(ds);
		xuatSV(ds);
		ghiFile(ds);
		system("pause");
		system("cls");
		break;
	case 7:
		xuatSV(ds);
		system("pause");
		system("cls");
		break;
	case 8:
		cout << "Tam biet" << endl;
		exit(1);
		break;
	default:
		break;
	}
}

int main()
{
	DanhSach ds;
	int n;
	docFileSV(ds);
	do
	{
		do
		{
			menu();
			cout << "Nhap yeu cau cua ban: ";
			cin >> n;
			if (n < 1 || n > 8)
				cout << "Nhap sai, vui long nhap lai" << endl;
			else
			{
				cout << "Dang xu ly yeu cau....." << endl;
				Sleep(2000);
				system("cls");
				xuLy(n, ds);
			}
		} while (n < 1 || n > 8);
	} while (1);
	return 0;
}
