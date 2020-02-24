#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include "binarysearch.h"

using namespace std;

int main() {

    ofstream file;
    file.open("result.csv");

    if (file.is_open() == false) {
        return 1;
    }

    int groups[10] = {
        1,
        10,
        100,
        1000,
        10000,
        100000,
        1000000,
        10000000,
        100000000,
        1000000000,
    };

    vector<long long> t;

    for (int i = 0; i < 10; i++) {

        t.clear();

        for (int j = 0; j < 50; j++) {

            // Instantiate array
            int* arr = new int[groups[i]];

            // Populating the array
            for (int l = 0; l < groups[i]; l++) {
                arr[l] = l;
            }

            // // Running the algorithm and measuring time
            auto initialTime = chrono::high_resolution_clock::now();
            int foundAt = binarySearch(arr, groups[i], groups[i]);
            auto finalTime = chrono::high_resolution_clock::now();

            // Deallocating array
            delete[] arr;

            // Calculating time and printing results
            auto executionTime =
                chrono::duration_cast<chrono::nanoseconds>(finalTime - initialTime);

            t.push_back(executionTime.count());

            file << groups[i] << ";" << executionTime.count() << endl;

        }

        long long sum = 0;
        for (int k = 0; k < t.size(); k++) {
            sum += t[k];
        }
        
        file << "> " << groups[i] << ";" << ((double)sum/t.size()) << endl << endl;

    }

    file.close();
    return 0;

}
