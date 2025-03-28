#include <iostream>
#define BULEN 10
using namespace std;


int main(int argc, char *argv[])
{
    int arr[BULEN];
    int *p;
    int a, i;

    for (i = 0; i < BULEN; i++)
    {
        arr[i] = 10 - i;
    }
    a = 5;
    p = &a;

    cout << "arr[2] = " << arr[2] << endl;
    cout << "arr+2 = " << arr+2 << endl;
    cout << "*(arr+2) = " << *(arr+2) << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;

    return 0;
}