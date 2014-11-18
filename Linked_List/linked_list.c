#include "linked_list.h"
#include <stdlib.h>

/* NOTE:  This implementation contains some errors.  Double check your work. */

/******************************************
 return empty list
 */
list create_list()
{
    list l;
    l.front = NULL;
    l.rear = NULL;
    l.size = 0;
    return l;
}

/*******************************************
 return whether list is empty
 */
int is_empty (list l)
{
    return l.front == NULL;
}

/*****************************************
 return # of elements in list
 */
int size (list l)
{
    return l.size;
}

/*******************************************
 postcondition: list & all nodes in list have
 been deleted - if l is NULL, nothing is
 done
 */
void delete (list* l)
{
    if (l != NULL)
    {
        node* temp = l -> front;
        while (temp != NULL)
        {
            node* temp1 = temp -> next;
            free (temp);
            temp = temp1;
        }
        free (l);
    }
}

/********************************************
 precondition: l is not NULL
 postcondition: item has been inserted at the
 beginning of l
 return whether insertion was performed
 */
int prepend (list* l, void* item)
{
    int result = 0;
    if (l != NULL)
    {
        node* temp = malloc (sizeof (node));
        if (temp != NULL)
        {
            result = 1;
            temp -> item = item;
            if (l -> front == NULL)
            {
                temp -> next = NULL;
                temp -> prev = NULL;
                l -> front = temp;
                l -> rear = temp;
            }
            else
            {
                temp -> next = l -> front;
                temp -> prev = l -> rear;
                l -> rear -> next = temp;
                l -> front -> prev = temp;
                l -> front = temp;
            }
            l -> size++;
        }
    }
    return result;
}

/********************************************
 precondition: l is not NULL
 postcondition: item has been inserted at the
 end of l
 return whether insertion was performed
 */
int append (list* l, void* item)
{
    int result = 0;
    if (l != NULL)
    {
        node* temp = malloc (sizeof (node));
        if (temp != NULL)
        {
            result = 1;
            temp -> item = item;
            temp -> next = NULL;
            if (l -> front == NULL)
            {
                l -> front = temp;
                l -> rear = temp;
            }
            else
            {
                l -> rear -> next = temp;
                l -> front ->prev = temp;
                temp -> next = l -> front;
                temp -> prev = l -> rear;
                l -> rear = temp;
            }
            l -> size++;
        }
    }
    return result;
}

/********************************************
 precondition: l is not NULL & 1 <= location <= size of list + 1
 postcondition: item has been inserted at location position
 end of l
 return whether insertion was performed
 */
int insert_in_list (list* l, int location, void* item)
{
    int result;
    if (l == NULL)
        result = 0;
    else if (location < 1 || location > size(*l) + 1)
        result = 0;
    else if (l -> size == 0)
    {
        l -> front = malloc (sizeof(node));
        if (l -> front == NULL)
            result = 0;
        else
        {
            result = 1;
            l -> front -> item = item;
            l -> rear = l -> front;
            l -> front -> next = NULL;
            l -> front -> prev = NULL;
            l -> size++;
        }
    }
    else
    {
        node* new_node = malloc (sizeof(node));
        if (new_node == NULL)
            result = 0;
        else
        {
            result = 1;
            new_node -> item = item;
            int i;
            node* temp = l -> front;
            for (i = 1; i < location - 1; i++)
                temp = temp -> next;
            new_node -> next = temp -> next;
            new_node -> prev = temp;
            temp -> next -> prev = new_node;
            temp -> next = new_node;
            if (location == l -> size + 1)
            {
                l -> rear = new_node;
                l -> front -> prev = l -> rear;
            }
            l -> size++;
        }
    }
    return result;
}

/********************************************
 precondition: l is not NULL & 1 <= location <= size of list
 postcondition: item has been deleted from l
 return whether deletion was performed
 */
int delete_from_list (list* l, int location)
{
    int result;
    if (l == NULL)
        result = 0;
    else if (location < 1 || location > size (*l))
        result = 0;
    else if (location == 1)
    {
        node* temp = l -> front;
        l -> front = l -> front -> next;
        if (size (*l) == 1)
            l -> rear = NULL;
        free (temp);
        l -> size--;
        result = 1;
    }
    else
    {
        node* temp = l -> front;
        int i;
        for (i = 1; i < location - 1; i++)
            temp = temp -> next;
        node* temp1 = temp -> next;
        temp -> next = temp1 -> next;
        temp1 -> next -> prev = temp;
        free (temp1);
        if (location == l -> size)
            l -> rear = temp;
        l -> size--;
        result = 1;
    }
    return result;
}


/********************************************
 precondition: l is not NULL & 1 <= location <= size of list
 return element at position location in l - NULL is returned
 if l is NULL or location is not valid
 */
void* get (list l, int location)
{
    void* item = NULL;
    if (1 <= location && location <= size(l))
    {
        node* temp = l.front;
        int i;
        for (i = 1; i < location; i++)
            temp = temp -> next;
        item = temp -> item;
    }
    return item;
}

/********************************************
 precondition: l is not NULL & 1 <= location <= size of list
 return element at position location in l - NULL is returned
 if l is NULL or location is not valid
 */
void* get_reverse (list l, int location)
{
    void* item = NULL;
    if (1 <= location && location <= size(l))
    {
        node* temp = l.rear;
        int i;
        for (i = size(l); i > location; i--)
            temp = temp -> prev;
        item = temp -> item;
    }
    return item;
}

/********************************************
 precondition: l is not NULL & 1 <= location <= size of list
 return whether item was put in l
 */
int set (list l, int location, void* item)
{
    int result = 0;
    if (1 <= location && location <= size(l))
    {
        node* temp = l.front;
        int i;
        for (i = 1; i < location; i++)
        temp = temp -> next;
        temp -> item = item;
        result = 1;
    }
    return result;
}
