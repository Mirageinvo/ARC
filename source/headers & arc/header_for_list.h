//LIST (not a paper)

struct node {
  int* next;
  int* prev;
  int data;
  int idx_of_list;
};

// idx_of_list T1 = 0; T2 = 1; B1 = 2; B2 = 3;

struct node* add_to_list(struct node* to_add, struct node* list);
struct node* delete_from_list(struct node* temp_adr);
int length_of(struct node* list);
