struct llnode
{
    /* since the llnode is a self-referential structure */
    /* we can not compile the struct and typedef decl into one */
    int val;                
    struct llnode *next;
};
typedef struct llnode llnode;

int ll_add_to_head(llnode **head, int val);
int ll_add_to_tail(llnode **head, int val);
int ll_print(llnode *p);
int ll_free(llnode *p);

int ll_find_by_value(llnode *p_list, int val);
int ll_del_from_tail(llnode **pp_list);
int ll_del_from_head(llnode **pp_list);
int ll_del_by_value(llnode **pp_list,int val);
int ll_insert_in_order(llnode **pp_list,int val);
int ll_concat(llnode **p_src_a,llnode **p_src_b);
int ll_sort(llnode **pp_list);
