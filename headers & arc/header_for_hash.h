//HASH

void create_hash_table(struct node** hash_table);
int hash_for_idx(int page);
struct node* check(struct node* page, struct node** hash_table);
void nulify(struct node* page, struct node** hash_table);
struct node* create_el (int page_val, struct node** hash_table);
