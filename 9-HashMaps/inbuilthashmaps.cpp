#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    // Insertion
    unordered_map<string, int> m;
    pair<string, int> p("abc", 1);
    m.insert(p);
    m["def"] = 2;

    // Find or Access
    cout << m.at("abc") << endl;
    cout << m["abc"] << endl;
    cout << m.size() << endl;
    cout << m["ghi"] << endl; // This statement will actually create a key named 'ghi', and initialize with 0
    cout << m.size() << endl;

    if (m.count("ghi"))
        cout << "ghi is present" << endl;

    m.erase("ghi");
    if (m.count("ghi"))
        cout << "ghi is present" << endl;
}