#include <iostream>
#include <queue>
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

int main()
{
    // Node<int> *root = takeInput();
    Node<int> *root = levelWise();
    printTree(root);
    cout << "Count = " << countNode(root) << endl;
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