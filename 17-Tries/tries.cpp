#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX INT_MAX

struct Node
{
    bool end;
    Node *next[26];

    Node()
    {
        end = false;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
};

void insert(string word, Node *trie)
{
    int i = 0;
    Node *newNode = trie;

    while (i < word.size())
    {
        if (newNode->next[word[i] - 'a'] == NULL)
            newNode->next[word[i] - 'a'] = new Node();
        newNode = newNode->next[word[i] - 'a'];
        i++;
    }
    newNode->end = true;
}

bool search(string word, Node *trie)
{
    int i = 0;
    Node *newNode = trie;

    while (i < word.size())
    {
        if (newNode->next[word[i] - 'a'] == NULL)
            return false;
        newNode = newNode->next[word[i] - 'a'];
        i++;
    }

    return newNode->end;
}

int main()
{
    Node *trie = new Node();
    vector<string> words = {"abc", "dabbc", "dabc", "lasw"};

    for (auto i : words)
        insert(i, trie);

    if (search("lasw", trie))
        cout << "Found" << endl;
}