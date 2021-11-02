#include <stdio.h>

// 顺序表中元素类型，这里定义为int
typedef int ElemType;

typedef struct Node {
  ElemType data;
  struct Node *next;
} Node, *LinkList;

// 需要扫描两遍链表
int solve(LinkList head, int k) {
  Node *p = head->next;

  // 计算单链表的长度，不计入头结点
  int len = 0;
  while (p != NULL) {
    len++;
    p = p->next;
  }

  // 找到倒数第k个位置
  p = head;
  int pos = len - k + 1;
  while (p != NULL && pos--) {
    p = p->next;
  }

  if (p != NULL) {
    printf("%d\n", p->data);
    return 1;
  }

  return 0;
}
// 2021.08
// 使用双指针，只需要扫描一遍
int solvePro(LinkList list, int k) {
  // 开始时定义两个指针，均指向头结点的下一个节点
  Node *p = list->next, *q = list->next;
  int count = 0;

  // p首先沿着链表移动，当count==k后，q指针同步移动
  while (p != NULL) {
    p = p->next;
    if (count >= k) {
      q = q->next;
    }
    count++;
  }

  // 如果count >= k, 说明q指针指向的就是倒数第k个节点
  if (count >= k) {
    printf("%d", q->data);
    return 1;
  }

  // 如果count < k，则说明k的值不在合法范围内，查找失败，返回0
  return 0;
}

// 2021.11
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
//   printf("pos: %d\n", getElem(list, 2));

//   solvePro(list, 1);

//   return 0;
// }