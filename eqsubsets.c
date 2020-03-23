//authors: Philip Robinson and Hayden Liao
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "eqsubsets.h"

bool eq_subsets(int set[], int len, bool dynamic_programming) {
    // Declare function variables
    int sum = 0;
    // If set has at least one non-positive integer, return false
    for(int i = 0; i < len; i++) {
        if(set[i] <= 0) { return false; }
        sum += set[i];
    }
    // If sum is odd, return false
    if(sum % 2 == 1) {
        return false;
    }
    if(dynamic_programming) {
        // Just call the dynamic programming function
        return eq_subsets_dynamicprogramming(set, len, sum);
    } else {
        // Otherwise, see if there is a subset that totals T/2 through the recursive algorithm
        return eq_subsets_recusive(set, len, sum / 2);
    }
}

bool eq_subsets_recusive(int set[], int len, int target) {
    // If target is 0, we have found a subset that adds to 0
    if(target == 0) { return true; }
    // No more elements elements and target is non-zero, so there was no correct config
    if(len == 0 && target > 0) { return false; }
    // target is less than 0, so there's nothing left in sum, so no correct config
    if(target < 0) { return false; }
    // If an element is too big, don't put it in the subset, keep going
    if(set[len-1] > target) { return eq_subsets_recusive(set, len-1, target); }
    // Recursive case: Find out if any configuration works
    return (
        eq_subsets_recusive(set, len-1, target) ||
        eq_subsets_recusive(set, len-1, target - set[len-1])
    );
}

bool eq_subsets_dynamicprogramming(int set[], int len, int sum) {
    //error checking done in parent function
        /*
        If set has at least one non-positive integer, return false
    	sum = sum of elements in set
    	If sum is odd, return false
    	len = set.length
        */

	// Create table with (sum/2)+1 rows and len+1 columns
    bool table[(sum/2)+1][len+1];

    // Initialize top row of table with true (there is a subset that sums to 0)
    // Initialize left column (and the rest of the table) except for [0][0] to false
    for(int i=0; i<(sum/2)+1; i++){
        for(int j=0; j<len+1; j++){
            if(i==0){
                table[i][j] = true;
            } else {
                table[i][j] = false;
            }
        }
    }

    for(int i=1; i<sum/2+1; i++){
        for(int j=1; j<len+1; j++){
            table[i][j] = table[i][j-1]; // same return value for subset that
                                        // sums to i without item j-1
            // can have a subset that sums to i if we had a subset without
                // item j-1 that sums to (i-set[j-1])

            // second condition: if table[i][j-1] is true, the following should not overwrite it
            if(i>=set[j-1] && table[i][j-1] == false){
                table[i][j] = table[i-set[j-1]][j-1];
            }
        }
    }

    print_table(len, (sum/2)+1, set, table);
    return table[sum/2][len];
}

void print_table(int len, int height, int set[], bool table[height][len]){
    //print values
    printf("\t-\t");
    for(int j=0; j<len; j++){
        printf("%d\t", set[j]);
    }
    printf("\n");

    //print indices
    printf("\t");
    for(int j=0; j<len+1; j++){
        printf("%d\t", j);
    }
    printf("\n");


    //print table contents
    int j=0;
    for(int i=0; i<height; i++){
        printf("%d\t", i);
        for(j=0; j<len+1; j++){
            if(table[i][j]==true){
                printf("T\t");
            } else {
                printf("F\t");
            }
        }
        printf("\n");
    }
}


int main(int argc, char const *argv[]) {
    // Is the algorithm supposed to be dynamic programming or not?
    bool dp = true;

    // Create the sets
    int set0[] = {3, 1, 5, 9, 12};		// should return true
    int set1[] = {10, 7, 4, 8};		    // should return false
    int set2[] = {4, 5, 1, 11, 10, 3};  // should return true
    int set3[] = {4, 5, 6, 11, 120, 4};	// should return false

    // Test the sets
    if(   eq_subsets(set0, 5, dp) ) { printf("Set 0 passed\n"); } else { printf("Set 0 failed\n"); }
    if(   eq_subsets(set1, 4, dp) ) { printf("Set 1 passed\n"); } else { printf("Set 1 failed\n"); }
    if(   eq_subsets(set2, 6, dp) ) { printf("Set 2 passed\n"); } else { printf("Set 2 failed\n"); }
    if(   eq_subsets(set3, 6, dp) ) { printf("Set 3 passed\n"); } else { printf("Set 3 failed\n"); }

    return EXIT_SUCCESS;
}
