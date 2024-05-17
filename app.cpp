#include <bits/stdc++.h>
#include <cmath>
#include "BST/BST.cpp"
#include "AVL/AVL.cpp"

using namespace std;

bool lessPrice(const item& data, const item& node) {
    if(data.getPrice() < node.getPrice()) return true;
    else return false;
}

bool lessName(const item& data, const item& node) {
    if(data.getItemname() < node.getItemname()) return true;
    else return false;
}

int main() {
    AVLTree bst1(lessPrice);
    AVLTree bst2(lessName);
    bst1.insert(item("Apple", "Fruit", 10));
    bst1.insert(item("Banana", "Fruit", 5));
    bst1.insert(item("Orange", "Fruit", 7));
    bst1.insert(item("Mango", "Fruit", 15));
    bst1.insert(item("Pineapple", "Fruit", 20));
    bst1.print();
    cout << "--------------------------------\n";
    bst2.insert(item("Apple", "Fruit", 10));
    bst2.insert(item("Banana", "Fruit", 5));
    bst2.insert(item("Orange", "Fruit", 7));
    bst2.insert(item("Pineapple", "Fruit", 20));
    bst2.print();
    cout << "Hello world";
    return 0;
}