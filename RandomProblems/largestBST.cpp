// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

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

// int minSubtree(Node *root)
// {
//     if (root->left == NULL && root->right == NULL)
//         return root->data;
//     int minLeft = minSubtree(root->left);
//     int minRight = minSubtree(root->right);
//     return min(minLeft, minRight, root->data);
// }

// int maxSubtree(Node *root)
// {
//     if (root->left == NULL && root->right == NULL)
//         return root->data;
//     int maxLeft = maxSubtree(root->left);
//     int maxRight = maxSubtree(root->right);
//     return max(maxLeft, maxRight, root->data);
// }

// bool validBST(Node *root, int min, int max)
// {
//     if (root == NULL)
//         return true;
//     if (root->data <= min || root->data >= max)
//         return false;
//     return validBST(root->left, min, root->data) && validBST(root->right, root->data, max);
// }

// Node *largestBST(Node *root)
// {
//     int min = minSubtree(root);
//     int max = maxSubtree(root);
//     bool state = validBST()
// }

// int main()
// {
// }