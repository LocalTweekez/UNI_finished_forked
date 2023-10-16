#include "selectionSort.h"

void selectionSort(std::vector<int> &data){

    for (int i = 0; i < data.size() - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < data.size(); j++) {
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(data[i], data[minIndex]);
    }
}
