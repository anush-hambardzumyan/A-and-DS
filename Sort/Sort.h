#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <vector>
#include <initializer_list>
#include <random>
#include <algorithm>
#include <type_traits>

template <typename T>
class Sort {
    private:
        std::vector<T> m_arr;
    public:
        Sort(std::vector<T>);
        Sort(std::initializer_list<T>);
        ~Sort();
        void shuffleArray();
        void printArray();
        void BubbleSort();          //O(n^2)
        void SelectionSort();       //O(n^2)
        void InsertionSort();       //O(n^2)
        void MergeSort();           //O(nlogn)
        void QuickSort();           //O(nlogn)
        void CountingSort();        //O(n + range)
        void RadixSort();           //
        void HeapSort();            //

    private:
        void MergeSort(int start, int end);
        void Merge(int start, int mid, int end); 

        void QuickSort(int start, int end);
        int partition(int start, int end);   
        
        void CountingForRadix(std::vector<T>& arr, int exp);

        void heapify(int n, int i);
};

#include "Sort.hpp"
#endif