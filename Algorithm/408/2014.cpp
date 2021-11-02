#include <stdio.h>

typedef struct BiNode {
  int weight;                      // 数据域
  struct BiNode *lchild, *rchild;  // 左右孩子指针
} BiNode, *BiTree;

/*
             1
        2        3
     4    5         6
  7         8

*/

int solve(BiTree root, int layer) {
  // 定义一个static变量存储wpl
  static int wpl = 0;
  // 递归边界
  if (root == NULL) {
    return wpl;
  }

  // 如果是叶子结点则累加权值
  if (root->lchild == NULL && root->rchild == NULL) {
    wpl += root->weight * layer;
  }

  // 递归遍历左右子树
  solve(root->lchild, layer + 1);
  solve(root->rchild, layer + 1);

  return wpl;
}

// int main() {
//   BiTree root = NULL;
//   int arr[20] = {1, 2, 3, 4, 5, -1, 6, 7, -1, -1, 8};

//   init(root, arr, 11);

//   printf("%d\n", solve(root, 1));

//   return 0;
// }