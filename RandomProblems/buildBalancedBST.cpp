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

Node *sortedArrToBST(int *arr, int start, int end)
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);
    root->left = sortedArrToBST(arr, start, mid - 1);
    root->right = sortedArrToBST(arr, mid + 1, end);
    return root;
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    Node *root = sortedArrToBST(arr, 0, n - 1);
    preorder(root);
}