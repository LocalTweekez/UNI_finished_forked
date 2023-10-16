#include "insertionSort.h"


void insertionSort(std::vector<int> &data){
    for(int i = 1; i < data.size(); i++){
        int key = data[i];
        int currentIndex = i - 1;

        while (currentIndex >= 0 && data[currentIndex] > key){
            data[currentIndex+1] = data[currentIndex];
            currentIndex--;

        }

        data[currentIndex + 1] = key;
    }
}


