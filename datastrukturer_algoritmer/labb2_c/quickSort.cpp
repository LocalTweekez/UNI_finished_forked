#include "quickSort.h"

int medianOfThree(std::vector<int>& data, int low, int high) {
    int mid = low + (high - low) / 2;

    if (data[low] > data[mid])
        std::swap(data[low], data[mid]);

    if (data[low] > data[high])
        std::swap(data[low], data[high]);

    if (data[mid] > data[high])
        std::swap(data[mid], data[high]);

    return mid;
}

int partition(std::vector<int>& data, int low, int high, bool useMedianOfThree) {
    int pivotIndex = useMedianOfThree ? medianOfThree(data, low, high) : high;
    int pivot = data[pivotIndex];
    int i = low - 1;

    std::swap(data[pivotIndex], data[high]);

    for (int j = low; j < high; j++) {
        if (data[j] <= pivot) {
            i++;
            std::swap(data[i], data[j]);
        }
    }

    std::swap(data[i + 1], data[high]);
    return i + 1;
}

void quicksort(std::vector<int>& data, int low, int high, bool useMedianOfThree) {
    if (low < high) {
        int pivotIndex = partition(data, low, high, useMedianOfThree);
        quicksort(data, low, pivotIndex - 1, useMedianOfThree);
        quicksort(data, pivotIndex + 1, high, useMedianOfThree);
    }
}