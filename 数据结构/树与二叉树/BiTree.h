
#include <stdio.h>

#include <queue>

using namespace std;

typedef int ElemType;

typedef struct BiNode {
  ElemType data;                   // 数据域
  struct BiNode *lchild, *rchild;  // 左右孩子指针
} BiNode, *BiTree;

BiNode* newNode(int data);

void init(BiTree& root, int* arr, int len);

void biInit(BiTree& root, int* arr, int index);

void biChange(BiTree root, int data, int newData);

void preOrder(BiTree root);

void inOrder(BiTree root);

void postOrder(BiTree root);

void layerOrder(BiTree root);