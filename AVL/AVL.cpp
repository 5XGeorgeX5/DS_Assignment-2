#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

template <typename T>
class AVLTree
{
private:
    struct Node
    {
        T data;
        Node *parent;
        Node *left;
        Node *right;
        unsigned int height;
        Node(const T &value)
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

    Node *findNode(Node *node, const T &value)
    {
        if (node == nullptr)
            return nullptr;
        if (value < node->data)
        {
            return findNode(node->left, value);
        }
        if (node->data < value)
        {
            return findNode(node->right, value);
        }
        return node;
    }

    Node *findParent(Node *node, const T &value)
    {
        if (value < node->data)
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

    Node *insertNode(const T &value)
    {
        Node *newNode = new Node(value);

        if (root == nullptr)
        {
            root = newNode;
            return root;
        }
        Node *parent = findParent(root, value);
        newNode->parent = parent;
        if (value < parent->data)
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

    int printNode(Node *node, int offset, int depth, std::vector<std::string> &output)
    {
        if (!node)
            return 0;

        bool is_left = (node->parent && node->parent->left == node);
        std::stringstream ss;
        ss << "(" << std::setw(3) << std::setfill('0') << node->data << ")";

        std::string data_str = ss.str();
        int width = data_str.length();

        int left = printNode(node->left, offset, depth + 1, output);
        int right = printNode(node->right, offset + left + width, depth + 1, output);

        for (int i = 0; i < width; i++)
            output[depth][offset + left + i] = data_str[i];

        if (depth && is_left)
        {
            for (int i = 0; i < width + right; i++)
                output[depth - 1][offset + left + width / 2 + i] = '-';
            output[depth - 1][offset + left + width / 2] = '.';
        }
        else if (depth && !is_left)
        {
            for (int i = 0; i < left + width; i++)
                output[depth - 1][offset - width / 2 + i] = '-';
            output[depth - 1][offset + left + width / 2] = '.';
        }
        return left + width + right;
    }

    void printInOrder(Node *node)
    {
        if (node == nullptr)
            return;
        printInOrder(node->left);
        std::cout << node->data << " ";
        printInOrder(node->right);
    }

public:
    AVLTree()
    {
        root = nullptr;
    }

    void insert(const T &value)
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

    void remove(const T &value)
    {
        Node *node = findNode(root, value);
        if (node == nullptr)
            return;
        Node *replacement = deleteNode(node);
        while (replacement)
        {
            setHeight(replacement);
            balanceNode(replacement);
            replacement = replacement->parent;
        }
    }

    void printTree()
    {
        if (!root)
        {
            std::cout << "Empty tree" << std::endl;
            return;
        }

        int height = root->height;
        std::vector<std::string> output(height, std::string(255, ' '));
        printNode(root, 0, 0, output);

        for (const std::string &line : output)
        {
            std::cout << line.substr(0, line.find_last_not_of(' ') + 1) << std::endl;
        }
        cout << endl;
    }

    void print()
    {
        printInOrder(root);
        std::cout << std::endl;
    }
};

int main()
{
    AVLTree<int> tree;
    tree.insert(10);
    tree.printTree();
    tree.insert(20);
    tree.printTree();
    tree.insert(20);
    tree.printTree();
    tree.insert(20);
    tree.printTree();
    tree.insert(20);
    tree.printTree();
    tree.insert(20);
    tree.printTree();
    tree.remove(20);
    tree.printTree();
    tree.insert(30);
    tree.printTree();
    tree.insert(15);
    tree.printTree();
    tree.insert(25);
    tree.printTree();
    tree.insert(5);
    tree.printTree();
    tree.insert(35);
    tree.printTree();
    tree.insert(40);
    tree.printTree();
    tree.insert(45);
    tree.printTree();
    tree.remove(25);
    tree.printTree();
    tree.remove(20);
    tree.printTree();
    tree.remove(30);
    tree.printTree();
    tree.remove(35);
    tree.printTree();
    tree.print();
    return 0;
}