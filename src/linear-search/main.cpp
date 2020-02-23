#include <iostream>
#include <chrono>
#include "linearsearch.h"

#define N 100000000

using namespace std;

int main() {

    int* arr = new int[N];

    for (int i = 0; i < N; i++) {
        arr[i] = i;
    }

    auto initialTime = chrono::high_resolution_clock::now();
    int foundAt = linearsearch(arr, N, N);
    auto finalTime = chrono::high_resolution_clock::now();

    delete[] arr;

    auto executionTime =
        chrono::duration_cast<chrono::milliseconds>(finalTime - initialTime); 

    cout << "Execution time: " << executionTime.count() << "ms" << endl;
    cout << "    Array size: " << N << endl;

    return 0;

}
