#include "Min_Heap.h"
#include "Max_Heap.h"

#include <iostream>

using std::cout, std::cin, std::endl, std::swap;


int main() {

    vector<int> vec {4, 1, 3, 9, 2, 10, 8, 7};

    Max_Heap<int> heap {vec};

    heap.printAscending();
    
}
