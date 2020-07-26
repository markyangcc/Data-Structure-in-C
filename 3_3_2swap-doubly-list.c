/* 通过只调整指针（而不是数据）来交换两个相邻的元素，使用：
b.双链表 */

//使用双链表时其实没必要知道要交换结点的前序结点，因为有指针指向它
//但是为了将单链表双链表统一，在赋值tempnode的判断条件处没有更改了
//null pointer 如果被看作一个临时结点，注意它没有prev指针域

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node header;

void createdoublylist(struct node *header, struct node **ptr, int data)
{
    struct node *newnode = malloc(sizeof(struct node));
    //make the list link to headerer
    if (header->next == NULL)
        header->next = newnode;

    (*ptr)->next = newnode;
    newnode->prev = (*ptr);
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
    tempnode1->prev = tempnode2->prev = tempnode3->prev = tempnode4->prev = NULL;

    //get list length
    struct node *tempL = L;
    int nodenum = 0; //total nodes num of the list
    while (tempL->next != NULL)
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
    int currentnodeindex = 0; //current nodes index of the list
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
    tempnode3->prev = tempnode1;
    tempnode3->next = tempnode2;
    tempnode2->prev = tempnode3;
    tempnode2->next = tempnode4;
    //id tempnode4 is the null pointer, it can't pointer to other node, only other nodes can point to null pointer
    if (tempnode4 != NULL)
        tempnode4->prev = tempnode2;
}

void printlistfrbegin(struct node *L)
{
    while (L != NULL)
    {
        printf("%d\t", L->data);
        L = L->next;
    }
}
//To prove that double-linked lists can also be printed in reverse order
void printlistfrend(struct node *L, struct node *header)
{
    while (L->next != NULL)
        L = L->next;
    while (L != header)
    {
        printf("%d\t", L->data);
        L = L->prev;
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

    createdoublylist(header, &ptr, 1);
    createdoublylist(header, &ptr, 2);
    createdoublylist(header, &ptr, 3);
    createdoublylist(header, &ptr, 4);

    int position;
    printf("Enter the node index(called position), so we will swap it with node whichs index is 'position + 1':");
    scanf("%d", &position);
    swap(header, position);
    printf("print from begin: ");
    printlistfrbegin(header->next);
    printf("\n");
    printf("print from end  : ");
    printlistfrend(header->next, header);

    return 0;
}