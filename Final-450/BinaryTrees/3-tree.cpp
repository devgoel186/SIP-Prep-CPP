#include <iostream>
#include <queue>
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

int height(Node *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
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
        cout << front->data << " ";
        q.pop();
        if (front->left != NULL)
            q.push(front->left);
        if (front->right != NULL)
            q.push(front->right);
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

    // preorder(root);
    cout << height(root) - 1 << endl;
}