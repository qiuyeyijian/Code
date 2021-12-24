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

// 时间复杂度O(m+n)，空间复杂度O(1)
LinkList solve(LinkList str1, LinkList str2) {
  int len1 = getLength(str1);
  int len2 = getLength(str2);

  Node *l1 = str1->next;
  Node *l2 = str2->next;

  // 按照表尾对齐
  while (len1 > len2 && len1 != NULL) {
    l1 = l1->next;
    len1--;
  }
  while (len2 > len1 && l2 != NULL) {
    l2 = l2->next;
    len2--;
  }

  Node *p = l1;
  while (l1 != NULL) {
    // 如果发生一次不匹配，则要重新开始
    if (l1->data != l2->data) {
      p = l1;
    }
    l1 = l1->next;
    l2 = l2->next;
  }

  return p;
}

// int main() {
//   LinkList l1 = initLinkList();
//   LinkList l2 = initLinkList();

//   for (int i = 1; i < 10; ++i) {
//     static int k = 11;
//     insertElem(l1, i, k);
//     k /= 2;
//   }

//   for (int i = 1; i < 8; ++i) {
//     static int k = 13;
//     insertElem(l2, i, k);
//     k /= 2;
//   }

//   show(l1);
//   show(l2);

//   Node *p = solve(l1, l2);

//   show(p);

//   return 0;
// }
