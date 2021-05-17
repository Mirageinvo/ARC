#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "../../includes/header_for_list.h"
#include "../../includes/list_test_header.h"

int test_for_length_of() {
    int ans, tmp;
    struct node* st;
    struct node* f;
    srand(time(NULL));
    for (int i = 0; i < 100; ++i) {
        ans = rand() % 200;
        st = (struct node*)malloc(sizeof(struct node));
		f = st;
        st->data = 0;
        st->prev = NULL;
        for (int j = 0; j < ans - 1; ++j) {
            st->next = (struct node*)malloc(sizeof(struct node));
            st->next->prev = st;
            st = st->next;
            st->data = j + 1;
        }
        st->next = NULL;
		if (ans == 0)
			tmp=length_of(NULL);
		else {
        	tmp = length_of(f);
		}
        f = st->prev;
        while (f != NULL) {
            free(st);
            st = f;
            f = f->prev;
        }
        free(st);
        printf("%d ---> %d\n", tmp, ans);
        if (tmp != ans)
            return 0;
    }
	printf("\nAll tests for length_of have been passed\n");
    return 1;
}

int test_for_add_to_list(){
	struct node* ans;
	struct node* list = (struct node*)malloc(sizeof(struct node));
	struct node* to_add = (struct node*)malloc(sizeof(struct node));
	list->prev = NULL;
	list->next = NULL;
	to_add->data = 0;
	list->data = 1;
	ans = add_to_list(to_add, list);
	if (ans->data == 0 && ans->next->data == 1) {
		free(ans->next);
		free(ans);
		printf("\nAll tests for add_to_list have been passed\n");
		return 1;
	}
	return 0;
}

void test_for_list() {
    int ans = 0;

    ans = test_for_length_of();
    assert(ans == 1);
    ans = 0;

    ans = test_for_add_to_list();
    assert(ans == 1);
}
