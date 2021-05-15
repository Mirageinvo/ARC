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
static void REPLACE(long long p, int * T1,  int * T2, int *B1, int * B2, int idx) {
    int len = length_of(T1);
    if ((len >= 1) && ((idx == 3 && len == p) || (len > p))) { // idx == 3 means x in B2
        int * temp_adr = last_in_list(T1);
        delete_from_list(temp_adr);
        add_to_list(temp_adr, B1);
    }
    else {
        int * temp_adr = last_in_list(T2);
        delete_from_list(temp_adr);
        add_to_list(temp_adr, B2);
    }
};

//return address of last node in list
static int * last_in_list (int * node) {
    if (*(node -> next) == NULL)
        return node;
    node = *(node -> next);
};

void ARC () {
    
    //initialization
    
    long long size_c; //size of cashe
    long long quan_req; //quantity of requests
    long long p; //very important parameter of system)
    int * T1, T2, B1, B2; //pointers to top of LRU1, top of LRU2, bottom of LRU1, bottom of LRU2
    int temp_page;
    int * addr_of_page;
    int len_t1, len_t2, len_b1, len_b2, len_l1, len_l2;
    int idx = -1;
    
    //reading data

    int res = scanf("%d %d", &size_c, &quan_req);
    assert (res == 2);
    
    for (i = 0; i < quan_req; i++) {
        int res = scanf(" %d", &temp_page);
        assert(res == 1);
        
        addr_of_page = adr_of_page_hash (temp_page);
        
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
                    delete_from_list(B1);
                    REPLACE(p, T1, T2, B1, B2, idx);
                }
                else {
                    delete_from_list(last_in_list(T1));
                }
            };
            if (len_l1 < size_c && (len_l1 + len_l2) >= size_c) {
                if (len_l1 + len_l2 == 2 * size_c)
                    delete_from_list(last_in_list(B2));
                REPLACE(p, T1, T2, B1, B2, idx);
            };
            addr_of_page = create_hash(temp_page, sizeof(struct node)); // LOOK AT THIS! предлагаю сделать create_hash с такими входными параметрами, чтобы можно было делать маллок на определенный размер (потому что по идее хэш не знает про списки)
            add_to_list(addr_of_page, T1); // LOOK AT THIS! также предлагаю сделать вот такое добавление в список: адрес добавляемого элемента, затем в какой список добавляем. кстати, мне вручную здесь перевязать указатель на начало списка, или эта функция может вернуть новое значение указателя на голову списка. это не необходимо, но мне кажется, красиво.
            continue;
        };
        
        //hit in ARC and DBL
        
        assert(addr_of_page != NULL);
        idx = *(addr_of_page -> idx_of_list); //will it work? don't know, not sure
        
        if (idx == 0 || idx == 1) {
            add_to_list(addr_of_page, T2);
            delete_from_list(addr_of_page); //OK
            continue;
        };
        
        //hit in DBL miss in ARC
        
        if(idx == 2) { //hit in B1
            p = min(size_c, p + max(1, (len_b2 / len_b1)));
            REPLACE(p, T1, T2, B1, B2, idx);
            add_to_list(addr_of_page, T2);
            delete_from_list(addr_of_page);//OK
            continue;
        };
        if (idx == 3) { //hit in B2
            p = max(0, p - max((len_b1 / len_b2), 1));
            REPLACE(p, T1, T2, B1, B2, idx);
            add_to_list(addr_of_page, T2);
            delete_from_list(addr_of_page);//OK
            continue;
        };
        
    }
};


