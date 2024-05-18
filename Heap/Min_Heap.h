#ifndef HEAP_MIN_HEAP_H
#define HEAP_MIN_HEAP_H

#include <vector>

using std::vector;

template <typename T>
class Min_Heap {
private:
    vector<T> heap_vector;
    int size;
public:
    Min_Heap() : size {0} {}
    Min_Heap(const vector<T> &vec);

    void heapify(int i);
    void insert(T input);
    void delete_item(T input);

    Min_Heap &operator=(const vector<T> &vec);
};


#endif //HEAP_MIN_HEAP_H
