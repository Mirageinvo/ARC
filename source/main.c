#include <stdio.h>
#include <stdlib.h>
#include "header_for_list.h"
#include "header_for_hash.h"
#include "header_for_ARC.h"

int main () {
    int number_of_hits;
    struct node ** hash_table;
    number_of_hits = 0;
    hash_table = create_hash_table(hash_table);
    number_of_hits = ARC(hash_table);
    
    printf("number of hits to hash: %d\n", number_of_hits);
    free_hash(hash_table);
    return 0;
}
