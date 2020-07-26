/*给你一个链表L和另一个链表P，他们包含以升序排列的整数。操作PrintLots(L,P)将打印L中那些由P指定的位置上的元素。
例如，如果P=1，3，4，6，那么L中的第1，3，4，6个元素将被打印出来
写出程序PrintLots(L,P)。你应该只使用基本的表操作。该程序的运行时间是多少？
*/

//采用带头结点的链表，两个链表结构声明为全局变量
//时间复杂度是 O(m*n) m，n分别是L，P链表长度

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

//declare two global node for list L and P
struct node header_L;
struct node header_P;

void createlist(struct node *header, struct node **ptr, int data);
void printlist(struct node *L); //print list L and P
void PrintLots(struct node *L, struct node *P);

void createlist(struct node *header, struct node **ptr, int data)
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

void printlist(struct node *L)
{
    while (L != NULL)
    {
        printf("%5d", L->data);
        L = L->next;
    }
}

void PrintLots(struct node *L, struct node *P)
{
    int count = 1;
    while (P != NULL)
    {
        //move to positions
        while (P->data != count)
        {
            L = L->next;
            count++;
        }
        printf("%5d", L->data);
        P = P->next;
    }
}

int main(void)
{
    // initialize the header_L
    struct node *header_L = malloc(sizeof(struct node));
    if (!header_L)
    {
        perror("malloc node");
        exit(EXIT_FAILURE);
    };
    header_L->next = NULL;

    struct node *ptr_L = header_L; //ptr_L is used to move on the list L when create list

    // initialize the header_P
    struct node *header_P = malloc(sizeof(struct node));
    if (!header_P)
    {
        perror("malloc node");
        exit(EXIT_FAILURE);
    };
    header_P->next = NULL;

    struct node *ptr_P = header_P; //ptr_P is used to move on the list P when create list

    createlist(header_L, &ptr_L, 10);
    createlist(header_L, &ptr_L, 20);
    createlist(header_L, &ptr_L, 30);
    createlist(header_L, &ptr_L, 40);
    createlist(header_L, &ptr_L, 50);
    createlist(header_L, &ptr_L, 60);
    createlist(header_L, &ptr_L, 70);

    createlist(header_P, &ptr_P, 1);
    createlist(header_P, &ptr_P, 3);
    createlist(header_P, &ptr_P, 4);
    createlist(header_P, &ptr_P, 6);

    printf("Linked List L:");
    printlist(header_L->next);
    printf("\n");
    printf("Linked List P:");
    printlist(header_P->next);
    printf("\n");
    printf("Output       :");
    PrintLots(header_L->next, header_P->next);

    return 0;
}