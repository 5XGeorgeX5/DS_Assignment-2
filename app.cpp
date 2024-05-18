#include <bits/stdc++.h>
#include <cmath>
#include "BST/BST.cpp"
#include "AVL/AVL.cpp"
#include "Heap/MaxHeap.cpp"
#include "Heap/MinHeap.cpp"

using namespace std;

bool lessPrice(const item& data, const item& node) {
    if(data.getPrice() < node.getPrice()) return true;
    else return false;
}

bool lessName(const item& data, const item& node) {
    if(data.getItemname() < node.getItemname()) return true;
    else return false;
}

vector<item> items;

template<typename T>
void getData(T& priceTree, T& nameTree) {
    string fileName = "items.txt";
    FILE *file = freopen(fileName.c_str(), "r", stdin);

    if (!file) {
        cerr << "Error: Unable to open file " << fileName << endl;
        return;
    }
    string itemname, category;
    int price;
    int t;
    cin >> t;
    getline(cin, itemname);
    while(t--) {
        getline(cin, itemname);
        getline(cin, category);
        cin >> price;
        items.push_back(item(itemname, category, price));
        priceTree.insert(item(itemname, category, price));
        nameTree.insert(item(itemname, category, price));
        getline(cin, itemname);
    }
    fclose(file);
}
int main() {
    int x = -1;
    while(x > 4 || x < 1) {
        cout << "\n";
        cout << "Choose which data structure to deal with:\n";
        cout << "1 - Binary Search Tree.\n";
        cout << "2 - AVL Tree.\n";
        cout << "3 - Max Heap.\n";
        cout << "4 - Min Heap.\n";
        cin >> x;
        if(x > 4 || x < 1) cout << "Choose a number between 1 and 4.\n";
    }
    BST bstPriceTree(lessPrice);
    BST bstNameTree(lessName);
    AVL avlPriceTree(lessPrice);
    AVL avlNameTree(lessName);
    MaxHeap maxHeapPrice(lessPrice);
    MaxHeap maxHeapName(lessName);
    MinHeap minHeapPrice(lessPrice);
    MinHeap minHeapName(lessName);

    if(x == 1) {
        getData(bstPriceTree, bstNameTree);
    } else if(x == 2) {
        getData(avlPriceTree, avlNameTree);
    } else if(x == 3) {
        getData(maxHeapPrice, maxHeapName);
    } else if(x == 4) {
        getData(minHeapPrice, minHeapName);
    }

    freopen("CON", "r", stdin);
    // for(item x: items) {
    //     x.print();
    // }


    int inp = -1;
    while(inp < 1 || inp > 8) {
        cout << "\n";
        cout << "1 - Add item data.\n";
        cout << "2 - Remove item data.\n";
        cout << "3 - Display data normally.\n";
        cout << "4 - Display items sorted by name ascending.\n";
        cout << "5 - Display items sorted by name descending.\n";
        cout << "6 - Display items sorted by price ascending.\n";
        cout << "7 - Display items sorted by price descending.\n";
        cout << "8 - Close program\n";
        cin >> inp;

        if(inp < 1 || inp > 8) {
            cout << "Enter a number between 1 and 8.\n";
        }
        if(inp == 1) {
            string s, c;
            int p;
            cin.ignore();
            cout << "Enter the name of the item: \n";
            getline(cin, s);
            cout << "Enter the category of the item: \n";
            getline(cin, c);
            cout << "Enter the price of the item: \n";
            cin >> p;
            items.push_back(item(s, c, p));
            if(x == 1) {
                bstNameTree.insert(item(s, c, p));
                bstPriceTree.insert(item(s, c, p));
            } else if(x == 2) {
                avlNameTree.insert(item(s, c, p));
                avlPriceTree.insert(item(s, c, p));
            } else if(x == 3) {
                maxHeapName.insert(item(s, c, p));
                maxHeapPrice.insert(item(s, c, p));
            } else if(x == 4) {
                minHeapName.insert(item(s, c, p));
                minHeapPrice.insert(item(s, c, p));
            }
            cout << "Item was added successfully.\n";
            inp = -1;
            continue;
        } else if(inp == 2) {
            string s, c;
            int p;
            cin.ignore();
            cout << "Enter the name of the item: \n";
            getline(cin, s);
            cout << "Enter the category of the item: \n";
            getline(cin, c);
            cout << "Enter the price of the item: \n";
            cin >> p;
            bool done = false;
            item temp(s, c, p);
            for(int i=0; i<items.size(); ++i) {
                item x = items[i];
                if(!(temp != x)) {
                    items.erase(items.begin() + i);
                    done = true;
                    cout << "Item was removed successfully.\n";
                    break;
                }
            }
            if(!done) cout << "Item could not be found.\n";
            else {
                if(x == 1) {
                    bstNameTree.remove(temp);
                    bstPriceTree.remove(temp);
                } else if(x == 2) {
                    avlNameTree.remove(temp);
                    avlPriceTree.remove(temp);
                } else if(x == 3) {
                    maxHeapName.remove(temp);
                    maxHeapPrice.remove(temp);
                } else if(x == 4) {
                    minHeapName.remove(temp);
                    minHeapPrice.remove(temp);
                }
            }
            
            inp = -1;
            continue;
        } else if(inp == 3) {
            for(int i=0; i<items.size(); ++i) {
                items[i].print();
            }
            cout << "\n";
            inp = -1;
            continue;
        } else if(inp == 4) {
            if(x == 1) {
                bstNameTree.printAscending();
            } else if(x == 2) {
                avlNameTree.printAscending();
            } else if(x == 3) {
                maxHeapName.printAscending();
            } else if(x == 4) {
                minHeapName.printAscending();
            }

            inp = -1;
            continue;
        } else if(inp == 5) {
            if(x == 1) {
                bstNameTree.printDescending();
            } else if(x == 2) {
                avlNameTree.printDescending();
            } else if(x == 3) {
                maxHeapName.printDescending();
            } else if(x == 4) {
                minHeapName.printDescending();
            }
            inp = -1;
            continue;
        } else if(inp == 6) {
            if(x == 1) {
                bstPriceTree.printAscending();
            } else if(x == 2) {
                avlPriceTree.printAscending();
            } else if(x == 3) {
                maxHeapPrice.printAscending();
            } else if(x == 4) {
                minHeapPrice.printAscending();
            }
            inp = -1;
            continue;
        } else if(inp == 7) {
            if(x == 1) {
                bstPriceTree.printDescending();
            } else if(x == 2) {
                avlPriceTree.printDescending();
            } else if(x == 3) {
                maxHeapPrice.printDescending();
            } else if(x == 4) {
                minHeapPrice.printDescending();
            }
            inp = -1;
            continue;
        } else if(inp == 8) {
            break;
        }
    }
    return 0;
}