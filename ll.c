#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

/* One of the lessons here is to see that if we want to use a function to malloc something that
 * is a POINTER in the CALLER of the function, then we must send in the ADDRESS of the POINTER
 * to that function.
 * 
 * Recap: if we want to use a function to modify a VARIABLE in the caller
 *        then the CALLER needs to send in the ADDRESS of the VARIABLE
 *
 * Similarly: if we want to use a function to modify a POINTER in the caller
 *            then the CALLER needs to send in the ADDRESS of the POINTER
 *
 * In the code below, ll_add_to_head and ll_add_to_tail are dynamically creating new
 * nodes to be added to the linked list. Any dynamic creation of a node must be via
 * malloc.
 */

int ll_add_to_head(llnode **head, int val)
{
    if (head == NULL)
        return -1;
    
    llnode *old_head;
    old_head = *head;
    
    *head = (llnode *)malloc(sizeof(llnode));
    (*head)->val = val;
    (*head)->next = old_head;
    
    return 0;
}

int ll_add_to_tail(llnode **head, int val)
{
    if (head == NULL)
        return -1;
    
    if (*head == NULL)
    {
        *head = (llnode *)malloc(sizeof(llnode));
        (*head)->val = val;
        (*head)->next = NULL;
        
        return 0;
    }
    else
    {
        /* recursively call ll_add_to_tail until we get to the tail
         * which is the point where the pointer is NULL */
        return ll_add_to_tail(&((*head)->next), val);
    }
}

int ll_print(llnode *p)
{
    if (p == NULL)
      return 0;
    else
    {
        printf("val = %d\n",p->val);
        return ll_print(p->next);
    }
}

int ll_free(llnode *p)
{
    if (p == NULL)
        return -1;
   else
   {
        llnode *f = p->next;
        free(p);
        return ll_free(f);
   }
}

int ll_find_by_value(llnode *p_list, int val)
{
    if (p_list == NULL)
        return -1;
    
    llnode *cursor = p_list;
    while (cursor != NULL)
    {
        if (cursor->val == val)
        {
            printf("Found it!\n");
            return 0;
        }
        cursor = cursor->next;
    }
    return -1;

}

int ll_del_from_tail(llnode **pp_list)
{
    if (pp_list == NULL || *pp_list == NULL)
        return -1;
    
    llnode *cursor = *pp_list;
    
    if (cursor->next == NULL)
    {
        printf("Only 1 element in the list\n");
        *pp_list = NULL;
        return 0;
    }
    
    if (cursor->next->next == NULL)
    {
        cursor->next = NULL;
        free(cursor->next);
        return 0;
    }
    else
        // Recursively finding the next
        return ll_del_from_tail(&(cursor->next));
}

int ll_del_from_head(llnode **pp_list)
{
    if (pp_list == NULL || *pp_list == NULL )
        return -1;
    
    llnode *front = *pp_list;

    *pp_list = (*pp_list)->next;
    front->next = NULL;
    
    free(front);
    return 0;

}

int ll_del_by_value(llnode **pp_list, int val)
{
    if (pp_list == NULL || *pp_list == NULL)
        return -1;
    
    llnode *cursor = *pp_list;
    if (cursor->val == val)
    {
        printf("Found it at the front!\n");
        return ll_del_from_head(pp_list);
    }
    
    if (cursor->next == NULL)
        return -1;
    else if (cursor->next->val == val)
    {
        cursor->next = cursor->next->next;
        cursor->next = NULL;
        free(cursor->next);
        return 0;
    }
    else
        return ll_del_by_value(&(cursor->next), val);
}

int ll_insert_in_order(llnode **pp_list, int val)
{
    if (pp_list == NULL)
        return -1;
    
    llnode *cursor = *pp_list;

    if (cursor->next == NULL)
        return -1;
    else if (cursor->val <= val && cursor->next->val >= val)
    {
        llnode *insert = NULL;
        insert = (llnode *)malloc(sizeof(llnode));
        insert->val = val;
        insert->next = cursor->next;
        cursor->next = insert;
        return 0;
    }
    else
        return ll_insert_in_order(&(cursor->next), val);

}

int ll_concat(llnode **p_src_a, llnode **p_src_b)
{
    if (p_src_a == NULL)
        p_src_a = p_src_b;
    else if (p_src_b == NULL)
        return 0;
    else if (p_src_a == NULL && p_src_b == NULL)
        return -1;

    llnode *cursor = *p_src_b;
    int r;
        
    while (cursor != NULL)
    {
        r = ll_add_to_tail(p_src_a, cursor->val);
        cursor = cursor->next;
    }
    return 0;
}

int ll_sort(llnode **pp_list)
{
    if (pp_list == NULL)
        return -1;
    
    llnode *head = *pp_list;
    llnode *cursor = head;
    int tmp, swapped = 1;
    
    while (swapped)
    {
        swapped = 0;
        while (cursor->next != NULL)
        {
            if (cursor->val > cursor->next->val)
            {
                tmp = cursor->val;
                cursor->val = cursor->next->val;
                cursor->next->val = tmp;
                swapped = 1;
            }
            cursor = cursor->next;
        }
        // Reset cursor back to the front
        cursor = head;
    }
    return 0;
}