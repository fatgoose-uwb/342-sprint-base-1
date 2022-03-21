#include <cstdio>
#include "problem_1.h"
#include "problem_2.h"

/*
 * This file does run through memory check at submission.
 * However, any changes in this file will be ignored for grading, EXCEPT its compilation and memory leak
 * Meaning, if there's memory leak from this file, or it doesn't compile, there will be points penalty
 */

int main(int argc, char **argv) {
    printf("hello css342\n");

    int *data = new int[4]{1, 2, 3, 4};
    int result = Searcher::binary_search(data, 0, 4);
    printf("search result %d\n", result);
    delete[] data;

    data = new int[4]{3, 1, 2, -2};
    Sorter::bubble_sort(data, 4);
    for (int i = 0; i < 4; i++) {
        printf("%d\n", data[i]);
    }
    delete[] data;
}