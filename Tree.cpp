#include <bits/stdc++.h>
#include "item.cpp"

using namespace std;

class Tree {
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
    public:
    Node *insertNode(const item &value);
}