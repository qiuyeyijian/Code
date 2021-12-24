#include "BiTree.h"

BiNode* newNode(int data) {
  BiNode* n = new BiNode;
  n->data = data;
  // 初始状态下没有左右孩子，也就是该节点的左右指针指向NULL
  n->lchild = n->rchild = NULL;

  return n;
}

// 根据层次遍历创建二叉树，-1表示空
void init(BiTree& root, int* arr, int len) {
  queue<BiNode**> qu;  // 注意队列里存的是指针的地址，也就是二级指针
  qu.push(&root);

  for (int i = 0; i < len; ++i) {
    BiNode** n = qu.front();  // 去除一个指针
    qu.pop();
    if (arr[i] != -1) {
      *n = newNode(arr[i]);    // 改变指针的指向
      qu.push(&(*n)->lchild);  // 将左右孩子指针的地址入队
      qu.push(&(*n)->rchild);
    }
  }
}

// 根据先序遍历序列创建一棵二叉树，-1表示空
void biInit(BiTree& root, int* arr, int index) {
  static int i = index;
  if (arr[i] == -1) {
    root = NULL;
  } else {
    root = newNode(arr[i]);
    biInit(root->lchild, arr, i++);
    biInit(root->rchild, arr, i++);
  }
}

void biChange(BiTree root, int data, int newData) {
  if (root == NULL) {
    return;  // 空树，死胡同（递归边界）
  }

  // 找到数据域为data的节点，把它修改为newData
  if (root->data == data) {
    root->data = newData;
  }

  // 递归搜索左右子树
  biChange(root->lchild, data, newData);
  biChange(root->rchild, data, newData);
}

// 先序遍历
void preOrder(BiTree root) {
  if (root == NULL) {
    return;
  }

  printf("%d ", root->data);
  preOrder(root->lchild);
  preOrder(root->rchild);
}

// 中序遍历
void inOrder(BiTree root) {
  if (root == NULL) {
    return;
  }

  inOrder(root->lchild);
  printf("%d ", root->data);
  inOrder(root->rchild);
}

// 后序遍历
void postOrder(BiTree root) {
  if (root == NULL) {
    return;
  }

  postOrder(root->lchild);
  postOrder(root->rchild);
  printf("%d ", root->data);
}

// 层序遍历
void layerOrder(BiTree root) {
  queue<BiNode*> qu;
  qu.push(root);

  while (!qu.empty()) {
    BiNode* n = qu.front();
    qu.pop();

    printf("%d ", n->data);
    if (n->lchild != NULL) qu.push(n->lchild);
    if (n->rchild != NULL) qu.push(n->rchild);
  }
}

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
    wpl += root->data * layer;
  }

  // 递归遍历左右子树
  solve(root->lchild, layer + 1);
  solve(root->rchild, layer + 1);

  return wpl;
}

void initHalfman(BiTree& root, int* arr, int len) {
  BiNode* p = root;
  for (int i = 0; i < len; ++i) {
    p->rchild = newNode(arr[i]);
    p = p->rchild;
  }
}

void insertNode(BiTree& root, int data) {
  BiNode* p = root;
  BiNode* s = newNode(data);

  while (p->rchild != NULL && (p->rchild->data < data)) {
    p = p->rchild;
  }
  s->rchild = p->rchild;
  p->rchild = s;
}

typedef struct Node {
  BiNode* binode;
  Node* next;
} Node, *LinkList;

int main() {
  BiTree root = newNode(0);
  BiNode* p = root;

  int arr[] = {1, 2, 3, 4, 5};

  initHalfman(root, arr, 5);

  insertNode(root, 3);

  while (p != NULL) {
    printf(" %d", p->data);
    p = p->rchild;
  }

  return 0;
}