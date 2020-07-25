/*编写一个打印单链表的所有元素的程序*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node *ptrtonode; //define a argument point to the "node" struct
typedef ptrtonode List;         //give the pointer a alias

struct node head;


void createlist(struct node **head, int data);
void printlist(struct node *L);

int main(void)
{
    struct node *head = malloc(sizeof(struct node));
    if (!head)
    {
        perror("malloc node");
        exit(EXIT_FAILURE);
    };
    head->next = NULL;
    // initialize other fields of head

    createlist(&head, 1);
    createlist(&head, 1);

    printlist(head->next);

    return 0;
}

void createlist(struct node **head, int data)
{
    List newnode = malloc(sizeof(struct node));

    if ((*head)->next == NULL)
        (*head)->next = newnode;

    newnode->data = data;
    newnode->next = NULL;
}
void printlist(struct node *L)
{
    while (L->next != NULL)
    {
        printf("%5d", L->data);
        L = L->next;
    }
}