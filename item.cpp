#ifndef ITEM_CPP
#define ITEM_CPP

#include <bits/stdc++.h>
using namespace std;

class item {
    string itemname;
    string category;
    int price;
    public:
    item(string s, string s2, int p) {
        itemname = s;
        category = s2;
        price = p;
    }
    item() {
        itemname = "";
        category = "";
        price = 0;
    }
    bool operator<(const item& other) {
        return price < other.price;
    }
    void print() const {
        cout << "Item: " << itemname << ", Category: " << category << ", Price: " << price << "\n";
    }
    void setItemname(string s) {
        itemname = s;
    }
    void setCategory(string s) {
        category = s;
    }
    void setPrice(int s) {
        price = s;
    }
    string getItemname() const {
        return itemname;
    }
    string getCategory() const {
        return category;
    }
    int getPrice() const {
        return price;
    }
};

#endif