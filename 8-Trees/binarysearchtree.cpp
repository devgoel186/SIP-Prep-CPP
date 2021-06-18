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
        this->left = NULL;
        this->right = NULL;
    }

    ~Node()
    {
        delete left;
        delete right;
    }
};

template <typename T>
struct LLNode
{
    T data;
    LLNode *next;

    LLNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
struct LL
{
    LLNode<T> *head;
    LLNode<T> *tail;

    LL()
    {
        this->head = NULL;
        this->tail = NULL;
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

// EFFICIENCY = O(N*H)
bool checkBST(Node<int> *root)
{
    if (root == NULL)
        return true;
    int leftMax = maximumElement(root->left);
    int rightMin = minimumElement(root->right);
    bool output = (root->data > leftMax) && (root->data <= rightMin) && checkBST(root->left) && checkBST(root->right);
    return output;
}

// EFFICIENCY = O(N)
pair<bool, pair<int, int>> checkBSTOptimised(Node<int> *root)
{
    if (root == NULL)
    {
        return pair<bool, pair<int, int>>(true, make_pair(INT_MAX, INT_MIN));
    }
    pair<bool, pair<int, int>> leftState = checkBSTOptimised(root->left);
    pair<bool, pair<int, int>> rightState = checkBSTOptimised(root->right);
    pair<bool, pair<int, int>> output;

    bool con1 = (root->data > leftState.second.second);
    bool con2 = (root->data < rightState.second.first);
    bool result = leftState.first && rightState.first && con1 && con2;

    int maxEle = max({root->data, leftState.second.second, rightState.second.second});
    int minEle = min({root->data, leftState.second.first, rightState.second.first});

    output = make_pair(result, make_pair(minEle, maxEle));
    return output;
}

bool isBST3(Node<int> *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == NULL)
        return true;
    if (root->data < min || root->data > max)
        return false;
    bool leftState = isBST3(root->left, min, root->data);
    bool rightState = isBST3(root->right, root->data, max);
    return leftState && rightState;
}

Node<int> *constructBST(int *arr, int si, int ei)
{
    if (si > ei)
        return NULL;
    int mid = (si + ei) / 2;
    Node<int> *root = new Node<int>(arr[mid]);
    root->left = constructBST(arr, si, mid - 1);
    root->right = constructBST(arr, mid + 1, ei);
    return root;
}

LL<int> *BSTToSortedLL(Node<int> *root)
{
    if (root == NULL)
    {
        LL<int> *temp = new LL<int>();
        return temp;
    }
    LL<int> *lh = BSTToSortedLL(root->left);
    LL<int> *rh = BSTToSortedLL(root->right);

    LLNode<int> *rootNode = new LLNode<int>(root->data);

    if (lh->tail != NULL)
        lh->tail->next = rootNode;
    rootNode->next = rh->head;

    LL<int> *output = new LL<int>();
    if (lh->head == NULL)
        output->head = rootNode;
    else
        output->head = lh->head;

    if (rh->tail == NULL)
        output->tail = rootNode;
    else
        output->tail = rh->tail;

    return output;
}

int main()
{
    // Node<int> *root = levelWise();
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    Node<int> *root = constructBST(arr, 0, 6);
    cout << "Is BST? : ";
    if (checkBSTOptimised(root).first)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    cout << "Is BST3? : ";
    if (isBST3(root))
        cout
            << "Yes" << endl;
    else
        cout << "No" << endl;
    LL<int> *llPointer = BSTToSortedLL(root);
    cout << "## BST To Linked List : ";
    while (llPointer->head != NULL)
    {
        cout << llPointer->head->data << " ";
        llPointer->head = llPointer->head->next;
    }
    cout << "##" << endl;
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
