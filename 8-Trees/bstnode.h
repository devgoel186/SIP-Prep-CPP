#include <iostream>
using namespace std;

template <typename T>
class BSTNode
{
public:
    T data;
    BSTNode *left;
    BSTNode *right;

    BSTNode(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    ~BSTNode()
    {
        delete left;
        delete right;
    }
};