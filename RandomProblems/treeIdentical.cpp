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

bool isIdentical(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    else if (root1 == NULL && root2 != NULL || root2 == NULL && root1 != NULL)
        return false;
    else
        return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right) && (root1->data == root2->data);
}

int main()
{
    Node *root1 = new Node(2);
    root1->left = new Node(3);
    root1->right = new Node(5);
    root1->left->left = new Node(12);
    root1->left->right = new Node(11);
    root1->right->left = new Node(8);
    root1->right->right = new Node(4);

    Node *root2 = new Node(2);
    root2->left = new Node(3);
    root2->right = new Node(5);
    root2->left->left = new Node(12);
    root2->left->right = new Node(11);
    root2->right->left = new Node(8);
    root2->right->right = new Node(4);

    // 2 3 5 12 11 8 4 - BFS Traversal

    /*
        2
        /\
       3  5
      /\  /\
    12 11 8 4
    */

    cout << isIdentical(root1, root2) << endl;
}