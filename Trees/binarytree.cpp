#include <iostream>
#include <queue>
#include <time.h>
#include <algorithm>
#include <iomanip>
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

int countNode(Node<int> *root)
{
    if (root == NULL)
        return 0;
    return countNode(root->left) + countNode(root->right) + 1;
}

void preorder(Node<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node<int> *root)
{
    if (root == NULL)
        return;
    preorder(root->left);
    cout << root->data << " ";
    preorder(root->right);
}

void postorder(Node<int> *root)
{
    if (root == NULL)
        return;
    preorder(root->left);
    preorder(root->right);
    cout << root->data << " ";
}

Node<int> *buildTreeHelper(int *in, int *pre, int inS, int inE, int preS, int preE)
{
    if (inS > inE)
        return NULL;
    int rootData = pre[preS];
    int rootIndexInorder = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == rootData)
        {
            rootIndexInorder = i;
            break;
        }
    }
    int lInS = inS;
    int rPreE = preE;
    int lPreS = preS + 1;
    int lInE = rootIndexInorder - 1;
    int rInS = rootIndexInorder + 1;
    int rInE = inE;
    int lPreE = lInE - lInS + lPreS;
    int rPreS = lPreE + 1;

    Node<int> *root = new Node<int>(rootData);
    root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
    root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
    return root;
}

Node<int> *buildTree(int *in, int *pre, int size)
{
    return buildTreeHelper(in, pre, 0, size - 1, 0, size - 1); // inorder, preorder, inS, inE, preS, preE
}

int height(Node<int> *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

// Diameter of a binary tree is the maximum distance between two nodes
// Efficiency = O(n*h) [this is because we are fetching heights multiple times,
// one time in diameter and one in height]
int diameter(Node<int> *root)
{
    if (root == NULL)
        return 0;
    int diam = height(root->left) + height(root->right);
    return max({diameter(root->left), diameter(root->right), diam});
}

// Efficiency = O(n)
pair<int, int> diameterHeight(Node<int> *root)
{
    if (root == NULL)
    {
        return pair<int, int>(0, 0);
    }
    pair<int, int> leftAns = diameterHeight(root->left);
    pair<int, int> rightAns = diameterHeight(root->right);
    pair<int, int> finalAns;
    finalAns = make_pair(max({leftAns.first, rightAns.first, (leftAns.second + rightAns.second)}), max(leftAns.second, rightAns.second) + 1);
    return finalAns;
}

int main()
{
    // Node<int> *root = takeInput();
    // Node<int> *root = levelWise();
    int in[] = {4, 2, 5, 1, 8, 6, 9, 3, 7};
    int pre[] = {1, 2, 4, 5, 3, 6, 8, 9, 7};
    Node<int> *root = buildTree(in, pre, 9);
    // printTree(root);
    printTreeLevelWise(root);
    cout << "Count = " << countNode(root) << endl;

    // time_t start, end;
    // time(&start);
    // ios_base::sync_with_stdio(false);
    cout << "Diameter = " << diameter(root) << endl;
    // time(&end);

    // time_t start2, end2;
    // time(&start2);
    // ios_base::sync_with_stdio(false);
    cout << "Efficient Diameter = " << diameterHeight(root).first << endl;
    // time(&end2);

    // double time_taken = double(end - start);
    // cout << "Time taken by program 1 is : " << fixed
    //      << time_taken << setprecision(14);
    // cout << " sec " << endl;

    // double time_taken2 = double(end2 - start2);
    // cout << "Time taken by program 2 is : " << fixed
    //      << time_taken2 << setprecision(14);
    // cout << " sec " << endl;

    cout << "### Pre-Order ###" << endl;
    preorder(root);
    cout << endl;
    cout << "### In-Order ###" << endl;
    inorder(root);
    cout << endl;
    cout << "### Post-Order ###" << endl;
    postorder(root);
    cout << endl;
    delete root;
}