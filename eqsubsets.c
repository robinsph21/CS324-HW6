#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool eq_subsets(int set[], int len) {
    // If L has at least one non-positive integer, return false
	// T = sum of elements in L
	// If T is odd, return false
	// N = L.length
	// EQ_SUBSETS_R(L, N, T/2)		// see if there is a subset that totals T/2
    return eq_subsets_recusive({}, 0, 0);
}

bool eq_subsets_recusive(int set[], int len, int target) {
    // 	If S == 0, return true                          // we have found a subset (empty) that adds to 0
    // 	If N==0 and S > 0, return false                 // out of elements and S > 0
    // 	If S < 0, return false                          // S < 0, so nothing left in sum
    // 	If L[N-1] > S, return EQ_SUBSETS_R(L, N-1, S)   // too big to put in subset
    // 	return EQ_SUBSETS_R(L, N-1, S) || EQ_SUBSETS_R(L, N-1, S – L[N-1])
     		// first call does not put element in subset
            // second call puts element in subset
    return true;
}

int main(int argc, char const *argv[]) {
    // Create the sets
    int set0[] = {3, 1, 5, 9, 12};		// should return true
    int set1[] = {10, 7, 4, 8};		    // should return false
    int set2[] = {4, 5, 1, 11, 10, 3};  // should return true
    int set3[] = {4, 5, 6, 11, 120, 4};	// should return false

    // Test the sets
    if(eq_subsets(set0, 5)) { printf("Set 0 passed\n"); } else { printf("Set 0 failed\n"); }
    if(!eq_subsets(set1, 4)) { printf("Set 1 passed\n"); } else { printf("Set 1 failed\n"); }
    if(eq_subsets(set2, 6)) { printf("Set 2 passed\n"); } else { printf("Set 2 failed\n"); }
    if(!eq_subsets(set0, 7)) { printf("Set 3 passed\n"); } else { printf("Set 3 failed\n"); }

    return EXIT_SUCCESS;
}
