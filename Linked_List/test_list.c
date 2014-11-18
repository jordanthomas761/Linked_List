#include "linked_list.h"
#include <stdio.h>

void display_list (list l);
void display_list_reverse (list l);

/* NOTE:  This example has errors.  Please double check your work */

int main ()
{
    list l = create_list();
    prepend (&l, (void*)2);
    append (&l, (void*)17);
    insert_in_list (&l, 3, (void*)1);
    insert_in_list (&l, 2, (void*)14);
    display_list(l);
    printf ("\n");
    display_list_reverse(l);
    printf ("\n");
    delete_from_list (&l,2);
    display_list(l);
    printf ("\n");
    display_list_reverse(l);
    printf ("\n");
    set (l, 3, (void*)5);
    display_list(l);
    printf ("\n");
    display_list_reverse(l);
    return 0;
}

void display_list (list l)
{
    int i;
    for (i = 1; i <= size(l); i++)
        printf ("%d\n", (int)get(l, i));
}

void display_list_reverse (list l)
{
    int i;
    for (i = size(l); i >= 1; i--)
    {
        printf ("%d\n", (int)get_reverse(l, i));
    }
}