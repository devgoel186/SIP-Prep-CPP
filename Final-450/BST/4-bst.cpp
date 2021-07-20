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

void inorder(Node *root, int key, Node *&pre, Node *&suc)
{
    if (root == NULL)
        return;

    else if (root->data == key)
    {
        if (root->left != NULL)
        {
            Node *temp = root->left;
            while (temp->right)
                temp = temp->right;
            pre = temp;
        }
        if (root->right != NULL)
        {
            Node *temp = root->right;
            while (temp->left)
                temp = temp->left;
            suc = temp;
        }
    }

    else if (key > root->data)
    {
        pre = root;
        inorder(root->right, key, pre, suc);
    }

    else
    {
        suc = root;
        inorder(root->left, key, pre, suc);
    }
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

    int key;
    cin >> key;

    Node *pre = NULL, *suc = NULL;
    inorder(root, key, pre, suc);
    cout << pre->data << " " << suc->data << endl;
}