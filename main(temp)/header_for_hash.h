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
#pragma once

void create_hash_table(int* hash_table);
int hash_for_idx(int page);
int check(int page, int* hash_table);
void nulify(int page, int* hash_table);
int collision_check(int page, int* hash_table);
int* hash_of_el (int page, int* hash_table);
