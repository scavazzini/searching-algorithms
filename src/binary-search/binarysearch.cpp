#include "binarysearch.h"

int BinarySearch::search(const int *arr, int arrSize, int element) {

    int left = 0;
    int middle = 0;
    int right = arrSize - 1;

    while (left <= right) {

        middle = (left + right) / 2;

        if (element < arr[middle]) {
            right = middle - 1;
        }
        else if (element > arr[middle]) {
            left = middle + 1;
        }
        else {
            return middle;
        }

    }
    return -1;

}

