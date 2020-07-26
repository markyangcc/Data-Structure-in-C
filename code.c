/*编写一个打印单链表的所有元素的程序*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node header; //declare a global node called header

void createlist(struct node *header, struct node **ptr, int data);
void printlist(struct node *L);

int main(void)
{
    // initialize the header
    struct node *header = malloc(sizeof(struct node));
    if (!header)
    {
        perror("malloc node");
        exit(EXIT_FAILURE);
    };
    header->next = NULL;

    struct node *ptr = header; //ptr is used to move on the list

    createlist(header, &ptr, 1);
    createlist(header, &ptr, 2);

    printlist(header->next); //header->next is the beginning of the actually linked list, except the header

    return 0;
}

void createlist(struct node *header, struct node **ptr, int data)
{
    struct node *newnode = malloc(sizeof(struct node));
    //make the list link to headerer
    if (header->next == NULL)
        header->next = newnode;
    //link new node to previous list
    (*ptr)->next = newnode;
    (*ptr) = newnode;

    newnode->data = data;
    newnode->next = NULL;
}

void printlist(struct node *L)
{
    while (L != NULL)
    {
        printf("%d\t", L->data);
        L = L->next;
    }
}
