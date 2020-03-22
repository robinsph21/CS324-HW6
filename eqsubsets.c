#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool eq_subsets() {
    return true;
}

int main(int argc, char const *argv[]) {
    int set0[] = {3, 1, 5, 9, 12};		// should return true
    int set1[] = {10, 7, 4, 8};		    // should return false
    int set2[] = {4, 5, 1, 11, 10, 3};  // should return true
    int set3[] = {4, 5, 6, 11, 120, 4};	// should return false

    return EXIT_SUCCESS;
}
