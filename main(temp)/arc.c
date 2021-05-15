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

static void REPLACE(long long p) {
    
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
                    REPLACE(p);
                }
                else {
                    delete_from_list(T1);
                }
            };
            if (len_l1 < size_c && (len_l1 + len_l2) >= size_c) {
                if (len_l1 + len_l2 == 2 * size_c)
                    delete_from_list(B2);
                REPLACE(p);
            };
            addr_of_page = create_hash(temp_page, sizeof(struct node)); // LOOK AT THIS! предлагаю сделать create_hash с такими входными параметрами, чтобы можно было делать маллок на определенный размер (потому что по идее хэш не знает про списки)
            add_to_list(addr_of_page, T1); // LOOK AT THIS! также предлагаю сделать вот такое добавление в список: адрес добавляемого элемента, затем в какой список добавляем. кстати, мне вручную здесь перевязать указатель на начало списка, или эта функция может вернуть новое значение указателя на голову списка. это не необходимо, но мне кажется, красиво.
        };
        
        //hit in ARC and DBL
        
        if (addr_of_page < B1 &&  addr_of_page >= T1)
        
        //hit in DBL miss in ARC
        
        
    }
    
};


