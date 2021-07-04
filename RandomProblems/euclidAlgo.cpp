#include <iostream>
using namespace std;

int euclidAlgo(int a, int b)
{
    if (b == 0)
        return a;
    if (a == 0)
        return b;
    return euclidAlgo(b, a % b);
}

int main()
{
    cout << euclidAlgo(35, 14);
}