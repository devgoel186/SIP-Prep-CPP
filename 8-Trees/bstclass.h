#include <iostream>
#include <queue>
#include "./bstnode.h"
using namespace std;

template <typename T>
class BST
{

private:
    bool hasData(int data, BSTNode<int> *root)
    {
        if (root == NULL)
            return false;
        if (data > root->data)
            return hasData(data, root->right);
        if (data < root->data)
            return hasData(data, root->left);
        return true;
    }

    // EFFICIENCY = O(H)
    BSTNode<int> *insertData(int data, BSTNode<int> *root)
    {
        if (root == NULL)
        {
            BSTNode<int> *temp = new BSTNode<int>(data);
            return temp;
        }
        if (data > root->data)
            root->right = insertData(data, root->right);
        if (data < root->data)
            root->left = insertData(data, root->left);
        return root;
    }

    // EFFICIENCY = O(H)
    BSTNode<int> *deleteData(int data, BSTNode<int> *root)
    {
        if (root == NULL)
            return NULL;
        if (data > root->data)
        {
            root->right = deleteData(data, root->right);
            return root;
        }
        else if (data < root->data)
        {
            root->left = deleteData(data, root->left);
            return root;
        }
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            else if (root->left == NULL)
            {
                BSTNode<int> *temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                BSTNode<int> *temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            else
            {
                BSTNode<int> *temp = root->right;
                while (temp->left != NULL)
                {
                    temp = temp->left;
                }
                root->data = temp->data;
                root->right = deleteData(temp->data, root->right);
                return root;
            }
        }
    }

    void printTree(BSTNode<int> *root)
    {
        queue<BSTNode<int> *> q;
        q.push(root);
        while (!q.empty())
        {
            BSTNode<int> *front = q.front();
            q.pop();
            cout << front->data << " : ";
            if (front->left != NULL)
            {
                q.push(front->left);
                cout << "L" << front->left->data << " ";
            }
            if (front->right != NULL)
            {
                q.push(front->right);
                cout << "R" << front->right->data << " ";
            }
            cout << endl;
        }
    }

public:
    BSTNode<int> *root;

    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

    void printTree()
    {
        printTree(this->root);
    }

    void deleteData(int data)
    {
        this->root = deleteData(data, this->root);
    }

    void insertData(int data)
    {
        this->root = insertData(data, this->root);
    }

    bool hasData(int data)
    {
        return hasData(data, root);
    }
};