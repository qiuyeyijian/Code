#include <stdio.h>

typedef struct RBNode {
  int data;
  struct RB *parent;  // 父结点指针
  struct RB *lchild;  // 左孩子指针
  struct RB *rchild;  // 右孩子指针
  int color;          // 结点颜色, 0表示红，1表示黑
} RBNode, *RBTree;
