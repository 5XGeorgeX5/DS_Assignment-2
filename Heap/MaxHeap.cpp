#include <vector>
#include <iostream>
#include <algorithm>
#include "../item.cpp"

using std::cout, std::endl, std::vector, std::swap, std::reverse;

class MaxHeap
{
private:
    bool (*lessCompare)(const item &, const item &);
    vector<item> heap_vector;
    int size;
    void heapify(int i)
    {
        int largest{i};
        int left_child{i * 2 + 1};
        int right_child{i * 2 + 2};

        if (left_child < size && lessCompare(heap_vector[largest], heap_vector[left_child]))
        {
            largest = left_child;
        }
        if (right_child < size && lessCompare(heap_vector[largest], heap_vector[right_child]))
        {
            largest = right_child;
        }

        if (largest != i)
        {
            swap(heap_vector[i], heap_vector[largest]);
            heapify(largest);
        }
    }
    void heapSort()
    {
        for (int i{size - 1}; i >= 0; --i)
        {
            swap(heap_vector[0], heap_vector[i]);
            --size;
            heapify(0);
        }
        reverse(heap_vector.begin(), heap_vector.end());
        size = heap_vector.size();
    }

public:
    MaxHeap(bool (*lessCompare)(const item&, const item&)){
        size = 0;
        this->lessCompare = lessCompare;
    }
    MaxHeap(const vector<item> &vec)
    {
        heap_vector = vec;
        size = vec.size();
        for (int i{size / 2 - 1}; i >= 0; --i)
        {
            heapify(i);
        }
    }

    void insert(const item &input)
    {
        heap_vector.emplace_back(input);
        int current{size};
        while (lessCompare(heap_vector[(current - 1) / 2], heap_vector[current]))
        {
            swap(heap_vector[(current - 1) / 2], heap_vector[current]);
            current = (current - 1) / 2;
        }
        size++;
    }

    void remove(const item &input)
    {
        int i{0};

        for (; i < heap_vector.size(); ++i)
        {
            if (!(heap_vector[i] != input))
            {
                break;
            }
        }

        swap(heap_vector[i], heap_vector[size - 1]);
        heap_vector.pop_back();
        size--;
        heapify(i);
    }
    void printAscending()
    {
        heapSort();
        for (int i{size - 1}; i >= 0; --i)
        {
            heap_vector[i].print();
        }
        cout << endl;
    }
    void printDescending()
    {
        heapSort();
        for (int i{0}; i < size; ++i)
        {
            heap_vector[i].print();
        }
        cout << endl;
    }
};