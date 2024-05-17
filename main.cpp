#include <bits/stdc++.h>
using namespace std;
template<typename T> class BST {
    struct Node{
        T data;
        Node* left, *right;
    };
    Node* Root = nullptr;
    Node* newNode(const T& data){
        Node* ret = new Node();
        ret->data = data;
        ret->left = ret->right = nullptr;
        return ret;
    }
public:
    Node* insert(Node* cur, T data){
        if(cur == nullptr){
            cur = newNode(data);
            if(Root == nullptr)
                Root = cur;
            return cur;
        }
        if(cur->data < data)
           cur->right = insert(cur->right, data);
        else
           cur->left = insert(cur->left, data);
        return cur;
    }
    void insert(const T& data){
        insert(Root, data);
    }
    int remove(Node* &cur, const T& data){
        if(cur == nullptr){
            return -1;
        }
        if(data < cur->data)
            return remove(cur->left, data);
        else if(data > cur->data)
            return remove(cur->right, data);
        else{
            if(cur->left == nullptr && cur->right == nullptr){
                delete cur;
                cur = nullptr;
            }
            else if(cur->left == nullptr){
                Node* temp = cur;
                cur = cur->right;
                delete temp;
            }
            else if(cur->right == nullptr){
                Node* temp = cur;
                cur = cur->left;
                delete temp;
            }
            else{
                Node* Descendant = cur->right;
                while(Descendant->left != nullptr)
                    Descendant = Descendant->left;

                cur->data = Descendant->data;

                remove(cur->right, Descendant->data);
            }
            return 1;
        }
    }
    int remove(const T& data){
        return remove(Root, data);
    }
    bool search(Node* cur, const T& data){
        if(cur == nullptr){
            return false;
        }
        if(cur->data == data){
            return true;
        }
        if(cur->data > data)
            return search(cur->left, data);
        else
            return search(cur->right, data);
    }
    bool search(const T& data){
        return search(Root, data);
    }
    // to be done: Displays
};
int main() {
    BST<int>b;
    b.insert(8);
    b.insert(11);
    b.insert(283);
    cout << b.remove(283) << '\n';
    cout << b.remove(2863) << '\n';
    cout << boolalpha << b.search(8) << '\n' << b.search(11) << '\n' << b.search(283) << '\n' << b.search(14);
    BST<array<int, 5>>c;
    c.insert({1, 2, 3, 4, 6});
    cout << c.search({1, 2, 3, 4, 6}) << ' ' << c.search({2, 3}) << '\n';
}
