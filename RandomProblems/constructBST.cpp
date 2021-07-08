// #include <bits/stdc++.h>
// using namespace std;
// #define long long ll;

// struct Node
// {
//     int data;
//     Node *left;
//     Node *right;

//     Node(int data)
//     {
//         this->data = data;
//         left = NULL;
//         right = NULL;
//     }
// };

// pair<int, Node *> buildFromPreorder(vector<int> preorder, int key, int min, int max, int n)
// {
//     pair<int, Node *> output;
//     output.second = NULL;
//     if (key > min && key < max)
//     {
//         output.first++;
//         output.second = new Node(key);

//         pair<int, Node *> p1;
//         pair<int, Node *> p2;
//         if (output.first < n)
//         {
//             p1 = buildFromPreorder(preorder, preorder[output.first], min, key, n);
//         }
//         if (p1.first < n)
//         {
//             p2 = buildFromPreorder(preorder, preorder[output.first], min, key, n);
//         }
//     }
//     output.second->left = p1 ;
//     o
//     return output;
// }

// void BFS(Node *root)
// {
//     if (root == NULL)
//         return;

//     queue<Node *> q;
//     q.push(root);
//     while (!q.empty())
//     {
//         Node *front = q.front();
//         cout << front->data << " ";
//         q.pop();
//         if (front->left != NULL)
//             q.push(front->left);
//         if (front->right != NULL)
//             q.push(front->right);
//     }
//     cout << endl;
// }

// void preorder(Node *root)
// {
//     if (root == NULL)
//         return;
//     cout << root->data << " ";
//     preorder(root->left);
//     preorder(root->right);
// }

// void inorder(Node *root)
// {
//     if (root == NULL)
//         return;
//     inorder(root->left);
//     cout << root->data << " ";
//     inorder(root->right);
// }

// int main()
// {
//     vector<int> preorderArr{7, 5, 4, 6, 8, 9};
//     Node *root = buildFromPreorder(preorderArr, 0, 5);
//     preorder(root);
//     cout << endl;
//     inorder(root);
//     cout << endl;
//     BFS(root);
// }