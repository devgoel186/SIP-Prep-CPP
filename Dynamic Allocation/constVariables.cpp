#include <iostream>
using namespace std;

int main()
{
    int j = 12;
    const int *p = &j;
    j++;
    cout << j << endl;
    (*p)++; // This gives error
    cout << *p << endl;
}