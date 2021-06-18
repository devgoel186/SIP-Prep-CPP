#include <iostream>
using namespace std;

int main()
{
    int i = 10;
    int *p = &i;

    cout << p << endl;
    p += 2;
}
