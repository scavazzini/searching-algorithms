#include "linearsearch.h"

int LinearSearch::search(const int *arr, int arrSize, int element) {

    for (int i = 0; i < arrSize; i++) {

        if (element == arr[i]) {
            return i;
        }

    }
    return -1;

}
