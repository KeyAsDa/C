#include <iostream>
#include <ctime>
#include <cstdlib>
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

//XUẤT MẢNG VỪA TẠO
// void xuatMang(int a[])
// {
//     for(int i = 0; i < MAX; i++)
//     {
//         cout << a[i] << "\t";
//     }
// }

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
    case 1:
    {
        for(int i = 0; i < 5; i++)
        {
            for(int j = i * 10; j <= i * 10 + 9; j++)
            {
                cout << a[j] << "\t";
            }
        }
        cout << endl;
    
        break;
    }
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
                xuLy(n, a);
            }
            else
                cout << "Nhap sai yeu cau" << endl;
        } while (n < 1 || n > 9);
    } while (1);
    return 0;
}