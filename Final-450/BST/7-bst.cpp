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

Node *LCA(Node *root, int a, int b)
{
    if (root == NULL)
        return NULL;

    else if (root->data > a && root->data > b)
        return LCA(root->left, a, b);

    else if (root->data < a && root->data < b)
        return LCA(root->right, a, b);

    return root;
}

Node *LCA2(Node *root, int a, int b)
{
    if (root == NULL)
        return NULL;

    if (root->data == a || root->data == b)
        return root;

    Node *x = LCA(root->left, a, b);
    Node *y = LCA(root->right, a, b);

    if (x && y)
        return root;
    else if (x)
        return x;
    return y;
}

int main()
{
    /*
        6
       4 8
     3 5 7 9
     */

    Node *root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    cout << LCA2(root, 8, 9)->data << endl;
}