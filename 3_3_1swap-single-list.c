/* 通过只调整指针（而不是数据）来交换两个相邻的元素，使用：
a.单链表 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node header; //declare struct header

void createsinglelist(struct node *header, struct node **ptr, int data)
{
    struct node *newnode = malloc(sizeof(struct node));
    //make the list link to header_Ler
    if (header->next == NULL)
        header->next = newnode;
    //link new node to previous list
    (*ptr)->next = newnode;
    (*ptr) = newnode;

    newnode->data = data;
    newnode->next = NULL;
}

void swap(struct node *L, int position)
{
    //allocat temp pointer to store some important nodes' address
    struct node *tempnode1 = malloc(sizeof(struct node));
    struct node *tempnode2 = malloc(sizeof(struct node));
    struct node *tempnode3 = malloc(sizeof(struct node));
    struct node *tempnode4 = malloc(sizeof(struct node));
    tempnode1->next = tempnode2->next = tempnode3->next = tempnode4->next = NULL;

    //get list length
    struct node *tempL = L;
    int nodenum = 0; //total nodes num of the list
    while (tempL != NULL)
    {
        tempL = tempL->next;
        nodenum++;
    }
    //check illegel input
    if (position >= nodenum)
    {
        fprintf(stderr, "Error,list is only %d in length.", nodenum);
        exit(EXIT_FAILURE);
    }

    //find previous node
    int currentnodeindex = 1; //current nodes index of the list
    while (L != NULL)
    {
        if (position == currentnodeindex + 1)
        {
            tempnode1 = L;
            tempnode2 = L->next;
            tempnode3 = L->next->next;
            tempnode4 = L->next->next->next;
        }
        L = L->next;
        currentnodeindex++;
    }
    //Modify the pointing relationship of the front and back pointers of the nodes to be exchanged.
    tempnode1->next = tempnode3;
    tempnode3->next = tempnode2;
    tempnode2->next = tempnode4;
}

void printlist(struct node *L)
{
    while (L != NULL)
    {
        printf("%d\t", L->data);
        L = L->next;
    }
}

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

    createsinglelist(header, &ptr, 1);
    createsinglelist(header, &ptr, 2);
    createsinglelist(header, &ptr, 3);
    createsinglelist(header, &ptr, 4);
    createsinglelist(header, &ptr, 5);

    int position;
    printf("Enter the node index(called position), so we will swap it with node whichs index is 'position + 1':");
    scanf("%d", &position);
    swap(header->next, position);

    printlist(header->next); //header->next is the beginning of the actually linked list, except the header

    return 0;
}