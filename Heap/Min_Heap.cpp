#include "Min_Heap.h"

template<typename T>
void Min_Heap::heapify(vector<T> &heap, int i) {
    int largest {i};
    int left_child {i * 2 + 1};
    int right_child {i * 2 + 2};

    if (left_child < heap.size() && heap[left_child] < heap[largest]) {
        largest = left_child;
    }
    if (right_child < heap.size() && heap[right_child] < heap[largest]) {
        largest = right_child;
    }

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapify(heap, largest);
    }
}

template<typename T>
void Min_Heap::insert(vector<T> &heap, T input) {
    input.emplace_back(heap);
    for (int i = heap.size() / 2 - 1; i >= 0; --i) {
        heapify(heap, i);
    }
}

template<typename T>
void Min_Heap::delete_item(vector<T> &heap, T input) {
    int i {0};

    for (; i < heap.size(); ++i) {
        if (heap[i] == input) {
            break;
        }
    }

    swap(heap[i], heap[heap.size() - 1]);
    heap.pop_back();

    for (i = heap.size() / 2 - 1; i >= 0; --i) {
        heapify(heap, i);
    }
}


