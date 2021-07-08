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
        this->left = NULL;
        this->right = NULL;
    }
};

bool validBST(Node *root, int min, int max)
{
    if (root == NULL)
        return true;
    if (root->data <= min || root->data >= max)
        return false;
    return validBST(root->left, min, root->data) && validBST(root->right, root->data, max);
}

int main()
{
    Node *root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(5);
    root->right->right = new Node(2);

    // 2 3 5 12 11 8 4 - BFS Traversal
    // 2 3 12 11 5 8 4 - Preorder
    // 12 3 11 2 8 5 4 - Inorder
    // 12 11 3 8 4 5 2 - Postorder
    cout << validBST(root, INT_MIN, INT_MAX) << endl;
}