#include <stdio.h>

typedef struct Node {
  char data;
  struct Node* next;
} Node, *LinkList;

int getLen(LinkList list) {
  Node* p = list->next;
  int ans = 0;

  while (p != NULL) {
    ans++;
    p = p->next;
  }

  return ans;
}

void solve(LinkList str1, LinkList str2, Node* p) {
  int len1 = getLen(str1);
  int len2 = getLen(str2);
  int gap = len1 - len2;

  Node* l1 = str1->next;
  Node* l2 = str2->next;

  while (gap > 0) {
    l1 = l1->next;
  }
  while (gap < 0) {
    l2 = l2->next;
  }

  p = l1;
  while (l1 != NULL) {
    if (l1->data != l2->data) {
      p = l1->next;
    }
    l1 = l1->next;
    l2 = l2->next;
  }
}

int main() { return 0; }