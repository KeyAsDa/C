#include <iostream>
#include <fstream>
#include <string>
#define M 20
using namespace std;

struct Product
{
    int id;
    string ten;
    double gia;
    int soLuong;
};

struct Item
{
    Product* p;
    int next;
};

struct HashTable
{
    Item h[M];
    int r;
};


void init(HashTable& t)
{
    for(int i = 0; i < M; i++)
    {
        t.h[i].p = NULL;
        t.h[i].next = -1;
    }
    t.r = M - 1;
}

int hashFunc(int id)
{
    return id % M;
}

void add(HashTable& t, Product* p)
{
    int idx = hashFunc(p->id);
    if(t.h[idx].p == NULL)
        t.h[idx].p = p;
    else
    {
        if(t.h[idx].p->id == p->id)
            t.h[idx].p->soLuong++;
        else
        {
            bool flag = false;
            while(t.h[idx].next != -1 && flag == false)
            {
                idx = t.h[idx].next;
                if(t.h[idx].p->id == p->id)
                {
                    t.h[idx].p->soLuong++;
                    flag = true;                    
                }
            }
            if(flag == false)
            {
                t.h[t.r].p = p;
                t.h[idx].next = t.r;
            }
            while(t.r >= 0 && t.h[t.r].p != NULL)
                t.r--;
        }
    }
}

void show(HashTable t)
{
    for(int i = 0; i < M; i++)
    {
        if(t.h[i].p != NULL)
        {
            cout << t.h[i].p->id << " : " << t.h[i].p->ten << " ---> " << t.h[i].p->gia << " VND : " << t.h[i].p->soLuong << endl; 
        }
    }
}

void SanPham(Product* product[])
{
    int count = 0;
    ifstream f;
    f.open("giohang.txt", ios::in);
    while(!f.eof())
    {
        Product* p = new Product;
        f >> p->id;
        f.ignore();
        getline(f, p->ten);
        f >> p->gia;
        f.ignore();
        p->soLuong = 1;
        product[count++] = p; 
    }
    f.close();
}

int main()
{
    HashTable t;
    init(t);
    Product** product = new Product* [M];
    SanPham(product);
    add(t, product[0]);
    add(t, product[1]);
    add(t, product[2]);
    add(t, product[1]);
    show(t);
    delete [] product;
    return 0;
}