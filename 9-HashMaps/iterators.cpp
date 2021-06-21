#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    unordered_map<string, int> m;
    m["abc1"] = 1;
    m["abc2"] = 2;
    m["abc3"] = 3;
    m["abc4"] = 4;
    m["abc5"] = 5;
    m["abc6"] = 6;

    m.find("abc3");

    for (unordered_map<string, int>::iterator it = m.begin(); it != m.end(); it++)
        cout << "Key : " << it->first << ", Value : " << it->second << endl;
}