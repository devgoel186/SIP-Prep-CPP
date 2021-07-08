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

void zigzagTraversal(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> currentLevel;
    stack<Node *> nextLevel;

    bool leftToRight = true;
    currentLevel.push(root);

    while (!currentLevel.empty())
    {
        Node *front = currentLevel.top();
        currentLevel.pop();

        if (front)
        {
            cout << front->data << " ";

            if (leftToRight)
            {
                if (front->left)
                    nextLevel.push(front->left);
                if (front->right)
                    nextLevel.push(front->right);
            }
            else
            {
                if (front->right)
                    nextLevel.push(front->right);
                if (front->left)
                    nextLevel.push(front->left);
            }
        }

        if (currentLevel.empty())
        {
            leftToRight = !leftToRight;
            currentLevel.swap(nextLevel);
        }
    }
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

    zigzagTraversal(root);
}