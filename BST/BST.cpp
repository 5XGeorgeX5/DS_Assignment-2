#include <bits/stdc++.h>
#include "../item.cpp"
using namespace std;

class BST
{
    bool (*lessCompare)(const item&, const item&);
    struct Node
    {
        item data;
        Node *left, *right;
        Node(const item &value)
        {
            data = value;
            left = nullptr;
            right = nullptr;
        }
    };

    Node *Root = nullptr;

    Node *insert(Node *cur, const item &data)
    {
        if (cur == nullptr)
        {
            cur = new Node(data);
            if (Root == nullptr)
                Root = cur;
            return cur;
        }
        if (lessCompare(cur->data , data))
            cur->right = insert(cur->right, data);
        else
            cur->left = insert(cur->left, data);
        return cur;
    }

    int remove(Node *&cur, const item &data)
    {
        if (cur == nullptr)
        {
            return -1;
        }
        if (lessCompare(data, cur->data))
            return remove(cur->left, data);
        if (lessCompare(cur->data, data))
            return remove(cur->right, data);
        else
        {
            if (cur->left == nullptr && cur->right == nullptr)
            {
                delete cur;
                cur = nullptr;
            }
            else if (cur->left == nullptr)
            {
                Node *temp = cur;
                cur = cur->right;
                delete temp;
            }
            else if (cur->right == nullptr)
            {
                Node *temp = cur;
                cur = cur->left;
                delete temp;
            }
            else
            {
                Node *Descendant = cur->right;
                while (Descendant->left != nullptr)
                    Descendant = Descendant->left;

                cur->data = Descendant->data;

                remove(cur->right, Descendant->data);
            }
            return 1;
        }
    }

    bool search(Node *cur, const item &data)
    {
        if (cur == nullptr)
        {
            return false;
        }
        if (lessCompare(data, cur->data))
            return search(cur->left, data);
        if (lessCompare(cur->data, data))
            return search(cur->right, data);
        return true;
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
    BST(bool (*lessCompare)(const item&, const item&))
    {
        this->lessCompare = lessCompare;
    }
    void insert(const item &data)
    {
        insert(Root, data);
    }
    
    int remove(const item &data)
    {
        return remove(Root, data);
    }

    bool search(const item &data)
    {
        return search(Root, data);
    }

    void printAscending()
    {
        printInOrder(Root);
        std::cout << std::endl;
    }

    void printDescending()
    {
        printInOrderRight(Root);
        std::cout << std::endl;
    }
};
