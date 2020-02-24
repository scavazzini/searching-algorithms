#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include <ctime>
#include <string>
#include "binary-search/binarysearch.h"

using namespace std;

ofstream file;

const vector<int> GROUPS = {
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
const int TIMES_EACH = 5000;

bool openFile() {
    string timestamp = to_string(time(NULL));

    file.open("results_" + timestamp + ".csv");
    return file.is_open();
}

int main() {

    bool fileOpened = openFile();
    if (fileOpened == false) {
        cout << "Failed to open results file." << endl;
        return 1;
    }

    vector<int> results;

    for (int n: GROUPS) {

        results.clear();

        // Instantiate array
        int* arr = new int[n];

        // Populating the array
        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }

        for (int j = 0; j < TIMES_EACH; j++) {

            // Running the algorithm and measuring time
            auto initialTime = chrono::high_resolution_clock::now();
            int foundAt = binarySearch(arr, n, n);
            auto finalTime = chrono::high_resolution_clock::now();

            // Calculating time and printing results
            auto executionTime =
                chrono::duration_cast<chrono::nanoseconds>(finalTime - initialTime);

            results.push_back(executionTime.count());

        }

        // Deallocating array
        delete[] arr;

        // Calculating the avg result
        int sumResult = 0;
        for (int result: results) {
            sumResult += result;
        }
        int avgResult = (double) sumResult / results.size();
        
        // Writing result to file
        file << n << ";" << avgResult << endl;

    }

    file.close();
    return 0;

}
