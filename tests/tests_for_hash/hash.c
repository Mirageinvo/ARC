//stdin  -> page
//stdout -> adress of that page + in that adress should be val of that page + I should fill
//          the hash_table


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "../includes/header_for_list.h"
#include "../includes/header_for_hash.h"



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


int super_power(int p, int num, int mod) {
    if (p == 0) {
        return 1;
    }
    if (p == 1) {
        return num % mod;
    }
    if (p % 2 == 1) {
        return (super_power(p - 1, num, mod) * num) % mod;
    }
    else {
        int tmp = super_power(p / 2, num, mod) % mod;
        return (tmp * tmp) % mod;
    }
}


struct node** create_hash_table() {
    struct node** hash_table;
    int our_constant_from_nowhere = 23767001; //number of pages in a biggest book in the world, multiplied by 1000 and plus 1
    hash_table = (struct node**)calloc(our_constant_from_nowhere, sizeof(struct node*));
    return hash_table;
}


int hash_for_idx(int page) {
    int counter = 0, k = page, tmp = page;
    while (tmp != 0) {
        tmp /= 10;
        counter++;
    }
    assert(tmp == 0);
    for (int i = 0; i < counter; ++i) {
        tmp += ((k % 10) * (super_power(i, 101, 23767001))) % 23767001;
        k /= 10;
        tmp %= 23767001;
    }
    return tmp;
}


// This function checks, if an element was used before. Returns pointer to the el, if was, NULL - if else.
struct node* check(int page, struct node** hash_table) {
    int idx = hash_for_idx(page);

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


struct node* create_el(int page_val, struct node** hash_table) {
    int idx = hash_for_idx(page_val);
    hash_table[idx] = (struct node*)malloc(sizeof(struct node));
    hash_table[idx]->prev = NULL;
    hash_table[idx]->next = NULL;

    return hash_table[idx];
}

//Function, that frees all the hash
void free_hash(struct node** hash_table) {
    int i, const_from_nowhere = 23767001;

    for (i = 0; i < const_from_nowhere; ++i) {
        free(hash_table[i]);
    }

    free(hash_table);
}