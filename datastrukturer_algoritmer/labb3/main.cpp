#include "searching.h"

int size = 40000001;
int elementSize = 2000;
int intervals = 1000;

const int samples = 10;

std::vector<int> SieveOfEratosthenes(int n) {
    std::vector<int> returnData;
    std::vector<bool> array(n, true);

    array[0] = false;
    array[1] = false;

    for(int i = 2; pow(i,2) < n; i++) {
        if(array[i]) {
            for(int j = i*2; j < n; j += i) {
                array[j] = false;
            }
        }
    }
    for(int i = 2; i < n; i++) {
        if(array[i]) {
            returnData.push_back(i);
        }
    }
    return returnData;
}
enum SEARCH_ALGORITHMS {
    SEARCH_LINEAR,
    SEARCH_BINARY,
    SEARCH_BST,
    SEARCH_HASHMAP
};
enum TIME_COMPLEXITY {
    CASE_BEST,
    CASE_RAND,
    CASE_WORST
};

// Enum to string by indexing
std::string method[] = {
        "Linear search",
        "Binary search",
        "BST search",
        "Hashtable search",
        "Null"
};

bool testData(std::vector<int>& vec,
              SEARCH_ALGORITHMS searchMethod,
              TIME_COMPLEXITY timeCase = CASE_RAND) {



    // Linear search and binary search
    //searchLinear searchLin(vec);
    //searchBinary searchBin(vec);

    // Binary search tree object
    BST_Search bst_search(vec);
    BstNode* root = bst_search.assignBST(0,vec.size());
    int dummyBST = 0;

    // Hashtable object
    // Size of hashtable is below 50%
    int hashMapSize = (int)vec.size() / 2;
    std::vector<std::vector<int>> hash_map(hashMapSize);
    Hash_Search hash_search(vec, hash_map);
    std::pair<int,int> dummyHash;
    // ==========================================================================

    // Initialize testing parameters
    int guess = 0;
    int randElement = 0;
    double searchTime = 0;
    double averageTime = 0;
    double totalTime = 0;
    double stdDev = 0;

    std::vector<int> testdata;
    std::vector<double> searchTimes;
    std::vector<double> stdDevs;
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime, endTime;
    container_table table; // Four-valued vector table, see MyFunctions.h

    // Clear all the table data
    table.first.first.clear();
    table.first.second.clear();
    table.second.first.clear();
    table.second.second.clear();

    std::cout << "======================= " << method[searchMethod] << " =======================\n";
    std::cout << "Elements\tAverage time[ms]\tTest runs\tStdDev[ms]\n";

    for(int i = 1; i < intervals + 1; i++) {
        // Clear old data
        totalTime = 0;
        searchTimes.clear();

        testdata.clear();
        testdata.resize(elementSize * i);

        if(searchMethod == SEARCH_LINEAR || searchMethod == SEARCH_BINARY) {
            std::copy(vec.begin(), (vec.begin() + elementSize * i), testdata.begin());
        }
        else if(searchMethod == SEARCH_BST) {
            bst_search.deleteTree(root);
            root = bst_search.assignBST(0, (elementSize * i)-1);
        }
        else if(searchMethod == SEARCH_HASHMAP) {
            hash_search.refillMap(vec, hashMapSize,elementSize,i);
        }

        std::chrono::nanoseconds ms = std::chrono::nanoseconds::zero();
        int counter = 0;
        int numberToFind = -1;

        if(timeCase == CASE_RAND) {
            numberToFind = rand() % testdata.size() - 1;
        }
        else if(timeCase == CASE_BEST) {
            numberToFind = 2;
        }
        else if(timeCase == CASE_WORST) {
            numberToFind = testdata.back();
        }
        //std::cout << "testdata size: " << testdata.size() << ", last element is " << testdata.back() << " and searched element is " << numberToFind << "\n";
        /*
        for(auto &e : testdata)
            std::cout << e << ", ";
        std::cout << "\n\n";
        */

        for(int j = 0; j < samples; j++) {

            if(searchMethod == SEARCH_LINEAR) {
                startTime = std::chrono::high_resolution_clock::now();
                //searchLin.Search(numberToFind, testdata);
                searchLinear(numberToFind, testdata);
                endTime = std::chrono::high_resolution_clock::now();
            }
            else if (searchMethod == SEARCH_BINARY) {
                startTime = std::chrono::high_resolution_clock::now();
                //searchBin.Search(numberToFind, testdata);
                searchBinary(numberToFind, testdata);
                endTime = std::chrono::high_resolution_clock::now();
            }
            else if (searchMethod == SEARCH_BST) {
                startTime = std::chrono::high_resolution_clock::now();
                dummyBST = bst_search.bstSearch(root, numberToFind);
                endTime = std::chrono::high_resolution_clock::now();
            }
            else if (searchMethod == SEARCH_HASHMAP) {
                startTime = std::chrono::high_resolution_clock::now();
                dummyHash = hash_search.hashSearch(numberToFind);
                endTime = std::chrono::high_resolution_clock::now();
            }

            // Result in each case is stored as an integer, then pushed back in execution time vector
            ms = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
            auto duration = (int)ms.count();
            counter++;
            searchTimes.push_back(duration);
        }


        // Total and average time calculated
        auto averageTime = std::accumulate(searchTimes.begin(), searchTimes.end(), 0) / searchTimes.size();

        auto maxElement = *std::max_element(searchTimes.begin(), searchTimes.end());
        std::cout << testdata.size() << "<\t\t" << averageTime << "\t\t\t" << searchTimes.size() << "\t\t" << calculateStdDev(searchTimes) << "\t\t" << maxElement<<"\n";

        // All the data stored in 4-valued table
        table.first.first.push_back(testdata.size());
        table.first.second.push_back(averageTime);
        table.second.first.push_back(searchTimes.size());
        table.second.second.push_back(calculateStdDev(searchTimes));

    }

    saveData(table,"text",method[searchMethod],intervals);
    return true;
}

void TryAllDataOrders() {

    std::vector<int> primeVector = SieveOfEratosthenes(size);
    std::cout << "Amount of prime integers: " << primeVector.size() << ": \n";

    if(primeVector.size() < elementSize * intervals) {
        std::cout << "Size of vector: " << primeVector.size() << " is too small (less than "<< elementSize * intervals << "), returning zero\n";
        return;
    }


    testData(primeVector, SEARCH_LINEAR, CASE_RAND);
    testData(primeVector, SEARCH_BINARY,  CASE_RAND);
    testData(primeVector, SEARCH_BST, CASE_RAND);
    testData(primeVector, SEARCH_HASHMAP, CASE_RAND);

    testData(primeVector, SEARCH_LINEAR, CASE_BEST);
    testData(primeVector, SEARCH_BINARY,  CASE_BEST);
    testData(primeVector, SEARCH_BST, CASE_BEST);
    testData(primeVector, SEARCH_HASHMAP, CASE_BEST);


    testData(primeVector, SEARCH_LINEAR, CASE_WORST);
    testData(primeVector, SEARCH_BINARY,  CASE_WORST);
    testData(primeVector, SEARCH_BST, CASE_WORST);
    testData(primeVector, SEARCH_HASHMAP, CASE_WORST);


}

int main() {
    srand(time(nullptr));

    TryAllDataOrders();
    return 0;
}
