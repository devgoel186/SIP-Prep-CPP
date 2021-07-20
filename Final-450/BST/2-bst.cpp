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

Node *deleteNode(Node *root, int data)
{
    if (root == NULL)
        return NULL;
    if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
        return root;
    }
    else if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
        return root;
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left != NULL && root->right != NULL)
        {
            Node *temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
            return root;
        }
        else
        {
            if (root->left)
            {
                Node *temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            else
            {
                Node *temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
        }
    }
    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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

    root = deleteNode(root, 4);
    inorder(root);
}