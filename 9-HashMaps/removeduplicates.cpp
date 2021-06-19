#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// vector<int> removeDuplicates(int *a, int size)
// {
//     vector<int> output;
//     unordered_map<int, bool> seen;
//     for (int i = 0; i < size; i++)
//         seen.insert(make_pair(a[i], true));
//     for (unordered_map<int, bool>::iterator it = seen.begin(); it != seen.end(); ++it)
//         output.push_back(it->first);
//     return output;
// }

vector<int> removeDuplicates(int *a, int size)
{
    vector<int> output;
    unordered_map<int, bool> seen;
    for (int i = 0; i < size; i++)
    {
        if (seen.count(a[i]))
            continue;
        seen[a[i]] = true;
        output.push_back(a[i]);
    }
    return output;
}

int main()
{
    int a[] = {1, 1, 132, 3, 123, 3, 21, 3, 123, 4};
    vector<int> result = removeDuplicates(a, 10);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
}