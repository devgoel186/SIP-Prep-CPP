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

Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    Node *leftLCA = LCA(root->left, n1, n2);
    Node *rightLCA = LCA(root->right, n1, n2);
    if (leftLCA == NULL && rightLCA == NULL)
        return NULL;
    else if (leftLCA != NULL && rightLCA != NULL)
        return root;
    else if (leftLCA != NULL)
        return LCA(root->left, n1, n2);
    return LCA(root->right, n1, n2);
}

int dist(Node *root, int n1)
{
    if (root == NULL)
        return -1;
    if (root->data == n1)
        return 0;
    int output = max(dist(root->left, n1), dist(root->right, n1));
    if (output != -1)
        return output + 1;
    else
        return -1;
}

int shortestDistance(Node *root, int n1, int n2)
{
    Node *lcaNode = LCA(root, n1, n2);
    return dist(lcaNode, n1) + dist(lcaNode, n2);
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

    /*
        2
        /\
       3  5
      /\  /\
    12 11 8 4
    */
    cout << LCA(root, 8, 3)->data << endl;
    cout << shortestDistance(root, 2, 1) << endl;
}