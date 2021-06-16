#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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

Node<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    Node<int> *root = new Node<int>(rootData);
    queue<Node<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        int num;
        Node<int> *front = q.front();
        q.pop();
        cout << "Enter number of children of  " << front->data << " : ";
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            int childData;
            cin >> childData;
            Node<int> *child = new Node<int>(childData);
            front->children.push_back(child);
            q.push(child);
        }
    }
    return root;
}

Node<int> *takeInput()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    Node<int> *root = new Node<int>(rootData);

    int n;
    cout << "Enter no. of children of " << rootData << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Node<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(Node<int> *root)
{
    cout << root->data << " : ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ", ";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

void printLevelWise(Node<int> *root)
{
    queue<Node<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        cout << q.front()->data << " : ";
        for (int i = 0; i < q.front()->children.size(); i++)
        {
            cout << q.front()->children[i]->data << ", ";
            q.push(q.front()->children[i]);
        }
        cout << endl;
        q.pop();
    }
}

int countNode(Node<int> *root)
{
    if (root == NULL)
        return 0;
    int sum = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += countNode(root->children[i]);
    }
    return sum + 1;
}

int height(Node<int> *root)
{
    if (root->children.size() == 0)
        return 1;
    vector<int> heights;
    for (int i = 0; i < root->children.size(); i++)
    {
        heights.push_back(height(root->children[i]));
    }
    return *max_element(heights.begin(), heights.end()) + 1;
}

void printAtLevelK(Node<int> *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevelK(root->children[i], k - 1);
    }
}

int countLeaves(Node<int> *root)
{
    if (root == NULL)
        return 0;
    if (root->children.size() == 0)
        return 1;
    int sum = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += countLeaves(root->children[i]);
    }
    return sum;
}

int main()
{
    // Node<int> *root = new Node<int>(1);
    // Node<int> *node1 = new Node<int>(2);
    // Node<int> *node2 = new Node<int>(3);
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    // printTree(root);
    // Node<int> *root = takeInput();
    Node<int> *root = takeInputLevelWise();
    printAtLevelK(root, 2);
    cout << endl;
    cout << "Count = " << countNode(root) << endl;
    cout << "Height = " << height(root) << endl;
    cout << "Leaves = " << countLeaves(root) << endl;
    printLevelWise(root);
}