#include <fstream>
#include "SinhVien.h"
#include "json.hpp"
using json = nlohmann::json;

void ghiFile(DanhSach ds)
{
	ifstream inFile("DanhSachSinhVien.json");
	json student;
	inFile >> student;
	inFile.close();

	student.clear();

	for (SinhVien& sv : ds.sv)
	{
		json data;
		data["MSSV"] = sv.MSSV;
		data["hoTen"] = sv.hoTen;
		data["gioiTinh"] = sv.gioiTinh;
		data["tuoi"] = sv.tuoi;
		data["diemTichLuy"] = sv.diemTichLuy;
		student.push_back(data);
	}

	ofstream outFile("DanhSachSinhVien.json");
	outFile << student.dump(4);
	outFile.close();
}
