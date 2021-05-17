//HASH

struct node ** create_hash_table();
int hash_for_idx(int page);
struct node* check(int page, struct node** hash_table);
void nulify(struct node* page, struct node** hash_table);
struct node* create_el (int page_val, struct node** hash_table);
void free_hash(struct node** hash_table);
