#include <stdio.h>

typedef struct Node {
  int data;
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

// 时间复杂度O(n^2)，空间复杂度O(1)
LinkList solve(LinkList str1, LinkList str2) {
  Node *head1 = str1->next;
  Node *head2 = str2->next;

  while (head1 != NULL) {
    while (head2 != NULL) {
      if (head1 == head2) return head1;
      head2 = head2->next;
    }
    head1 = head1->next;
    head2 = str2->next;
  }

  return NULL;
}

// 时间复杂度O(m+n)，空间复杂度O(1)
LinkList solvePro(LinkList str1, LinkList str2) {
  // 获取str1和str2的长度
  int m = getLength(str1);
  int n = getLength(str2);

  Node *mp = str1->next;
  Node *np = str2->next;

  // 将两个链表以表尾对齐
  while (m < n && np != NULL) {
    np = np->next;
    n--;
  }
  while (m > n) {
    mp = mp->next;
    m--;
  }

  // 将指针mp和np同步向后移动，并比较是否相等
  while (mp != NULL && mp != np) {
    mp = mp->next;
    np = np->next;
  }

  // 返回共同后缀其实地址，如果没有则返回NULL
  return mp;
}

// int main() {
//   LinkList l1 = initLinkList();
//   LinkList l2 = initLinkList();
//   LinkList l3 = initLinkList();

//   for (int i = 1; i <= 3; ++i) {
//     insertElem(l1, i, i);
//   }

//   for (int i = 1; i <= 3; ++i) {
//     insertElem(l2, i, i * 2);
//   }

//   for (int i = 1; i <= 3; ++i) {
//     insertElem(l3, i, i + 5);
//   }

//   Node *head1 = l1;
//   Node *head2 = l2;
//   Node *head3 = NULL;

//   while (head1->next != NULL) {
//     head1 = head1->next;
//   }
//   while (head2->next != NULL) {
//     head2 = head2->next;
//   }
//   head1->next = l3->next;
//   head2->next = l3->next;

//   if (head1->next == head2->next) printf("true\n");

//   head3 = solvePro(l1, l2);

//   show(head3);

//   return 0;
// }