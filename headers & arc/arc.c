//
//  main.c
//  arc_first
//
//  Created by Софья Сухова on 15.05.2021.
//

#include <stdio.h>
#include <assert.h>
#include "header_for_list.h"
#include "header_for_hash.h"
#include "header_for_ARC.h"


//special function used in ARC
static void REPLACE(long long p, struct node * T1,  struct node * T2, struct node * B1, struct node * B2, int idx) {
    int len = length_of(T1);
    if ((len >= 1) && ((idx == 3 && len == p) || (len > p))) { // idx == 3 means x in B2
        struct node * temp_adr = last_in_list(T1);
        T1 = delete_from_list(temp_adr);
        //delete pointer to this page
        B1 = add_to_list(temp_adr, B1);
    }
    else {
        struct node * temp_adr = last_in_list(T2);
        T2 = delete_from_list(temp_adr);
        //delete pointer to this page
        B2 = add_to_list(temp_adr, B2);
    }
};

//return address of last node in list
static struct node * last_in_list (struct node * node) {
    if (*(node -> next) == NULL)
        return node;
    node = *(node -> next);
};

void ARC () {
    
    //initialization
    
    long long size_c; //size of cashe
    long long quan_req; //quantity of requests
    long long p; //very important parameter of system)
    struct node * T1, T2, B1, B2; //pointers to top of LRU1, top of LRU2, bottom of LRU1, bottom of LRU2
    int temp_page;
    struct node * addr_of_page;
    int len_t1, len_t2, len_b1, len_b2, len_l1, len_l2;
    int idx = -1;
    
    T1 = NULL;
    T2 = NULL;
    B1 = NULL;
    B2 = NULL;
    p = 0;
    addr_of_page = NULL;
    
    
    
    //reading data

    int res = scanf("%d %d", &size_c, &quan_req);
    assert (res == 2);
    
    for (i = 0; i < quan_req; i++) {
        int res = scanf(" %d", &temp_page);
        assert(res == 1);
        
        addr_of_page = adr_of_page_hash (temp_page); // hash! 
        
        len_t1 = length_of(T1);
        len_b1 = length_of(B1);
        len_t2 = length_of(T2);
        len_b2 = length_of(B2);
        len_l1 = len_t1 + len_b1;
        len_l2 = len_t2 + len_b2;
        
        // miss in DBL and ARC
        
        if (addr_of_page == NULL) {
            if (len_l1  == size_c) {
                if (len_t1 < size_c) {
                    B1 = delete_from_list(last_in_list(B1));
                    //delete pointer to this page
                    REPLACE(p, T1, T2, B1, B2, idx);
                }
                else {
                    T1 = delete_from_list(last_in_list(T1));
                }
            };
            if (len_l1 < size_c && (len_l1 + len_l2) >= size_c) {
                if (len_l1 + len_l2 == 2 * size_c)
                    B2 = delete_from_list(last_in_list(B2));
                    //delete pointer to this page
                REPLACE(p, T1, T2, B1, B2, idx);
            };
            addr_of_page = create_hash(temp_page, sizeof(struct node)); // make void pointers??
            T1 = add_to_list(addr_of_page, T1);
            continue;
        };
        
        //hit in ARC and DBL
        
        assert(addr_of_page != NULL);
        idx = *(addr_of_page -> idx_of_list); //will it work? don't know, not sure. now must work
        
        if (idx == 0 || idx == 1) {
            if (idx == 0)
                T1 = delete_from_list(addr_of_page); //OK
            else
                T2 = delete_from_list(addr_of_page); //OK
            T2 = add_to_list(addr_of_page, T2);
            continue;
        };
        
        //hit in DBL miss in ARC
        
        if(idx == 2) { //hit in B1
            p = min(size_c, p + max(1, (len_b2 / len_b1)));
            REPLACE(p, T1, T2, B1, B2, idx);
            T2 = add_to_list(addr_of_page, T2);
            B1 = delete_from_list(addr_of_page);//OK
            continue;
        };
        if (idx == 3) { //hit in B2
            p = max(0, p - max((len_b1 / len_b2), 1));
            REPLACE(p, T1, T2, B1, B2, idx);
            T2 = add_to_list(addr_of_page, T2);
            B2 = delete_from_list(addr_of_page);//OK
            continue;
        };
        
    }
};


