#include <iostream>
using namespace std;

// NOTES -
// NEVER RETURN THE REFERENCE OR A POINTER OF THE LOCAL
// VARIABLE OF A FUNCTION, AS AFTER RETURNING THE VALUE
// BECOMES GARBAGE, AND YOU ARE ESSENTIALLY POINTING TO
// A GARBAGE VALUE OR HAVE A GARBAG ADDRESS

void increment1(int *n)
{
    (*n)++;
}

void increment(int &n)
{
    n++;
}

int main()
{
    int i = 10;
    int &j = i;

    increment1(&i);
    cout << i << endl;
    increment(i);
    cout << i << endl;

    cout << i << endl;
    cout << j << endl;

    i++;
    cout << i << endl;
    j++;
    cout << j << endl;
}
