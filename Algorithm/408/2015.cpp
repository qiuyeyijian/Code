#include <stdio.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node, *LinkList;

int abs(int a) { return a > 0 ? a : -a; }

// 时间复杂度O(m)，空间复杂度O(n)
void solve(LinkList &head, int n) {
  Node *pre = head;
  Node *p = head->next;

  // 申请n+1个辅助空间，标记是否已访问过该元素
  bool *visited = new bool[n + 1]{false};

  while (p != NULL) {
    // 如果该节点的data已经访问过，则删除该节点
    if (visited[abs(p->data)]) {
      Node *t = p;
      p = p->next;
      pre->next = p;
      delete t;
    } else {
      // 否则保留该节点，并标记已访问
      visited[abs(p->data)] = true;
      pre = p;
      p = p->next;
    }
  }
}

// int main() {
//   LinkList list = initLinkList();

//   for (int i = 1; i <= 10; ++i) {
//     insertElem(list, i, i % 3 + 1);
//   }

//   show(list);

//   solve(list, 20);

//   show(list);

//   return 0;
// }