#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;

struct Stack
{
    char a[MAX][MAX];
    int top;
};

void init(Stack& s)
{
    s.top = -1;
}

void push(Stack& s, char x[])
{
    strcpy(s.a[++s.top], x);
}

char* pop(Stack& s)
{
    return s.a[s.top--];
}

bool isEmpty(Stack s)
{
    return s.top < 0;
}

bool isFull(Stack s)
{
    return s.top == MAX;
}

bool check(char* p)
{
    return (strcmp(p, "+") == 0 || strcmp(p, "-") == 0 || strcmp(p, "*") == 0 || strcmp(p, "/") == 0);
}

void tinh(char x[])
{
    Stack s;
    init(s);
    int tong;
    char* p = strtok(x, " ");
    while(p != NULL)
    {
        if(check(p) == true)
        {
            int b = atoi(pop(s));
            int a = atoi(pop(s));
            if(strcmp(p, "+") == 0)
                tong = a + b;
            else if (strcmp(p, "-") == 0)
                tong = a - b;
            else if(strcmp(p, "*") == 0)
                tong = a * b;
            else if(strcmp(p, "/") == 0)
                tong = a / b;
            char q[MAX];
            sprintf(q, "%d", tong); // convert int to c_string
            push(s, q);
        }
        else
            push(s, p);
        p = strtok(NULL, " ");
    }
    cout << tong << endl;
}

int main()
{
    char s[] = "5 10 + 2 * 3 /";
    tinh(s);
    return 0;
}