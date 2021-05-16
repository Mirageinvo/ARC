//HASH

//stdin  -> page
//stdout -> adress of that page + in that adress should be val of that page + I should fill
//          the hash_table

void create_hash_table(struct node** hash_table);
int hash_for_idx(int page);
struct node* check(struct node* page, struct node** hash_table);
void nulify(struct node* page, struct node** hash_table);
void create_el (int page_val, struct node** hash_table);
