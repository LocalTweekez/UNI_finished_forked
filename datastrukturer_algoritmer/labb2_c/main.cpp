#include <iostream>
#include <chrono>
#include <numeric>
#include "sorting.h"
#include <algorithm>



void print(std::vector<int>& data){
    for (auto e: data){

        std::cout << e << ", ";
    }
    std::cout << "\n"<< std::endl;

}

enum SORTING_METHOD {
    SORT_SELECTION,
    SORT_INSERTION,
    SORT_QUICKSORT,
    SORT_MO3,
    SORT_STL
};

void testrun(std::vector<int>& data, SORTING_METHOD method, std::string order, int chunksize = 20000, int intervals = 10, int samples = 10) {
    std::vector<int> testData;
    std::vector<float> sortingTimes;

    std::string methodLabel[] = {
            "Selection sort",
            "Insertion sort",
            "Quicksort",
            "Quicksort median of three",
            "Std::sort"
    };

    saveMethod(methodLabel[method], order);
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

    std::cout << "Chunk size\tAverage time\tStandard deviation\n";

    for(int i = 1; i < intervals + 1; i++) {
        sortingTimes.clear();

        // Amount of samples = 10
        for(int j = 0; j < samples; j++) {
            testData.clear();
            testData.resize(chunksize * i);

            std::copy(data.begin(), (data.begin() + chunksize*i), testData.begin());

            if (method == SORT_SELECTION) {
                start = std::chrono::high_resolution_clock::now();
                selectionSort(testData);
                end = std::chrono::high_resolution_clock::now();
            }
            else if (method == SORT_INSERTION) {
                start = std::chrono::high_resolution_clock::now();
                insertionSort(testData);
                end = std::chrono::high_resolution_clock::now();
            }
            else if (method == SORT_QUICKSORT) {
                start = std::chrono::high_resolution_clock::now();
                quicksort(testData, 0, testData.size()-1);
                end = std::chrono::high_resolution_clock::now();
            }
            else if (method == SORT_MO3) {
                start = std::chrono::high_resolution_clock::now();
                quicksort(testData, 0, testData.size()-1, true);
                end = std::chrono::high_resolution_clock::now();
            }
            else if (method == SORT_STL) {
                start = std::chrono::high_resolution_clock::now();
                std::sort(testData.begin(), testData.end());
                end = std::chrono::high_resolution_clock::now();
            }

            std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            float time = ms.count();

            sortingTimes.push_back(time);
        }


        saveData(testData.size(), sortingTimes);

    }
}
void TryAllDataorders(SORTING_METHOD method){
    const int chunksize = 20000;
    const int intervals = 10;
    dataGenerator dg;

    std::vector<int> random;
    std::vector<int> constant;
    std::vector<int> desc;
    std::vector<int> asc;

    dg.generateAscending(asc, (chunksize * intervals));
    dg.generateConstant(constant, 3, (chunksize * intervals));
    dg.generateDescending(desc,(chunksize * intervals));
    dg.generateRandom(random, (chunksize * intervals));

    testrun(asc, method,"ascending", chunksize, intervals);
    testrun(constant, method,"constant", chunksize, intervals);
    testrun(desc, method,"descending", chunksize, intervals);
    testrun(random, method,"random", chunksize, intervals);
}

int main() {
    const int chunksize = 2000;
    const int intervals = 10;

    std::vector<int> random;
    std::vector<int> constant;
    std::vector<int> desc;
    std::vector<int> asc;
    dataGenerator dg;
    dg.generateAscending(asc, (chunksize * intervals));
    dg.generateConstant(constant, 3, (chunksize * intervals));
    dg.generateDescending(desc,(chunksize * intervals));
    dg.generateRandom(random, (chunksize * intervals));
//----------------------------------------------------------------------------------------------
   SORTING_METHOD method = SORT_SELECTION;
    testrun(asc, method,"ascending", 2000, intervals);
    testrun(constant, method,"constant", 2000, intervals);
    testrun(desc, method,"descending", 2000, intervals);
    testrun(random, method,"random", 2000, intervals);
////----------------------------------------------------------------------------------------------
    method = SORT_INSERTION;
    dg.generateAscending(asc, (20000 * intervals));
    dg.generateConstant(constant, 3, (20000 * intervals));
    dg.generateDescending(desc,(chunksize * intervals));
    dg.generateRandom(random, (chunksize * intervals));

    testrun(asc, method,"ascending", 20000, intervals);
    testrun(constant, method,"constant", 20000, intervals);
    testrun(desc, method,"descending", 2000, intervals);
    testrun(random, method,"random", 2000, intervals);

    method = SORT_QUICKSORT;
    dg.generateAscending(asc, (chunksize * intervals));
    dg.generateConstant(constant, 3, (chunksize * intervals));
    dg.generateDescending(desc,(chunksize * intervals));
    dg.generateRandom(random, (20000 * intervals));

    testrun(asc, method,"ascending", 2000, intervals);
    testrun(constant, method,"constant", 2000, intervals);
    testrun(desc, method,"descending", 2000, intervals);
    testrun(random, method,"random", 20000, intervals);

    method = SORT_MO3;
    dg.generateAscending(asc, (20000 * intervals));
    dg.generateConstant(constant, 3, (2000 * intervals));
    dg.generateDescending(desc,(20000 * intervals));
    dg.generateRandom(random, (20000 * intervals));

    testrun(asc, method,"ascending", 20000, intervals);
    testrun(constant, method,"constant", 2000, intervals);
    testrun(desc, method,"descending", 20000, intervals);
    testrun(random, method,"random", 20000, intervals);
    method = SORT_STL;
    dg.generateAscending(asc, (20000 * intervals));
    dg.generateConstant(constant, 3, (20000 * intervals));
    dg.generateDescending(desc,(20000 * intervals));
    dg.generateRandom(random, (20000 * intervals));

    testrun(asc, method,"ascending", 20000, intervals);
    testrun(constant, method,"constant", 20000, intervals);
    testrun(desc, method,"descending", 20000, intervals);
    testrun(random, method,"random", 20000, intervals);

}

