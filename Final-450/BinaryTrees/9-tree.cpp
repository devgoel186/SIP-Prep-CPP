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

void BFS(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *front = q.front();
        cout << front->data << " ";
        q.pop();
        if (front->left != NULL)
            q.push(front->left);
        if (front->right != NULL)
            q.push(front->right);
    }
}

void leftView(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();

            if (i == 0)
                cout << front->data << " ";

            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
    }
    cout << endl;
}

void rightView(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();

            if (i == size - 1)
                cout << front->data << " ";

            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
    }
    cout << endl;
}

void topView(Node *root, bool left)
{
    if (root == NULL)
        return;
    queue<Node *> q;
}

Node *insertNode(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front->left != NULL)
            q.push(front->left);
        else
        {
            front->left = new Node(data);
            return root;
        }
        if (front->right != NULL)
            q.push(front->right);
        else
        {
            front->right = new Node(data);
            return root;
        }
    }
    return root;
}

int main()
{
    Node *root = new Node(11);
    root->left = new Node(12);
    root->right = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(1);
    root->right->right->right = new Node(7);

    leftView(root);
    rightView(root);
}