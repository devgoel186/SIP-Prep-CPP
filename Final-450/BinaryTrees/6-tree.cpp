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

void inorderRecursive(Node *root)
{
    if (root == NULL)
        return;
    inorderRecursive(root->left);
    cout << root->data << " ";
    inorderRecursive(root->right);
}

void inorderIterative(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> s;
    Node *temp = root;
    while (temp != NULL || !s.empty())
    {
        if (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
        else
        {
            temp = s.top();
            s.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
    }
}

void postorderRecursive(Node *root)
{
    if (root == NULL)
        return;
    postorderRecursive(root->left);
    postorderRecursive(root->right);
    cout << root->data << " ";
}

void postorderIterative(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> s;
    s.push(root);

    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();

        if (temp->left != NULL)
        {
            s.push(temp->left);
        }
        if (temp->right != NULL)
        {
            s.push(temp->right);
        }
    }
}

void preorderRecursive(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorderRecursive(root->left);
    preorderRecursive(root->right);
}

void preorderIterative(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        cout << temp->data << " ";

        if (temp->right != NULL)
        {
            s.push(temp->right);
        }

        if (temp->left != NULL)
        {
            s.push(temp->left);
        }
    }
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
    Node *root = NULL;
    root = insertNode(root, 12);
    root = insertNode(root, 4);
    root = insertNode(root, 6);
    root = insertNode(root, 1);
    root = insertNode(root, 7);
    root = insertNode(root, 9);
    root = insertNode(root, 19);
    root = insertNode(root, 93);

    inorderRecursive(root);
    cout << endl;
    inorderIterative(root);
}