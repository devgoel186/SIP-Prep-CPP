#include <iostream>
using namespace std;

int main()
{
    int *p = new int;
    *p = 10;
    cout << *p << endl;

    // for the below loop, manual release of memory is required
    // because dynamic memory is not released automatically on
    // basis of scope of variables
    while (true)
    {
        int *p = new int;
    }
}