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
    char name[1200];
    FILE *test;
    
    int i;
    
    srand(time(NULL));
    
    
    printf("input a name of file with .txt\n");
    int res = scanf("%s", name);
    assert(res == 1);
    
    test = fopen(name, "w");
    
    printf("input a size of cache\n");
    res = scanf("%d", &size_c);
    assert(res == 1);
    fprintf(test, "%d ", size_c);
    
    printf("input a quantity of requests\n");
    res = scanf("%d", &quan_req);
    assert(res == 1);
    fprintf(test, "%d\n", quan_req);
    
    printf("if you want random test, input 0 else input 1 and than requests\n");
    res = scanf("%d\n", &flag);
    assert(res == 1);
    
    if(flag != 0) {
        for(i = 0; i < quan_req; i++) {
            res = scanf("%d", &temp_page);
            assert(res == 1);
            fprintf(test, "%d ", temp_page);
        }
    }
    else {
        for(i = 0; i < quan_req; i++) {
                temp_page = (rand()/ 1000000) + 1;
                //printf("%d\n", temp_page);
                fprintf(test, "%d ", temp_page);
            }
    }
    fclose(test);
    return test;
}

int main() {
    int i = 1;
    FILE *temp;
    printf("let's create tests! if you want to exit, print 0\n");
    scanf("%d", &i);
    while (i ) {
        temp = create_test();
        if (temp != NULL)
            printf("OK\n");
        scanf("%d", &i);
    }
    return 0;
}
