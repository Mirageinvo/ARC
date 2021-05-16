s#include "header_for_list.h"

struct node* add_to_list(struct node* to_add, struct node* list) {
	if (list != NULL) {                           //если сам list создан
		to_add->next = list;
		list->prev = to_add;
	}
	return to_add;                         //если list не создан, то достаточно просто вернуть to_add
}                                          //(элемент, который мы хотели добавить)


int length_of(struct node* list) {
	int ans = 1;
	if (list == NULL) {
		return 0;
	}
	while (list->next != NULL) {
		list = list->next;
		ans++;
	}
	return ans;
}


struct node* delete_from_list(struct node* temp_adr) {
	struct node* ret = temp_adr;

	if (temp_adr->next != NULL && temp_adr->prev != NULL) {
		while (ret->prev != NULL)
			ret = ret->prev;
		temp_adr->prev->next = temp_adr->next;
		temp_adr->next->prev = temp_adr->prev;
		temp_adr->prev = NULL;
		temp_adr->next = NULL;
	}

	else if (temp_adr->prev != NULL) {
		while (ret->prev != NULL)
			ret = ret->prev;
		temp_adr->prev->next = NULL;
		temp_adr->prev = NULL;
	}
	
	else if (temp_adr->next != NULL) {
		ret = temp_adr->next;
		temp_adr->next->prev = NULL;
		temp_adr->next = NULL;
	}
	else {            //если удаляем единственный элемент в списке
		return NULL;
	}
	return ret;
}






