#include <iostream>
#include <chrono>
#include "binarysearch.h"

#define N 1000

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
    int foundAt = binarySearch(arr, N, N);
    auto finalTime = chrono::high_resolution_clock::now();

    // Deallocating array
    delete[] arr;

    // Calculating time and printing results
    auto executionTime =
        chrono::duration_cast<chrono::nanoseconds>(finalTime - initialTime); 

    cout << "Execution time: " << executionTime.count() << "ns" << endl;
    cout << "      Elements: " << N << endl;
    cout << "      Found at: " << foundAt << endl;

    return 0;

}
