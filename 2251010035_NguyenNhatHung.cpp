#include <iostream>
#include <ctime>
#include <Windows.h>
#include <cmath>
#define MAX 50
using namespace std;

// RANDOM TRONG KHOẢNG [MIN;MAX]
int get(int min, int max)
{
    return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}

// NHẬP 10 GIÁ TRỊ ĐẦU CỦA MẢNG
void nhap10GiaTriDau(int a[])
{
    // NHẬP 10 GIÁ TRỊ ĐẦU
    for(int i = 0; i < 10; i++)
    {
        do
        {
            cout << "a[" << i << "] = ";
            cin >> a[i];
            if(a[i] < -200 || a[i] > 100)
                cout << "Nhap gia tri trong khoang [-200;100]" << endl;            
        } while (a[i] < -200 || a[i] > 100);
    }
}

// RANDOM 40 GIÁ TRỊ CUỐI
void random40GiaTriCuoi(int a[])
{
    srand((unsigned int)time(NULL));
    for(int i = 10; i < MAX; i++)
    {
        a[i] = get(-100, 200);
        while(a[i] >= -17 &&  a[i] <= 17)
        {
            a[i] = get(-100, 200);
        }
    }
}

// HÀM TÌM SỐ NGUYÊN TỐ
bool timSoNguyenTo(int n)
{
    if(n >= 2)
    {
        for(int i = 2; i <= sqrt(n); i++)
        {
            if(n % i == 0)
                return false;
        }
        return true;
    }
    else
        return false;
}

//HÀM TÌM SỐ CÓ TỔNG CÁC CHỮ SỐ LÀ SỐ CHẴN
int timSo(int n)
{
    int bien;
    int tong = 0;
    while(n != 0)
    {
        bien = n % 10;
        tong = tong + bien;
        n = n / 10;
    }
    return tong;
}

//SẮP XẾP MẢNG GIẢM DẦN
void mangGiamDan(int a[])
{
    for(int i = 0; i < MAX - 1; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            if(a[i] > a[j])
            {
                int c = a[i];
                a[i] = a[j];
                a[j] = c;
            }
        }
    }
}

// TẠO MENU
void Menu()
{
    cout << "1. Xuat 50 phan tu, moi hang 10 phan tu" << endl;
    cout << "2. Trung binh cong cua 50 phan tu trong mang" << endl;
    cout << "3. Xuat so am chan va so duong le" << endl;
    cout << "4. Xuat cac thong tin sau: " << endl;
    cout << "   + Tong 50 phan tu" << endl;
    cout << "   + Trung binh cong 50 phan tu" << endl;
    cout << "   + Co bao nhieu so duong? So am? So 0? So chan? So le? So nguyen to?" << endl;
    cout << "   + Co bao nhieu so hang don vi? Hang chuc? Hang tram?" << endl;
    cout << "   + Co bao nnhieu so tron chuc? So tron tram" << endl;
    cout << "   + Co bao nhieu so co tong cac chu so la so chan" << endl;
    cout << "5. Sap xep mang A giam dan" << endl;
    cout << "6. Dao nguoc mang A" << endl;
    cout << "7. Nhap 1 so va thong bao phan tu co trong mang hay khong ?, Xuat hien bao nhieu lan ?, o vi tri nao? " << endl;
    cout << "8. Nhap lai thong tin mang A" << endl;
    cout << "9. Thoat" << endl;
}

// XỬ LÝ MENU
void xuLy(int n, int a[])
{
    switch (n)
    {

    //  XỬ LÝ YÊU CẦU 1
    case 1:
    {
        cout << "XUAT 50 PHAN TU, MOI HANG 10 PHAN TU" << endl;
        cout << endl;
        for(int i = 0; i < 5; i++)
        {
            for(int j = i * 10; j <= i * 10 + 9; j++)
            {
                cout << a[j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
        system("pause");
        system("cls");
        break;
    }

    // XỬ LÝ YÊU CẦU 2
    case 2:
    {
        int tong = 0;
        for(int i = 0; i < MAX; i++)
        {
            tong = tong + a[i];
        }
        cout << "Trung binh cong cua mang la: " << tong / MAX << endl;
        cout << endl;
        system("pause");
        system("cls");
        break;
    }

    // XỬ LÝ YÊU CẦU 3
    case 3:
    {
        // số âm chẵn và số dương lẻ
        int chan = 0;
        int le = 0;
        cout << "So am chan trong mang la: ";
        for(int i = 0; i < MAX; i++)
        {
            if(a[i] % 2 == 0 && a[i] < 0 && a[i] != chan)
            {
                chan = a[i];
                cout << a[i] << "\t";
            }
        }
        cout << endl;
        cout << "So duong le trong mang la: ";
        for(int i = 0; i < MAX; i++)
        {
            if(a[i] > 0 && a[i] % 2 != 0 && a[i] != le)
            {
                le = a[i];
                cout << a[i] << "\t";
            }
        }
        cout << endl << endl;
        system("pause");
        system("cls");
        break;
    }

    // XỬ LÝ YÊU CẦU 4
    case 4:
    {
        int tong = 0;
        int khong = 0;
        int duong = 0;
        int am = 0;
        int chan = 0;
        int le = 0;
        int soNguyenTo = 0;
        int soTronChuc = 0;
        int soTronTram = 0;
        int tongSo = 0;
        // tổng 50 phần tử
        cout << "Tong 50 phan tu = ";
        for(int i = 0; i < MAX; i++)
        {
            tong = tong + i;
        }
        cout << tong << endl << endl;
        // trung bình cộng
        cout << "Trung binh cong 50 phan tu = " << (tong / MAX) << endl << endl;
        // số dương, số âm, số 0, 

        for(int i = 0; i < MAX; i++)
        {
            if(a[i] > 0)
                duong = duong + 1;
            else if(a[i] < 0)
                am = am + 1;
            else
                khong = khong + 1;
        } 
        cout << "So duong trong mang: ";
        cout << duong << endl << endl;
        cout << "So am trong mang: ";
        cout << am << endl << endl;
        cout << "So 0 trong mang: ";
        cout << khong << endl << endl;
        
        //số chắn, số lẻ
        cout << "So chan trong mang: ";
        for(int i = 0; i < MAX; i++)
        {
            if(a[i] % 2 == 0)
                chan = chan + 1;
            else
                le = le + 1;
        } 
        cout << chan << endl << endl;
        cout << "So le trong mang la: ";
        cout << le << endl << endl;

        // số nguyên tố
        cout << "So nguyen to trong mang la: ";
        for(int i = 0; i < MAX; i++)
        {
            if(timSoNguyenTo(a[i]) == true)
                soNguyenTo = soNguyenTo + 1;
        }
        cout << soNguyenTo << endl << endl;

        // số hàng đơn vị, hàng chục, hagf trăm

        // số tròn chục, số tròn trăm
        for(int i = 0; i < MAX; i++)
        {
            if(a[i] == 100 || a[i] == 200 || a[i] == 300 || a[i] == 400 || a[i] == 500 || a[i] == 600 || a[i] == 700 || a[i] == 800 || a[i] == 900)
                soTronTram = soTronTram + 1;
            if(a[i] == 10 || a[i] == 20 || a[i] == 30 || a[i] == 40 || a[i] == 50 || a[i] == 60 || a[i] == 70 || a[i] == 80 || a[i] == 90)
                soTronChuc = soTronChuc + 1;
        }
        cout << "So tron chuc trong mang la: " << soTronChuc << endl;
        cout << "So tron tram trong mang la: " << soTronTram << endl;
        cout << endl;

        //số có tổng các chữ số là số chẵn
        for(int i = 0; i < MAX; i++)
        {
            if(timSo(a[i]) % 2 == 0)
                tongSo = tongSo + 1;
        }
        cout << "So so co tong cac chu so la so chan la: " << tongSo << endl;
        cout << endl;

        system("pause");
        system("cls");
        break;
    }

    //XỬ LÝ YÊU CẦU 5
    case 5:
    {
        //sắp xếp mảng giảm dần
        int b[MAX];
        for(int i = 0; i < MAX; i++)
        {
            b[i] = a[i];
        }
        mangGiamDan(b);
        cout << "Mang khi chua sap xep: " << endl;
        for(int i = 0; i < MAX; i++)
        {
            cout << a[i] << "\t";
        }
        cout << endl << endl;
        cout << "Mang sau khi sap xep giam dan: " << endl;
        for(int i = 0; i < MAX; i++)
        {
            cout << b[i] << "\t";
        }
        cout << endl << endl;

        system("pause");
        system("cls");
        break;
    }

    //XỬ LÝ YÊU CẦU 6
    case 6:
    {
        //đảo ngược mảng
        int t;
        int b[MAX];
        for(int i = 0; i < MAX; i++)
        {
            b[i] = a[i];
        }
        for(int i = 0; i < MAX / 2; i++)
        {
            t = b[i];
            b[i] = b[MAX - 1 - i];
            b[MAX -1 - i] = t;
        }
        cout << "Mang ban dau: " << endl;
        for(int i = 0; i < MAX; i++)
        {
            cout << a[i] <<"\t";
        }
        cout << endl << endl;
        cout << "Mang sau khi dao nguoc: " << endl;
        for(int i = 0; i < MAX; i++)
        {
            cout << b[i] << "\t";
        }
        cout << endl << endl;

        system("pause");
        system("cls");
        break;
    }

    //XỬ LÝ YÊU CẦU 7
    case 7:
    {
        // tìm vị trí xuất hiện trong mảng
        int n;
        int times = 0;
        bool check = false;
        cout << "Nhap n = ";
        cin >> n;
        for(int i = 0; i < MAX; i++)
        {
            if(a[i] == n)
            {
                if(i >=1 && i <= 50)
                {
                    cout << "Xuat hien tai vi tri: " << i << endl;
                }
                times = times + 1;
                check = true;
            }
        }
        if(check == true)
        {
            cout << "Tong so lan xuat hien la: " << times << endl;
        }
        else
            cout << "Khong co gia tri trong mang" << endl;
        cout << endl;

        system("pause");
        system("cls");
        break;
    }

    //XỬ LÝ YÊU CẦU 8
    case 8:
    {
        //nhập lại thông tin mảng A
        cout << "Nhap lai thong tin mang A" << endl << endl;
        nhap10GiaTriDau(a);
        random40GiaTriCuoi(a);
        cout << endl;
        system("pause");
        system("cls");
        break;
    }

    //thoát chương trình
    case 9:
    {
        cout << "Tam biet" << endl;
        exit(1);
        break;
    }
    
    default:
        break;
    }
}

int main()
{
    int a[MAX], n;
    nhap10GiaTriDau(a);
    random40GiaTriCuoi(a);
    system("cls");
    do
    {
        do
        {
            Menu();
            cout << "Nhap yeu cau cua ban: ";
            cin >> n;
            if(n > 0 && n <= 9)
            {
                cout << "Dang xu ly yeu cau....." << endl;
                Sleep(2000);
                system("cls");
                xuLy(n, a);
            }
            else
            {
                cout << endl;
                cout << "Nhap sai yeu cau" << endl;
                cout << "Vui long nhap lai" << endl;
                Sleep(2000);
                system("cls");
            } 
        } while (n < 1 || n > 9);
    } while (1);
    return 0;
}