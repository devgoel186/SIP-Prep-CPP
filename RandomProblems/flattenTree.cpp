#include <bits/stdc++.h>
using namespace std;
#define long long ll;

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

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void flattenTree(Node *root)
{
    if (root == NULL)
        return;

    if (root->left != NULL)
    {
        flattenTree(root->left);
        Node *temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node *t = root->right;
        while (t->right != NULL)
            t = t->right;
        t->right = temp;
    }

    flattenTree(root->right);
}

int main()
{
    Node *root = new Node(2);
    root->left = new Node(3);
    root->right = new Node(5);
    root->left->left = new Node(12);
    root->left->right = new Node(11);
    root->right->left = new Node(8);
    root->right->right = new Node(4);

    // 2 3 5 12 11 8 4 - BFS Traversal
    // 2 3 12 11 5 8 4 - Preorder

    /*
        2
        /\
       3  5
      /\  /\
    12 11 8 4
    */

    flattenTree(root);
    inorder(root);
}