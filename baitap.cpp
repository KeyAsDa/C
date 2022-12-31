#include <iostream>
#define MAX 1000
using namespace std;

int Tong_N(int n)
{
    int tong = 0;
    for(int i = 0; i <= n; i++)
    {
        tong = tong + i;
    }
    return tong;
}

void He10_2(int n)
{
    int a[MAX];
    int top = -1;
    while(n != 0)
    {
        top++;
        int x = n % 2;
        a[top] = x;
        n = n / 2;
    }
    for(int i = top; i >= 0; i--)
    {
        cout << a[i];
    }
}

int Fibonanci(int n)
{
    int a1 = 0;
    int a2 = 1;
    int a;
    for(int i = 3; i <= n; i++)
    {
        a = a1 + a2;
        a1 = a2;
        a2 = a;
    }
    return a;
}
int main()
{
    return 0;
}