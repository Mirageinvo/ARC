//
//  main.c
//  arc_first
//
//  Created by Софья Сухова on 15.05.2021.
//

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "../includes/header_for_list.h"
#include "../includes/header_for_hash.h"
#include "../includes/header_for_ARC.h"

//return address of last node in list
static struct node * last_in_list (struct node* node) {
    if ((node -> next) == NULL)
        return node;
    node = (node -> next);
    return last_in_list(node);
};

//create correct node
static void correct_node(struct node *adr, int data, int idx) {
    (adr -> data) = data;
    (adr -> idx_of_list) = idx;
};

static int max(int a, int b) {
    if (a > b)
        return a;
    return b;
};

static int min(int a, int b) {
    if (a < b)
        return a;
    return b;
};

//special function used in ARC
static void REPLACE(struct node** hash_table, long long p, struct node ** T1,  struct node ** T2, struct node ** B1, struct node ** B2, int idx) {
    int len = length_of( *T1);
    if ((len >= 1) && ((idx == 3 && len == p) || (len > p))) { // idx == 3 means x in B2
        struct node *temp_adr = last_in_list( *T1);
        *T1 = delete_from_list(temp_adr);
        *B1 = add_to_list(temp_adr, *B1);
        //printf("%p %p \n", *B1, temp_adr);
        correct_node(temp_adr, (temp_adr -> data), 2);
        //printf("%p %p \n", *B1, temp_adr);
        //printf("REPLACE 1\n");
    }
    else {
        struct node * temp_adr = last_in_list( *T2);
        *T2 = delete_from_list(temp_adr);
        *B2 = add_to_list(temp_adr, *B2);
        correct_node(temp_adr, (temp_adr -> data), 3);
        //printf("REPLACE 2\n");
    };
};

int ARC (struct node** hash_table) {
    
    //initialization
    
    int size_c = 0; //size of cashe
    int quan_req = 0; //quantity of requests
    int p ; //very important parameter of system)
    struct node *T1, *T2, *B1, *B2, *temp; //pointers to top of LRU1, top of LRU2, bottom of LRU1, bottom of LRU2
    int temp_page;
    struct node * addr_of_page;
    int len_t1, len_t2, len_b1, len_b2, len_l1, len_l2;
    int idx = -1;
    int number_of_hits;
    int res = 2;
    int i;
    
    T1 = NULL;
    T2 = NULL;
    B1 = NULL;
    B2 = NULL;
    p = 0;
    number_of_hits = 0;
    addr_of_page = NULL;
    temp = NULL;
    
    //reading data

    res = scanf("%d %d", &size_c, &quan_req);

    if(size_c < 0 || quan_req < 0){
        printf("Error! Invalid value of parameters!");
        return number_of_hits;
    }
    
    for (i = 0; i < quan_req; i++) {
        
        len_t1 = length_of(T1);
        len_b1 = length_of(B1);
        len_t2 = length_of(T2);
        len_b2 = length_of(B2);
        len_l1 = len_t1 + len_b1;
        len_l2 = len_t2 + len_b2;

        res = scanf(" %d", &temp_page);
        assert(res == 1);
        
        if(temp_page < 0){
            printf("Error! Invalid value of parameter!");
            break;
        }
        
        addr_of_page = check(temp_page, hash_table); // hash!
        
        // miss in DBL and ARC
        
        if (addr_of_page == NULL) {
            if (len_l1  == size_c) {
                if (len_t1 < size_c) {
                    temp = last_in_list(B1);
                    B1 = delete_from_list(temp);
                    nulify(temp, hash_table);
                    REPLACE(hash_table, p, &T1, &T2, &B1, &B2, idx);
                }
                else {
                    temp = last_in_list(T1);
                    T1 = delete_from_list(temp);
                    B1 = add_to_list(temp, B1);
                    correct_node(temp, temp -> data, 2);
                }
            };
            if (len_l1 < size_c && (len_l1 + len_l2) >= size_c) {
                if (len_l1 + len_l2 == 2 * size_c) {
                    temp = last_in_list(B2);
                    B2 = delete_from_list(temp);
                    nulify(temp, hash_table);
                }
                REPLACE(hash_table, p, &T1, &T2, &B1, &B2, idx);
            };
            addr_of_page = create_el(temp_page, hash_table);
            T1 = add_to_list(addr_of_page, T1);
            correct_node(addr_of_page, temp_page, 0);
            continue;
        };
        
        //hit in ARC and DBL
        
        assert(addr_of_page != NULL);
        idx = (addr_of_page -> idx_of_list);
        if (idx == 0 || idx == 1) {
            number_of_hits += 1;
            if (idx == 0)
                T1 = delete_from_list(addr_of_page); //OK
            else
                T2 = delete_from_list(addr_of_page); //OK
            T2 = add_to_list(addr_of_page, T2);
            correct_node(addr_of_page, temp_page, 1);
            continue;
        };
        
        //hit in DBL miss in ARC
        
        if(idx == 2) { //hit in B1
            p = min(size_c, p + max(1, (len_b2 / len_b1)));
            REPLACE(hash_table, p, &T1, &T2, &B1, &B2, idx);
            B1 = delete_from_list(addr_of_page);
            T2 = add_to_list(addr_of_page, T2);
            correct_node(addr_of_page, temp_page, 1);
            continue;
        };
        if (idx == 3) { //hit in B2
            p = max(0, p - max((len_b1 / len_b2), 1));
            REPLACE(hash_table, p, &T1, &T2, &B1, &B2, idx);
            B2 = delete_from_list(addr_of_page);//OK
            T2 = add_to_list(addr_of_page, T2);
            correct_node(addr_of_page, temp_page, 1);
            continue;
        };

    };
    return number_of_hits;
};

