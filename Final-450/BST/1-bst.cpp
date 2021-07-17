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

bool findNode(Node *root, int data)
{
    if (root == NULL)
        return false;

    Node *temp = new Node(data);
    if (temp->data > root->data)
        return findNode(root->right, data);
    else if (temp->data < root->data)
        return findNode(root->left, data);
    return true;
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    cout << findNode(root, 8) << endl;
    cout << findNode(root, 5) << endl;
    cout << findNode(root, 2) << endl;
    cout << findNode(root, 1) << endl;
    cout << findNode(root, 90) << endl;
}