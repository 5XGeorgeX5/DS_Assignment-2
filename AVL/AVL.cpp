#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include "../item.cpp"
using namespace std;

class AVL
{
private:

    bool (*lessCompare)(const item&, const item&);
    struct Node
    {
        item data;
        Node *parent;
        Node *left;
        Node *right;
        unsigned int height;
        Node(const item &value)
        {
            data = value;
            parent = nullptr;
            left = nullptr;
            right = nullptr;
            height = 1;
        }
    };

    Node *root;

    unsigned int getHeight(Node *node)
    {
        return node ? node->height : 0;
    }

    void setHeight(Node *&node)
    {
        node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    }

    int getBalance(Node *node)
    {
        return getHeight(node->left) - getHeight(node->right);
    }

    void leftRotate(Node *node)
    {
        Node *newRoot = node->right;
        Node *newRight = newRoot->left;

        if (node->parent == nullptr)
            root = newRoot;
        else if (node->parent->left == node)
            node->parent->left = newRoot;
        else
            node->parent->right = newRoot;
        newRoot->left = node;
        newRoot->parent = node->parent;
        node->right = newRight;
        if (newRight != nullptr)
            newRight->parent = node;
        node->parent = newRoot;
        setHeight(node);
        setHeight(newRoot);
    }

    void rightRotate(Node *node)
    {
        Node *newRoot = node->left;
        Node *newLeft = newRoot->right;

        if (node->parent == nullptr)
            root = newRoot;
        else if (node->parent->left == node)
            node->parent->left = newRoot;
        else
            node->parent->right = newRoot;
        newRoot->right = node;
        newRoot->parent = node->parent;
        node->left = newLeft;
        if (newLeft != nullptr)
            newLeft->parent = node;
        node->parent = newRoot;
        setHeight(node);
        setHeight(newRoot);
    }

    Node *findNode(Node *node, const item &value)
    {
        if (node == nullptr)
            return nullptr;
        if (lessCompare(value, node->data))
        {
            return findNode(node->left, value);
        }
        if (lessCompare(node->data, value))
        {
            return findNode(node->right, value);
        }
        return node;
    }

    Node *findParent(Node *node, const item &value)
    {
        if (lessCompare(value, node->data))
        {
            if (node->left == nullptr)
                return node;
            return findParent(node->left, value);
        }
        if (node->right != nullptr)
        {
            return findParent(node->right, value);
        }
        return node;
    }

    Node *insertNode(const item &value)
    {
        Node *newNode = new Node(value);

        if (root == nullptr)
        {
            root = newNode;
            return root;
        }
        Node *parent = findParent(root, value);
        newNode->parent = parent;
        if (lessCompare(value, parent->data))
            parent->left = newNode;
        else
            parent->right = newNode;
        return newNode;
    }

    Node *deleteNode(Node *node)
    {
        Node *replacement = node->right, *parent = node->parent;

        if (replacement == nullptr)
        {
            if (parent == nullptr)
                root = node->left;
            else if (parent->left == node)
                parent->left = node->left;
            else
                parent->right = node->left;
            if (node->left)
                node->left->parent = parent;
            delete node;
            return parent;
        }
        while (replacement->left)
        {
            replacement = replacement->left;
        }
        node->data = replacement->data;
        parent = replacement->parent;
        if (parent == node)
            parent->right = replacement->right;
        else
            parent->left = replacement->right;
        if (replacement->right)
            replacement->right->parent = parent;
        delete replacement;
        return parent;
    }

    bool balanceNode(Node *&node)
    {
        int balance = getBalance(node);
        if (balance > 1)
        {
            if (getBalance(node->left) < 0)
                leftRotate(node->left);
            rightRotate(node);
            return true;
        }
        else if (balance < -1)
        {
            if (getBalance(node->right) > 0)
                rightRotate(node->right);
            leftRotate(node);
            return true;
        }
        return false;
    }

    void printInOrder(Node *node)
    {
        if (node == nullptr)
            return;
        printInOrder(node->left);
        node->data.print();
        printInOrder(node->right);
    }

    void printInOrderRight(Node *node)
    {
        if (node == nullptr)
            return;
        printInOrderRight(node->right);
        node->data.print();
        printInOrderRight(node->left);
    }

public:
    AVL(bool (*lessCompare)(const item&, const item&))
    {
        this->lessCompare = lessCompare;
        root = nullptr;
    }

    void insert(const item &value)
    {
        Node *newNode = insertNode(value);
        int balance;
        while (newNode)
        {
            setHeight(newNode);
            if (balanceNode(newNode))
            {
                return;
            }
            newNode = newNode->parent;
        }
    }

    void remove(const item &value)
    {
        Node *node = findNode(root, value);
        if (node == nullptr)
            return;
        if(node->data.getPrice() != value.getPrice() || node->data.getItemname() != value.getItemname() || node->data.getCategory() != value.getCategory()) return;
        Node *replacement = deleteNode(node);
        while (replacement)
        {
            setHeight(replacement);
            balanceNode(replacement);
            replacement = replacement->parent;
        }
    }

    void printAscending()
    {
        printInOrder(root);
        std::cout << std::endl;
    }

    void printDescending()
    {
        printInOrderRight(root);
        std::cout << std::endl;
    }
};