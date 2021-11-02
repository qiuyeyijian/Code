#include <stdio.h>

// 顺序表中元素类型，这里定义为int
typedef int ElemType;

typedef struct Node {
  ElemType data;
  struct Node *next;
} Node, *LinkList;

int getLength(LinkList head) {
  Node *p = head->next;
  int len = 0;

  while (p != NULL) {
    len++;
    p = p->next;
  }

  return len;
}

void reverseList(LinkList &head) {
  Node *p = head->next;
  Node *tmp = NULL;

  // 每次都断掉p的下一个节点，头插法插入到最前
  // 直到p所指节点成为最后一个节点，则逆序完成
  while (p->next != NULL) {
    // 获取p的下一个节点
    tmp = p->next;
    p->next = p->next->next;

    // 头插法
    tmp->next = head->next;
    head->next = tmp;
  }
}

void solve(LinkList &L) {
  Node *p = L->next;
  Node *midp = L;
  Node *tmp = NULL;

  int len = getLength(L);
  int mid = (len + 1) / 2;

  // 移动到中间节点
  while (mid--) {
    midp = midp->next;
  }

  // 原地逆置后半段链表
  reverseList(midp);

  while (p != midp) {
    tmp = midp->next;
    midp->next = midp->next->next;

    tmp->next = p->next;
    p->next = tmp;

    p = p->next->next;
  }
}

// int main() {
//   LinkList list = initLinkList();

//   for (int i = 1; i <= 13; ++i) {
//     insertElem(list, i, i);
//   }

//   show(list);

//   // reverseList(list);
//   solve(list);

//   show(list);

//   return 0;
// }