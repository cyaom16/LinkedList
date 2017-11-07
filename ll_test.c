#include <stdio.h>
#include "ll.h"

int main(void) {
   llnode *root = NULL;
   int r = 0;

//   r = ll_add_to_tail(&root, 100);
//   r = ll_add_to_tail(&root, 200);
//   r = ll_add_to_tail(&root, 300);
//   r = ll_print(root);
   
//   r = ll_find_by_value(root, 100);
//   
   r = ll_del_from_tail(&root);
   
//   r = ll_del_from_head(&root);

//   
//   r = ll_del_by_value(&root, 300);
   
//   r = ll_insert_in_order(&root, 50);
   
//   llnode *new_root = NULL;
//   r = ll_add_to_tail(&new_root, 10);
//   r = ll_add_to_tail(&new_root, 20);
//   r = ll_add_to_tail(&new_root, 30);
//   r = ll_print(new_root);
   
//   r = ll_concat(&root, &new_root);
//   r = ll_sort(&root);
   
   printf("Status: %d\n", r);
//   r = ll_print(root);
//   r = ll_free(root);
   
   return 0;
}
