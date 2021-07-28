#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX INT_MAX

struct Node
{
    Node *next[2];
    Node()
    {
        next[0] = NULL;
        next[1] = NULL;
    }
};

int maxXOR(Node *root, vector<int> &a)
{
    int res = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int num = a[i];
        Node *temp = root;
        int currMax = 0;
        for (int j = 31; j >= 0; j--)
        {
            int bit = ((num >> j) & 1) ? 0 : 1;
            if (temp->next[bit] != NULL)
            {
                currMax = currMax << 1;
            }
            temp = temp->next[bit];
        }
    }
}

Node *buildTrie(vector<int> &a)
{
    Node *root = new Node();
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        int num = a[i];
        Node *temp = new Node();
        for (int j = 31; j >= 0; j--)
        {
            int bit = (num >> j) & 1;
            if (temp->next[bit] == NULL)
                temp->next[bit] = new Node();
            temp = temp->next[bit];
        }
    }
    return root;
}

int main()
{
    vector<int> a = {3, 10, 5, 15, 2};
    Node *root = buildTrie(a);
    int ans = maxXOR(root, a);
}