#include <iostream>
#include <vector>
using namespace std;

template <typename T>
struct Node
{
    T data;
    vector<Node<T> *> children;

    Node(T data)
    {
        this->data = data;
    }
};

void printTree(Node<int> *root)
{
    cout << root->data << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

int main()
{
    Node<int> *root = new Node<int>(1);
    Node<int> *node1 = new Node<int>(2);
    Node<int> *node2 = new Node<int>(3);
    root->children.push_back(node1);
    root->children.push_back(node2);
    printTree(root);
}