#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int maxBST(Node *root)
{
    if (root == NULL)
        return -1;
    if (root->right == NULL)
        return root->data;
    return maxBST(root->right);
}

int minBST(Node *root)
{
    if (root == NULL)
        return -1;
    if (root->left == NULL)
        return root->data;
    return minBST(root->left);
}

int main()
{
    Node *root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    cout << minBST(root) << " " << maxBST(root) << endl;
}