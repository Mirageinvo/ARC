//HASH
//stdin  -> page
//stdout -> adress of that page + in that adress should be val of that page + I should feel
//          the hash_table


/*
int hash_main() {
  ...
  int c, *hash_table;
  ...
  create_hash_table(hash_table); //here c comes up from the stdin, it's a size of a cache
  ...
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void create_hash_table(int* hash_table);
int hash_for_idx(int page);
int check(int page, int* hash_table);
void nulify(int page, int* hash_table);
int collision_check(int page, int* hash_table);
int* hash_of_el (int page, int* hash_table);



void create_hash_table(int* hash_table) {
  int our_constant_from_nowhere = 23767001; //number of pages in a biggest book in the world, multiplied by 1000 and plus 1
  hash_table = calloc(our_constant_from_nowhere, sizeof(int));
}

int hash_for_idx(int page) {
  int idx;
  idx = (page * 101) % 23767001;
  return idx;
}


// This function checks, if an element was used before. Returns 1, if was, 0 - if else.
int check(int page, int* hash_table) {
  int idx = hash_for_idx(page);

  if (hash_table[idx] != 0)
    return 1;

  return 0;
}
//----------------------------------------------------\\

// This function puts zero to the element witch we want to delete
void nulify(int page, int* hash_table) {
  int idx = hash_for_idx(page);
  hash_table[idx] = 0;
}
//-----------------------------------------------------\\

//Checker for collisions - returns 1, if element was used before, 0 - if else.
int collision_check(int page, int* hash_table) {
  int idx = hash_for_idx(page);

  if (page != hash_table[idx])
    return 1;

  return 0;
}
//-----------------------------------------------------\\

int* hash_of_el (int page, int* hash_table) {
  int idx_val;
  int *pointer;

  idx_val = hash_for_idx(page);

  return pointer;
}
