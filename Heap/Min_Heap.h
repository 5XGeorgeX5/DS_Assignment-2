#ifndef HEAP_MIN_HEAP_H
#define HEAP_MIN_HEAP_H

#include <vector>
using std::vector;

class Min_Heap {
private:
public:
    template <typename T>
    void heapify(vector<T> &heap, int i);

    template <typename T>
    void insert(vector<T> &heap, T input);

    template <typename T>
    void delete_item(vector<T> &heap, T input);
};


#endif //HEAP_MIN_HEAP_H
