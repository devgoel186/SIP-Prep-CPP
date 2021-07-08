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

void leftView(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            if (i == 0)
            {
                cout << front->data << " ";
            }
            if (front->left != NULL)
                q.push(front->left);
            if (front->right != NULL)
                q.push(front->right);
            q.pop();
        }
    }
    cout << endl;
}

void rightView(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            if (i == size - 1)
            {
                cout << front->data << " ";
            }
            if (front->left != NULL)
                q.push(front->left);
            if (front->right != NULL)
                q.push(front->right);
            q.pop();
        }
    }
    cout << endl;
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
    leftView(root);
    rightView(root);
}