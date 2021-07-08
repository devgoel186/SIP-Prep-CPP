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

void printSubtreeK(Node *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
        cout << root->data << " ";
    printSubtreeK(root->left, k - 1);
    printSubtreeK(root->right, k - 1);
}

int nodesAtDistanceK(Node *root, Node *target, int k)
{
    if (root == NULL)
        return -1;
    if (root == target)
    {
        printSubtreeK(root, k);
        return 0;
    }

    int dl = nodesAtDistanceK(root->left, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
            cout << root->data << " ";
        else
            printSubtreeK(root->right, k - dl - 2);
        return 1 + dl;
    }

    int dr = nodesAtDistanceK(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
            cout << root->data << endl;
        else
            printSubtreeK(root->left, k - dr - 2);
        return 1 + dr;
    }
    return -1;
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

    Node *target = root->left->right;

    // 2 3 5 12 11 8 4 - BFS Traversal
    // 2 3 12 11 5 8 4 - Preorder

    /*
        2
        /\
       3  5
      /\  /\
    12 11 8 4
    */

    nodesAtDistanceK(root, target, 2);
}