#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "eqsubsets.h"

bool eq_subsets(int set[], int len, bool dynamic_programming) {
    if(dynamic_programming) {
        // Just call the dynamic programming function
        return eq_subsets_dynamicprogramming(set, len);
    } else {
        // Declare function variables
        int sum = 0;
        // If set has at least one non-positive integer, return false
        for(int i = 0; i < len; i++) {
            if(set[i] <= 0) { return false; }
            sum += set[i];
        }
        // If sum is odd, return false
        if(sum % 2 == 1) { return false; }
        // Otherwise, see if there is a subset that totals T/2 through the recursive algorithm
        return eq_subsets_recusive(set, len, sum / 2);
    }
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

bool eq_subsets_dynamicprogramming(int set[], int len) {
	// If L has at least one non-positive integer, return false
	// T = sum of elements in L
	// If T is odd, return false
	// N = L.length
	// Create table with (T/2)+1 rows and N+1 columns
	// Initialize top row of table with true (there is a subset that sums to 0)
	// Initialize left column except for [0][0] with false
	// For i from 1 to (T/2):
	// 	For j from 1 to N:
	// 		Table[i][j] = Table[i][j-1]  // same return value for subset that
	// 						  // sums to i without item j-1
	// 		// can have a subset that sums to i if we had a subset without
	// 		// item j-1 that sums to (i-L[j-1])
	// 		if i >= L[j-1]
	// 			Table[i][j] = Table[i][j] or Table[i-L[j-1]][j-1]
	// Return Table[T/2][N]
    return true;
}


int main(int argc, char const *argv[]) {
    // Is the algorithm supposed to be dynamic programming or not?
    bool dp = false;

    // Create the sets
    int set0[] = {3, 1, 5, 9, 12};		// should return true
    int set1[] = {10, 7, 4, 8};		    // should return false
    int set2[] = {4, 5, 1, 11, 10, 3};  // should return true
    int set3[] = {4, 5, 6, 11, 120, 4};	// should return false

    // Test the sets
    if(   eq_subsets(set0, 5, dp) ) { printf("Set 0 passed\n"); } else { printf("Set 0 failed\n"); }
    if( ! eq_subsets(set1, 4, dp) ) { printf("Set 1 passed\n"); } else { printf("Set 1 failed\n"); }
    if(   eq_subsets(set2, 6, dp) ) { printf("Set 2 passed\n"); } else { printf("Set 2 failed\n"); }
    if( ! eq_subsets(set3, 7, dp) ) { printf("Set 3 passed\n"); } else { printf("Set 3 failed\n"); }

    return EXIT_SUCCESS;
}
