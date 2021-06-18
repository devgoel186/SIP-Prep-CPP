#include <iostream>
#include <queue>
#include <time.h>
#include <algorithm>
#include <iomanip>
#include <climits>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node *left;
    Node *right;

    Node(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~Node()
    {
        delete left;
        delete right;
    }
};

Node<int> *levelWise()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    Node<int> *root = new Node<int>(rootData);
    queue<Node<int> *> q;
    q.push(root);
    while (q.size() != 0)
    {
        Node<int> *front = q.front();
        q.pop();
        cout << "Enter left child of " << front->data << endl;
        int dataChild, dataChild2;
        cin >> dataChild;
        cout << "Enter right child of " << front->data << endl;
        cin >> dataChild2;
        if (dataChild != -1)
        {
            Node<int> *childLeft = new Node<int>(dataChild);
            front->left = childLeft;
            q.push(childLeft);
        }
        if (dataChild2 != -1)
        {
            Node<int> *childRight = new Node<int>(dataChild2);
            front->right = childRight;
            q.push(childRight);
        }
    }
    return root;
}

Node<int> *takeInput()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }

    Node<int> *root = new Node<int>(rootData);
    Node<int> *left = takeInput();
    Node<int> *right = takeInput();
    root->left = left;
    root->right = right;
    return root;
}

void printTree(Node<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " : ";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data << " ";
    }
    if (root->right != NULL)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

void printTreeLevelWise(Node<int> *root)
{
    queue<Node<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        Node<int> *front = q.front();
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

Node<int> *searchNode(Node<int> *root, int data)
{
    if (root == NULL)
    {
        cout << "No such node found!" << endl;
        return NULL;
    }
    if (data == root->data)
        return root;
    else if (data > root->data)
        return searchNode(root->right, data);
    return searchNode(root->left, data);
}

void printInRange(Node<int> *root, int low, int high)
{
    if (root == NULL)
        return;
    if (low < root->data)
        printInRange(root->left, low, high);
    if (low <= root->data && high >= root->data)
        cout << root->data << " ";
    if (high > root->data)
        printInRange(root->right, low, high);
}

int maximumElement(Node<int> *root)
{
    if (root == NULL)
        return INT_MIN;
    return max({root->data, maximumElement(root->left), maximumElement(root->right)});
}

int minimumElement(Node<int> *root)
{
    if (root == NULL)
        return INT_MAX;
    return min({root->data, minimumElement(root->left), minimumElement(root->right)});
}

bool checkBST(Node<int> *root)
{
    if (root == NULL)
        return true;
    int leftMax = maximumElement(root->left);
    int rightMin = minimumElement(root->right);
    bool output = (root->data > leftMax) && (root->data <= rightMin) && checkBST(root->left) && checkBST(root->right);
    return output;
}

int main()
{
    Node<int> *root = levelWise();
    cout << "Is BST? : ";
    if (checkBST(root))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    printTreeLevelWise(root);
    cout << "Enter element to search : " << endl;
    int search;
    cin >> search;
    Node<int> *found = searchNode(root, search);
    if (found != NULL)
        cout << "Found = " << found->data << endl;
    printInRange(root, 1, 9);
    // 5 3 7 1 4 6 9 -1 -1 -1 -1 -1 -1 8 10 -1 -1 -1 -1
}
