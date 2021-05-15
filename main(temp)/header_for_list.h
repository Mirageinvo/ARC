//LIST (not a paper)

struct node {
  int* next;
  int* prev;
  int data;
  int idx_of_list;
};

// idx_of_list T1 = 0; T2 = 1; B1 = 2; B2 = 3;

struct node* add_to_list(struct node* to_add, struct node* list);
delete_from_list(int data, int* adress);
length_of(int *adress);
remove_from_cache(int *adress);
