#include "Sort.h"

template <typename T>
Sort<T>::Sort(std::vector<T> arr) 
    : m_arr(arr) 
{}

template <typename T>
Sort<T>::Sort(std::initializer_list<T> arr) 
    : m_arr(arr)
{} 

template <typename T>
Sort<T>::~Sort()
{}

template <typename T>
void Sort<T>::shuffleArray()
{
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(std::begin(m_arr), std::end(m_arr), g);
}

template <typename T>
void Sort<T>::printArray()
{
    for (auto& elem : m_arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

template <typename T>
void Sort<T>::BubbleSort()
{
    for (int i = 0; i < m_arr.size(); ++i) {
        bool sorted = true;
        for (int j = 0; j < m_arr.size() - 1 - i; ++j) {
            if (m_arr[j] > m_arr[j + 1]) {
                std::swap(m_arr[j], m_arr[j + 1]);
                sorted = false;
            }
        }
        if (sorted) 
            break;
    }
}

template <typename T>
void Sort<T>::SelectionSort()
{
    for (int i = 0; i < m_arr.size() - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < m_arr.size(); ++j) {
            if (m_arr[j] < m_arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) 
            std::swap(m_arr[i], m_arr[minIndex]);
    }
}

template <typename T>
void Sort<T>::InsertionSort()
{
    for (int i = 1; i < m_arr.size(); ++i) {
        T key = m_arr[i];
        int j = i - 1;
        while (j >= 0 && m_arr[j] > key) {
            m_arr[j + 1] = m_arr[j];
            --j;
        }
        m_arr[j + 1] = key;
    }
}

template <typename T>
void Sort<T>::MergeSort()
{
    MergeSort(0, m_arr.size() - 1);
}

template <typename T>
void Sort<T>::MergeSort(int start, int end)
{
    if (start < end) {
        int mid = start + (end - start) / 2;  
        MergeSort(start, mid);
        MergeSort (mid + 1, end);
        Merge(start, mid, end);
    }
}

template <typename T>
void Sort<T>::Merge(int start, int mid, int end)
{
    if(m_arr.empty())
        return;
    std::vector<T> vec1(mid - start + 1);
    std::vector<T> vec2(end - mid);

    for (int i = 0; i < vec1.size(); ++i) 
        vec1[i] = m_arr[start + i];

    for (int i = 0; i < vec2.size(); ++i)
        vec2[i] = m_arr[mid + i + 1];

    int i = 0, j = 0, index = start;

    while (i < vec1.size() && j < vec2.size()) {
        if (vec1[i] < vec2[j]) 
            m_arr[index++] = vec1[i++];
        else 
            m_arr[index++] = vec2[j++];       
    }        

    while (i < vec1.size())
        m_arr[index++] = vec1[i++];
    while (j < vec2.size())
        m_arr[index++] = vec2[j++];        
}

template<typename T>
void Sort<T>::QuickSort()
{
    QuickSort(0, m_arr.size() - 1);
}

template<typename T>
void Sort<T>::QuickSort(int start, int end)
{
    if(m_arr.empty())
        return;
    if (start < end) {
        int pi = partition(start, end);
        QuickSort(start, pi - 1);
        QuickSort(pi + 1, end);
    }
}

template <typename T>
int Sort<T>::partition(int start, int end)
{
    int randInd = start + rand() % (end - start + 1);
    std::swap(m_arr[end], m_arr[randInd]);
    int pivot = m_arr[end];
    int i = start;
    int j = end - 1;

    while (true) {
        while (i < end && m_arr[i] < pivot) 
            ++i;

        while (j > start && m_arr[j] > pivot) 
            --j;

        if (i >= j)
            break;

        std::swap(m_arr[i], m_arr[j]);        
    }
    std::swap(m_arr[i], m_arr[end]);
    return i;
}

template <typename T>
void Sort<T>::CountingSort()
{
    if(m_arr.empty())
        return;

    T min = *std::min_element(m_arr.begin(), m_arr.end());
    T max = *std::max_element(m_arr.begin(), m_arr.end());

    int range = max - min + 1;

    std::vector<int> counts(range, 0);
    std::vector<T> res(m_arr.size());

    for (T& elem : m_arr) {
        ++counts[elem - min];
    }

    for (int i = 1; i < range; ++i) {
        counts[i] += counts[i - 1];
    }

    for (int i = m_arr.size() - 1; i >= 0; --i) {
        res[counts[m_arr[i] - min] - 1] = m_arr[i];
        --counts[m_arr[i] - min];
    }

    m_arr = std::move(res);
}

template <typename T>
void Sort<T>::HeapSort()
{
    int n = m_arr.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(n, i);
    }

    for (int i = n - 1; i > 0; --i) {
        std::swap(m_arr[0], m_arr[i]);
        heapify (i, 0);
    }
}

template <typename T>
void Sort<T>::heapify(int n, int i)
{
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    if (left < n && m_arr[left] > m_arr[largest])
        largest = left;

    if (right < n && m_arr[right] > m_arr[largest])
        largest = right;

    if (largest != i) {
        std::swap (m_arr[i], m_arr[largest]);
        heapify (n, largest);
    }
}

template <typename T>
void Sort<T>::CountingForRadix(std::vector<T>& arr, int exp)
{
    std::vector<T> output(arr.size());
    int counts[10] = {0};

    for (size_t i = 0; i < arr.size(); ++i) {
        int index = (arr[i] / exp) % 10;
        ++counts[index];
    }

    for (int i = 1; i < 10; ++i) {
        counts[i] += counts[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; --i) {
        int index = (arr[i] / exp) % 10;
        output[--counts[index]] = arr[i];
    }

    arr = std::move(output);
}

template <typename T>
void Sort<T>::RadixSort()
{
    std::vector<T> positive;
    std::vector<T> negative;

    for (auto& elem : m_arr) {
        if (elem >= 0) 
            positive.push_back(elem);
        else 
            negative.push_back(-elem);    
    }

    if (!positive.empty()) {
        T max = *std::max_element(positive.begin(), positive.end());
        for (int exp = 1; max / exp > 0; exp *= 10) {
            CountingForRadix(positive, exp);
        }
    }

    if (!negative.empty()) {
        T max = *std::max_element(negative.begin(), negative.end());
        for (int exp = 1; max / exp > 0; exp *= 10) {
            CountingForRadix(negative, exp);
        }

        std::reverse(negative.begin(), negative.end());
        for (auto& elem : negative) {
            elem = -elem;
        }
    }

    m_arr = std::move(negative);
    m_arr.insert(m_arr.end(), positive.begin(), positive.end());
}