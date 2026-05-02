#ifndef SORT_H
#define SORT_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <type_traits>


template<typename T>
bool is_sorted(const std::vector<T>& vec) {
    if (vec.size() <= 1) return true;
    for (size_t i = 0; i < vec.size() - 1; i++) {
        if (vec[i] > vec[i + 1]) return false;
    }
    return true;
}


template<typename T>
void bubble_sort(std::vector<T>& vec) {
    if (vec.size() <= 1) return;
    for (size_t i = 0; i < vec.size() - 1; i++) {
        for (size_t j = vec.size() - 1; j > i; j--) {
            if (vec[j] < vec[j - 1]) std::swap(vec[j], vec[j - 1]);
        }
    }
}


template<typename T>
void selection_sort(std::vector<T>& vec) {
    if (vec.size() <= 1) return;
    for (size_t i = 0; i < vec.size() - 1; i++) {
        size_t min_ind = i;
        for (size_t j = i + 1; j < vec.size(); j++) {
            if (vec[j] < vec[min_ind]) min_ind = j;
        }
        if (min_ind != i) std::swap(vec[i], vec[min_ind]);
    }
}

template<typename T>
void insertion_sort(std::vector<T>& vec) {
    if (vec.size() <= 1) return;
    for (size_t j = 1; j < vec.size(); j++) {
        T key = vec[j];
        int i = j - 1;
        while (i >= 0 && vec[i] > key) {
            vec[i + 1] = vec[i];
            i--;
        }
        vec[i + 1] = key;
    }
}


template<typename T>
int partition(std::vector<T>& vec, int low, int high) {
    T pivot = vec[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (vec[j] <= pivot) {
            i++;
            std::swap(vec[i], vec[j]);
        }
    }
    std::swap(vec[i + 1], vec[high]);
    return i + 1;
}

template<typename T>
void quick_sort(std::vector<T>& vec, int low, int high) {
    if (low < high) {
        int q = partition(vec, low, high);
        quick_sort(vec, low, q - 1);
        quick_sort(vec, q + 1, high);
    }
}

template<typename T>
void merge(std::vector<T>& vec, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    std::vector<T> L(n1 + 1);
    std::vector<T> R(n2 + 1);

    for (int i = 0; i < n1; i++) L[i] = vec[p + i];
    for (int j = 0; j < n2; j++) R[j] = vec[q + j + 1];

    
    if constexpr (std::is_same_v<T, int>) {
        L[n1] = 2147483647;
        R[n2] = 2147483647;
    } else if constexpr (std::is_same_v<T, std::string>) {
        L[n1] = "~~~~~~~~~~~~~~~~";
        R[n2] = "~~~~~~~~~~~~~~~~";
    }

    int i = 0, j = 0;
    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = R[j];
            j++;
        }
    }
}

template<typename T>
void merge_sort(std::vector<T>& vec, int p, int r) {
    if (p < r) {
        int q = p + (r - p) / 2;
        merge_sort(vec, p, q);
        merge_sort(vec, q + 1, r);
        merge(vec, p, q, r);
    }
}
template<typename T>
void insertion_sort_range(std::vector<T>& vec, int low, int high) {
    if (low >= high) return;
    for (int j = low + 1; j <= high; j++) {
        T key = vec[j];
        int i = j - 1;
        while (i >= low && vec[i] > key) {
            vec[i + 1] = vec[i];
            i--;
        }
        vec[i + 1] = key;
    }
}
template<typename T>
void quick_sort_hybrid(std::vector<T>& vec, int low, int high) {
    int n = high - low + 1;
    if(n<=20){
        insertion_sort_range(vec, low, high);
    }
    else{
        if (low < high) {
            int q = partition(vec, low, high);
            quick_sort_hybrid(vec, low, q - 1);
            quick_sort_hybrid(vec, q + 1, high);
        }
}
}
#endif 