#pragma once
#include <fstream>
#include "json.hpp"
#include "SinhVien.h"
#include "NhapSinhVien.h"
using json = nlohmann::json;

// THÊM SINH VIÊN VÀO FILE
void themSinhVien(DanhSach& ds)
{
	// MỞ FILE ĐỌC DỮ LIỆU
	ifstream inFile("DanhSachSinhVien.json");
	json student;
	inFile >> student;
	inFile.close();

	// THÊM DỮ LIỆU MỚI
	SinhVien sv;
	int n;
	cout << "NHAP SO LUONG SINH VIEN CAN THEM:";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		json data;
		nhap1SV(sv);
		data["MSSV"] = sv.MSSV;
		data["hoTen"] = sv.hoTen;
		data["gioiTinh"] = sv.gioiTinh;
		data["tuoi"] = sv.tuoi;
		data["diemTichLuy"] = sv.diemTichLuy;
		student.push_back(data);
		ds.sv.push_back(sv); //CẬP NHẬT VÀO VECTO SỐ LƯỢNG
	}

	// MỞ FILE GHI DỮ LIỆU MỚI VÀO
	ofstream outFile("DanhSachSinhVien.json");
	outFile << student.dump(4);
	outFile.close();
}