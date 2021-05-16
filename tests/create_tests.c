//this program create tests using stdin or random

#include <time.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


FILE *create_test() {
    int size_c;
    int quan_req;
    int flag;
    int temp_page;
    char *name;
    FILE *test;
    
    printf("input a name of file with .txt\n");
    int res = scanf("%s\n", &name);
    assert(res == 1);
    printf("input a size of cache\n");
    int res = scanf("%d\n", &size_c);
    assert(res == 1);
    printf("input a quantity of requests\n");
    int res = scanf("%d\n", &quan_req);
    assert(res == 1);
    printf("if you want to random test, input 0 else input 1 and than requests\n");
    int res = scanf("%d\n", &flag);
    assert(res == 1);
    
    test = fopen(name, "wr");
    
    
    if (flag) {
        
    }
}
