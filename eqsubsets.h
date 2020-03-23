//authors Philip Robinson and Hayden Liao
#ifndef EQSUBSETS_H
#define EQSUBSETS_H

bool eq_subsets(int set[], int len, bool dynamic_programming);
bool eq_subsets_recusive(int set[], int len, int target);
bool eq_subsets_dynamicprogramming(int set[], int len, int sum);
void print_table(int len, int height, int set[], bool table[height][len]); 

#endif
