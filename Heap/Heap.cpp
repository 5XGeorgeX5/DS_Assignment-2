#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using std::cout, std::endl, std::swap, std::reverse, std::vector;

template <typename T>
void insert_max(vector<T> &heap, int index) {
    T temp {heap[index]};
    while (index > 0 && temp > heap[ceil(index / 2.0) - 1]) {
        heap[index] = heap[ceil(index / 2.0) - 1];
        index = ceil(index / 2.0) - 1;
    }
    heap[index] = temp;
}

template <typename T>
void insert_min(vector<T> &heap, int index) {
    T temp {heap[index]};
    while (index > 0 && temp < heap[ceil(index / 2.0) - 1]) {
        heap[index] = heap[ceil(index / 2.0) - 1];
        index = ceil(index / 2.0) - 1;
    }
    heap[index] = temp;
}

template <typename T>
void make_max_heap(vector<T> &heap) {
    for (int i {0}; i < heap.size(); ++i) {
        insert_max(heap, i);
    }
}

template <typename T>
void make_min_heap(vector<T> &heap) {
    for (int i {0}; i < heap.size(); ++i) {
        insert_min(heap, i);
    }
}

template <typename T>
T pop(vector<T> &heap) {
    T return_value {heap[0]};
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    int i {0}, j {1};
    while (j < heap.size()) {
        if (j + 1 <= heap.size() - 1 && heap[j + 1] > heap[j]) {
            ++j;
        }
        if (heap[i] < heap[j]) {
            swap(heap[i], heap[j]);
            i = j;
            j = (j * 2) + 1;
        } else {
            break;
        }
    }
    return return_value;
}

template <typename T>
void heap_sort(vector<T> &vec) {
    for (int i {1}; i < vec.size(); ++i) {
        insert_max(vec, i);
    }
    int size = vec.size();
    vector<T> temp;
    for (int i {0}; i < size; ++i) {
        T value {pop(vec)};
        temp.emplace_back(value);
    }
    reverse(temp.begin(), temp.end());
    vec = temp;
}
