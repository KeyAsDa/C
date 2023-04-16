#pragma once
#include "SinhVien.h"
#include "json.hpp"
#include <fstream>
using json = nlohmann::json;

void docFileSV(DanhSach& ds)
{
	ifstream f;
	f.open("DanhSachSinhVien.json");
	json jsonData;
	f >> jsonData;
	f.close();

	// gán dữ liêuj vào vecto 
	for (json& a : jsonData) {
		SinhVien s;
		s.MSSV = a["MSSV"];
		s.hoTen = a["hoTen"];
		s.gioiTinh = a["gioiTinh"];
		s.tuoi = a["tuoi"];
		s.diemTichLuy = a["diemTichLuy"];
		ds.sv.push_back(s);
	}
}