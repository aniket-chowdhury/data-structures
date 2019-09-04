#include <iostream>

namespace lib
{
template <typename T>
class lrNode
{
public:
    T key;
    lrNode *left;
    lrNode *right;
    lrNode(T elemval, lrNode *leftval = nullptr, lrNode *rightval = nullptr) : key(elemval), left(leftval), right(rightval) {}
    lrNode(lrNode *leftval = nullptr, lrNode *rightval = nullptr) : left(leftval), right(rightval) {}
};

template <typename T>
class BST
{
private:
    lrNode<T> *root;

    void init()
    {
        root = fence = new lrNode<T>(nullptr);
    }

public:
    lrNode<T> *fence;
    lrNode<T> *getRoot() { return root; }
    BST() { init(); }
    bool insert(T it, lrNode<T>* node)
    {
        if (node == nullptr)
        {
            root = new lrNode<T>(it, nullptr, nullptr);
            return true;
        }
        if (it < node->key)
        {
            node->left = insert(it, node->left);
        }
        else if (it > node->key)
        {
            node->right = insert(it, node->right);
        }
    }
};
} // namespace std