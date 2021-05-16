#include <stdio.h>
#include <stdlib.h>
#include "header_for_list.h"
#include "header_for_hash.h"
#include "header_for_ARC.h"

int main () {
    int number_of_hits;
    struct node ** hash_table;
    number_of_hits = 0;
    create_hash_table(hash_table);
    number_of_hits = ARC(hash_table);
    
    printf("number of hits to hash: %d\n", number_of_hits);
    return 0;
}
