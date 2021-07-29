#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *createList() {
  // dummy 简化编程，方便返回 head
  struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
  dummy->val = -1;
  dummy->next = NULL;

  struct ListNode *tail = dummy;
  char ch;
  while ((ch = getchar()) != '\n') {

    if (ch == ' ')
      continue; // 跳过空格字符

    int num = ch - '0';
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = num;
    node->next = NULL;

    tail->next = node;
    tail = tail->next;
  }
  // todo: free()
  return dummy->next;
}

struct ListNode *removeNode(struct ListNode *head, int num) {
  // dummy 简化编程，方便删除 head
  struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
  dummy->val = -1;
  dummy->next = head;

  struct ListNode *node = dummy;

  while (node->next->val != num) {
    node = node->next;
  }

  struct ListNode *temp = node->next->next;
  node->next->next = NULL;
  free(node->next);
  node->next = temp;

  return dummy->next;
}

int main() {
  struct ListNode *head = createList();

  int num;
  scanf_s("%d", &num);
  struct ListNode *head2 = removeNode(head, num);

  while (head2 != NULL) {
    printf("%d ", head2->val);
    head2 = head2->next;
  }

  return 0;
}
/*
联发科7.28软件开发笔试
题目很简单，就是让删除一个链表的某个节点，就是用 C 处理输入麻烦，用 C++ 用惯了，一些 C 技巧忘记了

输入格式:
1 2 3 4 5 6    // 链表的节点
3              // 待删除的数据
输出：
1 2 4 5 6

*/