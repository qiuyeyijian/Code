#include <stdio.h>

// https://www.cnblogs.com/valarchie/p/12817351.html

typedef struct Node {
  int data;
  struct Node* next;
} Node, *LinkList;

int solve(LinkList list, int k) {
  Node *p = list->next, *q = list->next;

  // p首先沿着链表走k步
  for (int i = 0; i < k; ++i) {
    if (p == NULL) {
      return 0;
    }
    p = p->next;
  }

  // 然后p和q同步移动
  while (p != NULL) {
    p = p->next;
    q = q->next;
  }
  printf("%d", q->data);

  return 1;
}

// int main() {
//   LinkList list = initLinkList();

//   for (int i = 1; i <= 10; ++i) {
//     insertElem(list, i, i);
//   }
//   show(list);
//   printf("\nstatus: %d\n", solve(list, 10));

//   return 0;
// }
