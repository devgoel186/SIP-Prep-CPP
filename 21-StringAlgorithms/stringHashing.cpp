#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX INT_MAX

ll calculate_hash(string s, vector<int> &powers)
{
    ll hash = 0;
    for (int i = 0; i < s.size(); i++)
    {
        hash = (hash % MOD + ((s[i] - 'a' + 1) * powers[i]) % MOD) % MOD;
    }
    return hash;
}

int main()
{
    int n;
    int p = 31;
    cin >> n;
    vector<int> powers(n);
    powers[0] = 1;
    for (int i = 1; i < n; i++)
    {
        powers[i] = (powers[i - 1] * p) % MOD;
    }

    vector<string> strings = {"aa",
                              "ab",
                              "aa",
                              "b",
                              "cc",
                              "aa"};
    vector<ll> hashes;
    for (auto w : strings)
    {
        hashes.push_back(calculate_hash(w, powers));
    }
    sort(hashes.begin(), hashes.end());
    int distinct = 0;
    for (int i = 0; i < hashes.size(); i++)
    {
        if (i == 0 || hashes[i] != hashes[i - 1])
            distinct++;
    }

    cout << "Distinct substrings = " <<  distinct << endl;
}