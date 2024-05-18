#include "Min_Heap.h"

template<typename T>
Min_Heap<T>::Min_Heap(const vector<T> &vec) {
    heap_vector = vec;
    size = vec.size();
    for (int i {size / 2 - 1}; i >= 0; --i) {
        heapify(i);
    }
}

template<typename T>
void Min_Heap<T>::heapify(int i) {
    int largest {i};
    int left_child {i * 2 + 1};
    int right_child {i * 2 + 2};

    if (left_child < size && heap_vector[left_child] < heap_vector[largest]) {
        largest = left_child;
    }
    if (right_child < size && heap_vector[right_child] < heap_vector[largest]) {
        largest = right_child;
    }

    if (largest != i) {
        swap(heap_vector[i], heap_vector[largest]);
        heapify(largest);
    }
}

template<typename T>
void Min_Heap<T>::insert(T input) {
    input.emplace_back(heap_vector);
    for (int i {size / 2 - 1}; i >= 0; --i) {
        heapify(i);
    }
}

template<typename T>
void Min_Heap<T>::delete_item(T input) {
    int i {0};

    for (; i < size; ++i) {
        if (heap_vector[i] == input) {
            break;
        }
    }

    swap(heap_vector[i], heap_vector[size - 1]);
    heap_vector.pop_back();

    for (i = size / 2 - 1; i >= 0; --i) {
        heapify(i);
    }
}

template <typename T>
Min_Heap<T> &Min_Heap<T>::operator=(const vector<T> &vec) {
    heap_vector = vec;
    size = vec.size();
    for (int i {size / 2 - 1}; i >= 0; --i) {
        heapify(i);
    }
}


