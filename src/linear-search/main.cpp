#include <iostream>
#include <chrono>
#include "linearsearch.h"

#define N 100000000

using namespace std;

int main() {

    // Instantiate array
    int* arr = new int[N];

    // Populating the array
    for (int i = 0; i < N; i++) {
        arr[i] = i;
    }

    // Running the algorithm and measuring time
    auto initialTime = chrono::high_resolution_clock::now();
    int foundAt = linearsearch(arr, N, N);
    auto finalTime = chrono::high_resolution_clock::now();

    // Deallocating array
    delete[] arr;

    // Calculating time and printing results
    auto executionTime =
        chrono::duration_cast<chrono::milliseconds>(finalTime - initialTime); 

    cout << "Execution time: " << executionTime.count() << "ms" << endl;
    cout << "    Array size: " << N << endl;

    return 0;

}
