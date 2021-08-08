#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX INT_MAX

ll calculate_hash(string s, const vector<ll> &powers)
{
    ll hash = 0;
    for (ll i = 0; i < s.size(); i++)
        hash = (hash % MOD + ((s[i] - 'a' + 1) * powers[i]) % MOD) % MOD;
    return hash % MOD;
}

int main()
{
    string t, s;
    cin >> t >> s;
    ll tl = t.length(), sl = s.length();

    vector<ll> powers(max(tl, sl), 1);
    for (int i = 1; i < max(tl, sl); i++)
        powers[i] = (powers[i - 1] * 31) % MOD;

    for (auto i : powers)
        cout << i << " ";
    cout << endl;

    vector<ll> hashT(tl + 1, 0);
    for (ll i = 0; i < tl; i++)
        hashT[i + 1] = (hashT[i] % MOD + ((t[i] - 'a' + 1) * powers[i]) % MOD) % MOD;

    ll hashS = calculate_hash(s, powers);

    for (ll i = 0; i < tl - sl + 1; i++)
    {
        ll hashCurr = (hashT[i + sl] - hashT[i] + MOD) % MOD;
        if (hashCurr == (hashS * powers[i]) % MOD)
            cout << "Found at index " << i << endl;
    }
}