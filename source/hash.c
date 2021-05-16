//stdin  -> page
//stdout -> adress of that page + in that adress should be val of that page + I should fill
//          the hash_table

/*
#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node* next;
  struct node* prev;
  int data;
  int idx_of_list;
};
*/

/*
int hash_main() {
  ...
  int c;
  struct node* hash_table;
  ...
  create_hash_table(hash_table); //here c comes up from the stdin, it's a size of a cache
  ...
}
*/

//DON'T FORGET TO WRITE A FUNC, THAT FREES ALL THE HASH
void create_hash_table(struct node** hash_table);
int hash_for_idx(int page);
struct node* check(struct node* page, struct node** hash_table);
void nulify(struct node* page, struct node** hash_table);
struct node* create_el (int page_val, struct node** hash_table);
void free_hash(struct node** hash_table);


void create_hash_table(struct node** hash_table) {
  int our_constant_from_nowhere = 23767001; //number of pages in a biggest book in the world, multiplied by 1000 and plus 1
  hash_table = (struct node**)calloc(our_constant_from_nowhere, sizeof(struct node*));
}


int hash_for_idx(int page) {
  int i, k, ans = page, ten_counter = 0;

  while((ans / 10) != 0){
    ++ten_counter;
    ans = ans / 10;
  }
  ans = 0;

  for(i = 0; i < ten_counter; ++i) {
    k = page / (10 ^ (ten_counter - i));
    ans += (k * (101 ^ (ten_counter - i))) % 23767001;
  }

  return ans;
}


// This function checks, if an element was used before. Returns pointer to the el, if was, NULL - if else.
struct node* check(struct node* page, struct node** hash_table) {
  int idx = hash_for_idx(page->data);

  if (hash_table[idx] != NULL)
    return hash_table[idx];

  return NULL;
}

// This function puts zero to the element witch we want to delete
void nulify(struct node* page, struct node** hash_table) {
  int idx = hash_for_idx(page->data);
  free(hash_table[idx]);
  hash_table[idx] = NULL;
}


struct node* create_el (int page_val, struct node** hash_table) {
  int idx = hash_for_idx(page_val);
  hash_table[idx] = (struct node*)malloc(sizeof(struct node));
  hash_table[idx]->prev = NULL;
  hash_table[idx]->next = NULL;

  return hash_table[idx];
}

//Function, that frees all the hash
void free_hash(struct node** hash_table) {
  int i, const_from_nowhere = 23767001;

  for(i = 0; i < const_from_nowhere; ++i) {
    free(hash_table[i]);
  }

  free(hash_table);
}

