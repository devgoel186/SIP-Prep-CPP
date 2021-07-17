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

Node *mirror(Node *root)
{
    if (root == NULL)
        return root;

    root->left = mirror(root->left);
    root->right = mirror(root->right);

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    return root;
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void BFS(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *front = q.front();
        cout << front->data << " : ";
        q.pop();
        if (front->left != NULL)
        {
            cout << "L" << front->left->data << " ";
            q.push(front->left);
        }
        if (front->right != NULL)
        {
            cout << "R" << front->right->data << " ";
            q.push(front->right);
        }
        cout << endl;
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

    BFS(root);
    mirror(root);
    cout << endl;
    BFS(root);
}