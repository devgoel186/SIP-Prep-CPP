#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int getBit(int n, int pos)
{
    return (n & (1 << pos)) != 0;
}

int setBit(int n, int pos)
{
    return n | (1 << pos);
}

int clearBit(int n, int pos)
{
    int mask = ~(1 << pos);
    return (n & mask);
}

int updateBit(int n, int pos, int value)
{
    int temp = clearBit(n, pos);
    return temp | (value << pos);
}

bool checkPowerOf2(int n)
{
    if (n == 0)
        return false;
    int temp = 1;
    while (temp <= n)
    {
        if (temp == n)
            return true;
        temp = temp << 1;
    }
    return false;
}

int countNumberOfOnes(int n)
{
    if (n == 0)
        return 0;
    int temp = 1;
    int count = 0;
    while (temp <= n)
    {
        if (temp == (temp & n))
            count++;
        temp = temp << 1;
    }
    return count;
}

void allPossibleSubsets(int *arr, int n)
{
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                cout << arr[j] << " ";
        }
        cout << endl;
    }
}

void allPossibleSubsetsBacktracking(vector<int> *arr, vector<vector<int> *> *res, vector<int> *subset, int index)
{
    res->push_back(subset);
    for (int i = index; i < arr->size(); i++)
    {
        subset->push_back(arr->at(i));
        allPossibleSubsetsBacktracking(arr, res, subset, i + 1);
        subset->pop_back();
    }
    return;
}

vector<vector<int> *> *subsets(vector<int> *arr)
{
    vector<int> *subset;
    vector<vector<int> *> *res;

    // keeps track of current element in vector A;
    int index = 0;
    allPossibleSubsetsBacktracking(arr, res, subset, index);

    return res;
}

int uniqueNumberMap(int *arr, int n)
{
    unordered_map<int, int> h;
    for (int i = 0; i < n; i++)
    {
        if (h.find(arr[i]) != h.end())
            h[arr[i]]++;
        else
            h.insert(make_pair(arr[i], 1));
    }
    for (auto x : h)
    {
        if (x.second == 1)
            return x.first;
    }
    return -1;
}

/* The idea is to XOR all elements, and sunce XOR of two equal 
numbers gives 0, thus in the end we will be left with the unique number */
int uniqueNumber(int *arr, int n)
{
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum ^ arr[i];
    }
    return xorsum;
}

/* The idea is to get the rightmost set bit in the xorsum. This will tell
that either of the two bits in the unique numbers were 1. Now, we see which
numbers in the array have that bit set, and xor them, resulting in the first number with 
set bit at that point, and else we store in other sum, giving t5he second number*/
pair<int, int> twoUniqueNumbers(int *arr, int n)
{
    int xorsum = 0;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum ^ arr[i];
    }
    int setBit = xorsum & ~(xorsum - 1);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & setBit)
            x = x ^ arr[i];
        else
            y = y ^ arr[i];
    }
    return make_pair(x, y);
}

int main()
{
    cout << getBit(7, 1) << endl;
    cout << setBit(7, 3) << endl;
    cout << clearBit(7, 2) << endl;
    cout << updateBit(7, 1, 0) << endl;
    cout << "Power testing" << endl;
    for (int i = 0; i < 17; i++)
    {
        cout << i << " : " << checkPowerOf2(i) << endl;
    }
    cout << countNumberOfOnes(8) << endl;

    // vector<int> *arr = new vector<int>;
    // arr->push_back(3);
    // arr->push_back(4);
    // arr->push_back(132);
    // arr->push_back(312);
    // // allPossibleSubsets(arr, 3);
    // vector<vector<int> *> *res = subsets(arr);
    // // Print result
    // for (int i = 0; i < res->size(); i++)
    // {
    //     for (int j = 0; j < res[i].size(); j++)
    //         cout << res[i][j] << " ";
    //     cout << endl;
    // }

    int arr1[] = {12, 312, 132, 13, 13, 12, 132};
    int arr[] = {12, 312, 132, 13, 13, 1, 12, 1};
    int arrmap[] = {1, 32, 1, 312, 312, 32, 4, 5, 77, 5, 4, 5, 12, 12, 32, 43, 43, 43};
    cout << uniqueNumber(arr1, 7) << endl;
    pair<int, int> res = twoUniqueNumbers(arr, 8);
    cout << res.first << " " << res.second << endl;
    cout << uniqueNumberMap(arrmap, sizeof(arrmap) / sizeof(arr[0])) << endl;
}