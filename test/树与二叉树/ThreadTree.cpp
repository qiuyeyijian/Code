#include <stdio.h>

typedef int ElemType;

typedef struct ThreadNode {
  ElemType data;
  struct ThreadNode *lchild, *rchild;
  int ltag, rtag;
} ThreadNode, *ThreadTree;

void inThread(ThreadTree &p, ThreadTree &pre) {
  if (p != NULL) {
    inThread(p->lchild, pre);
    if (p->lchild == NULL) {
      p->lchild = pre;
      p->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL) {
      pre->rchild = p;
      pre->rtag = 1;
    }
    pre = p;
    inThread(p->rchild, pre);
  }
}

ThreadNode *firstNode(ThreadNode *p) {
  while (p->ltag == 0) p = p->lchild;  // 最左下节点（不一定是叶节点）
  return p;
}

// 求中序线索二叉树中结点p在中序序列下的后继
ThreadNode *nextNode(ThreadNode *p) {
  return p->rtag == 0 ? firstNode(p->rchild) : p->rchild;
}
