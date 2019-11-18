/*
    File: ws3.c

    Abstract:

        Small program that creates a hard coded linked list

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE_T
{
    char* name;
    struct NODE_T* next;
} NODE;


void PrintList(NODE* n);

int
main() 
{
    NODE a = {"door", NULL};
    NODE b = {"window", NULL};
    NODE c = {"floor", NULL};
    NODE d = {"key", NULL};


    // Link the nodes
    a.next = &b;
    b.next = &c;

    // Print the list
    PrintList(&a);

    // Print the list starting from b
    PrintList(&b);

    // Add node d between a and b
    a.next = &d;
    d.next = &b;

    // Print the list starting from b
    PrintList(&a);

    return 0;
}


void
PrintList(NODE* n)
{
    printf("List: ");
    while (n != NULL) 
    {        
        printf("%s ", n->name);
        n = n->next;
    }
    printf("\n");
}


