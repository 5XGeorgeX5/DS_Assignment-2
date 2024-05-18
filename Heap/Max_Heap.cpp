#include "Max_Heap.h"

template <typename T>
Max_Heap<T>::Max_Heap(const vector<T> &vec) {
    heap_vector = vec;
    size = vec.size();
    for (int i {size / 2 - 1}; i >= 0; --i) {
        heapify(i);
    }
}

template <typename T>
void Max_Heap<T>::heapify(int i) {
    int largest {i};
    int left_child {i * 2 + 1};
    int right_child {i * 2 + 2};

    if (left_child < heap_vector.size() && heap_vector[left_child] > heap_vector[largest]) {
        largest = left_child;
    }
    if (right_child < heap_vector.size() && heap_vector[right_child] > heap_vector[largest]) {
        largest = right_child;
    }

    if (largest != i) {
        swap(heap_vector[i], heap_vector[largest]);
        heapify(largest);
    }
}

template<typename T>
void Max_Heap<T>::insert(T input) {
    input.emplace_back(heap_vector);
    for (int i {heap_vector.size() / 2 - 1}; i >= 0; --i) {
        heapify(i);
    }
}

template<typename T>
void Max_Heap<T>::remove(T input) {
    int i {0};

    for (; i < heap_vector.size(); ++i) {
        if (heap_vector[i] == input) {
            break;
        }
    }

    swap(heap_vector[i], heap_vector[heap_vector.size() - 1]);
    heap_vector.pop_back();

    for (i = heap_vector.size() / 2 - 1; i >= 0; --i) {
        heapify(i);
    }
}

template <typename T>
Max_Heap<T> &Max_Heap<T>::operator=(const vector<T> &vec) {
    heap_vector = vec;
    heap_vector.size() = vec.heap_vector.size()();
    for (int i {heap_vector.size() / 2 - 1}; i >= 0; --i) {
        heapify(i);
    }
}

template <typename T>
void Max_Heap<T>::heapSort() {

    for (int i {size - 1}; i >= 0; --i) {
        swap(heap_vector[0], heap_vector[i]);
        --size;
        heapify(0);
    }
    size = heap_vector.size();
}

template <typename T>
void Max_Heap<T>::printAscending() {
    heapSort();
    for (int i {0}; i < size; ++i) {
        cout << heap_vector[i] << " ";
    }
    cout << endl;
}

template <typename T>
void Max_Heap<T>::printDescending() {
    heapSort();
    for (int i {size - 1}; i >= 0; --i) {
        cout << heap_vector[i] << " ";
    }
    cout << endl;
}






