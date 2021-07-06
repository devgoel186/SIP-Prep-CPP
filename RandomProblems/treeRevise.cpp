#include <bits/stdc++.h>
using namespace std;
#define long long ll;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

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
        cout << front->data << " ";
        q.pop();
        if (front->left != NULL)
            q.push(front->left);
        if (front->right != NULL)
            q.push(front->right);
    }
    cout << endl;
}

/* O(n) */
int sumOfNodesAtKRecursive(Node *root, int k)
{
    if (root == NULL)
        return 0;
    if (k == 0)
        return root->data;
    return sumOfNodesAtKRecursive(root->left, k - 1) + sumOfNodesAtKRecursive(root->right, k - 1);
}

/* O(n) */
int sumOfNodesAtK(Node *root, int k)
{
    if (root == NULL)
        return 0;

    queue<Node *> q;
    q.push(root);
    int count = 0, flag = 0, sum = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            Node *front = q.front();
            q.pop();

            if (count == k)
            {
                flag = 1;
                sum += front->data;
            }
            else
            {
                if (front->left != NULL)
                    q.push(front->left);
                if (front->right != NULL)
                    q.push(front->right);
            }
        }
        count++;
        if (flag == 1)
            break;
    }

    return sum;
}

Node *buildTree1Helper(vector<int> preorder, vector<int> inorder, int preS, int preE, int inS, int inE)
{
    if (inS > inE)
        return NULL;

    int rootValue = preorder[preS];
    Node *root = new Node(rootValue);
    int rootIndex;

    for (int i = inS; i <= inE; i++)
    {
        if (inorder[i] == rootValue)
        {
            rootIndex = i;
            break;
        }
    }

    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPreS = preS + 1;
    int lPreE = lInE - lInS + lPreS;
    int rInS = rootIndex + 1;
    int rInE = inE;
    int rPreS = lPreE + 1;
    int rPreE = preE;

    root->left = buildTree1Helper(preorder, inorder, lPreS, lPreE, lInS, lInE);
    root->right = buildTree1Helper(preorder, inorder, rPreS, rPreE, rInS, rInE);

    return root;
}

Node *buildTree2Helper(vector<int> postorder, vector<int> inorder, int postS, int postE, int inS, int inE)
{
    if (inS > inE)
        return NULL;

    int rootValue = postorder[postE];
    Node *root = new Node(rootValue);
    int rootIndex;

    for (int i = inS; i <= inE; i++)
    {
        if (inorder[i] == rootValue)
        {
            rootIndex = i;
            break;
        }
    }

    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPostS = postS;
    int lPostE = lInE - lInS + lPostS;
    int rInS = rootIndex + 1;
    int rInE = inE;
    int rPostS = lPostE + 1;
    int rPostE = postE - 1;

    root->left = buildTree2Helper(postorder, inorder, lPostS, lPostE, lInS, lInE);
    root->right = buildTree2Helper(postorder, inorder, rPostS, rPostE, rInS, rInE);

    return root;
}

Node *buildTree1(vector<int> preorder, vector<int> inorder)
{
    Node *root = buildTree1Helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    return root;
}

Node *buildTree2(vector<int> postorder, vector<int> inorder)
{
    Node *root = buildTree2Helper(postorder, inorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
    return root;
}

int main()
{
    // Node *root = new Node(2);
    // root->left = new Node(3);
    // root->right = new Node(5);
    // root->left->left = new Node(12);
    // root->left->right = new Node(11);
    // root->right->left = new Node(8);
    // root->right->right = new Node(4);

    // 2 3 5 12 11 8 4 - BFS Traversal
    // 2 3 12 11 5 8 4 - Preorder
    // 12 3 11 2 8 5 4 - Inorder
    // 12 11 3 8 4 5 2 - Postorder

    vector<int> preorderArr{2, 3, 12, 11, 5, 8, 4};
    vector<int> inorderArr{12, 3, 11, 2, 8, 5, 4};
    vector<int> postorderArr{12, 11, 3, 8, 4, 5, 2};

    Node *root = NULL;
    // root = buildTree1(preorderArr, inorderArr);
    root = buildTree2(postorderArr, inorderArr);

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    BFS(root);

    cout << sumOfNodesAtK(root, 0) << endl;
    cout << sumOfNodesAtKRecursive(root, 2) << endl;
}
