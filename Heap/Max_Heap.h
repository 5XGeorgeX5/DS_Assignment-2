#ifndef HEAP_MAX_HEAP_H
#define HEAP_MAX_HEAP_H

#include <vector>
#include <iostream>

using std::cout, std::endl, std::vector;

template <typename T>
class Max_Heap {
private:
    vector<T> heap_vector;
    int size;
    void heapify(int i);
    void heapSort();
public:

    Max_Heap() : size {0} {}
    Max_Heap(const vector<T> &vec);

    void insert(T input);
    void remove(T input);
    void printAscending();
    void printDescending();

    Max_Heap &operator=(const vector<T> &vec);
};


#endif //HEAP_MAX_HEAP_H
