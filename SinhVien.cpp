#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#define SO_MON 3
using namespace std;

struct SinhVien
{
    string MSSV;
    string hoTen;
    char queQuan[50];
    double diem[SO_MON];
};

struct DanhSach
{
    SinhVien *sv;
    int n;
};

void nhap1SinhVien(SinhVien& sv)
{
    cout << "MSSV: ";
    cin >> sv.MSSV;
    cin.ignore();
    cout << "Ho ten: ";
    getline(cin, sv.hoTen);
    cout << "Que quan: ";
    cin.getline(sv.queQuan, 50);
    for(int i = 0; i < SO_MON; i++)
    {
        cout << "Diem mon " << i + 1 << ": ";
        cin >> sv.diem[i];
    }
}

void xuat1SinhVien(const SinhVien sv)
{
    cout << "MSSV: " << sv.MSSV << endl;
    cout << "Ho ten: " << sv.hoTen << endl;
    cout << "Que quan: " << sv.queQuan << endl;
    for(int i = 0; i < SO_MON; i++)
    {
        cout << sv.diem[i] << "\t";
    }
    cout << endl;
}

void nhapDanhSach(DanhSach& ds)
{
    cout << "Nhap so luong sinh vien: ";
    cin >> ds.n;
    ds.sv = new SinhVien[ds.n];
    for(int i = 0; i < ds.n; i++)
    {
        cout << "== SINH VIEN THU " << i + 1 << " ==" << endl;
        nhap1SinhVien(ds.sv[i]);
    }
}

void docDanhSach(DanhSach& ds)
{
    ifstream f;
    f.open("sinhvien.txt", ios::in);
    f >> ds.n;
    f.ignore();
    ds.sv = new SinhVien[ds.n];
    for(int i = 0; i < ds.n; i++)
    {
        getline(f, ds.sv[i].MSSV, '#');
        getline(f, ds.sv[i].hoTen, '#');
        f.getline(ds.sv[i].queQuan, 50, '#');
        for(int j = 0; j < SO_MON; j++)
        {
            f >> ds.sv[i].diem[j];
            f.ignore();
        }
    }
    f.close();
}

void xuatDanhSach(const DanhSach ds)
{
    for(int i = 0; i < ds.n; i++)
    {
        xuat1SinhVien(ds.sv[i]);
        cout << "-----------" << endl;
    }
}

DanhSach timKiem(const DanhSach ds, string tuKhoa)
{
	DanhSach kq;
	kq.n = 0;
	kq.sv = new SinhVien[ds.n];
	for(int i = 0; i < ds.n; i++)
	{
		if(ds.sv[i].hoTen.find(tuKhoa) != -1)
		{
			kq.sv[kq.n++] = ds.sv[i];
		}
	}
	return kq;
}

DanhSach timKiem(const DanhSach ds, char tuKhoa[])
{
	DanhSach kq;
	kq.n = 0;
	kq.sv = new SinhVien[ds.n];
	for(int i = 0; i < ds.n; i++)
	{
		if(strstr(ds.sv[i].queQuan, tuKhoa) != NULL)
		{
			kq.sv[kq.n++] = ds.sv[i];
		}
	}
	return kq;
}

void swap(SinhVien& s1, SinhVien& s2)
{
    SinhVien s = s1;
    s1 = s2;
    s2 = s;
}

void sapXepTang(DanhSach& ds)
{
    for(int i = 0; i < ds.n - 1; i++)
    {
        for(int j = i + 1; j < ds.n; j++)
        {
            if(ds.sv[i].hoTen > ds.sv[j].hoTen)
                swap(ds.sv[i], ds.sv[j]);
        }
    }
}

double dtb(const SinhVien s)
{
    double tong = 0;
    for(int i = 0; i < SO_MON; i++)
        tong += s.diem[i];
    return tong / SO_MON;
}

bool kt1SvTb(const SinhVien s)
{
    double tong = 0;
    for(int i = 0; i < SO_MON; i++)
    {
        if(s.diem[i] < 5)
            return false;
        tong += s.diem[i];
    }
    return tong / SO_MON >= 7.5;
}

DanhSach ktTb(const DanhSach ds)
{
    DanhSach kq;
    kq.n = 0;
    kq.sv = new SinhVien[ds.n];
    for(int i = 0; i < ds.n; i++)
    {
        if(kt1SvTb(ds.sv[i]) == true)
            kq.sv[kq.n++] = ds.sv[i];
    }
    return kq;
}

void ghiHb(const DanhSach ds)
{
    ofstream f;
    f.open("hb.txt", ios::out);
    for(int i = 0; i < ds.n; i++)
    {
        f << ds.sv[i].MSSV << " - " << ds.sv[i].hoTen << endl;
        for(int j = 0; j < SO_MON; j++)
        {
            f << ds.sv[i].diem[j] << "\t";
        }
        f << " ---> " << dtb(ds.sv[i]) << endl;
    }
    f.close();
}

int main()
{
    DanhSach ds;
    docDanhSach(ds);
    xuatDanhSach(ds);
    ghiHb(ds);
    delete [] ds.sv;
    return 0;
}
