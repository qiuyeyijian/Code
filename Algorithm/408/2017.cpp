#include <stdio.h>
#include <string.h>

#include <queue>

using namespace std;

typedef struct node {
  char data[10];  // 存储操作数或操作符
  struct node *left, *right;
} BTree;

BTree* newNode(char* data) {
  BTree* n = new BTree;
  n->left = n->right = NULL;
  strcpy(n->data, data);
  return n;
}

// 层序遍历构建二叉树
void init(BTree*& root, char data[][10], int len) {
  queue<BTree**> qu;
  qu.push(&root);

  for (int i = 0; i < len; ++i) {
    BTree** n = qu.front();
    qu.pop();
    // 如果和 ”#” 不相等
    if (strcmp(data[i], "#") != 0) {
      *n = newNode(data[i]);
      qu.push(&(*n)->left);
      qu.push(&(*n)->right);
    }
  }
}

// 先序遍历
void preOrder(BTree* root) {
  if (root == NULL) {
    return;
  }

  printf("%s", root->data);
  preOrder(root->left);
  preOrder(root->right);
}

void solve(BTree* root, int layer) {
  if (root == NULL) {
    return;
  }

  // 若为叶节点则直接输出操作数，不加括号
  if (root->left == NULL && root->right == NULL) {
    printf("%s", root->data);
  } else {
    // 若不是叶节点，且所处层数大于1，则需要加相应的括号
    if (layer > 1) {
      printf("(");
    }
    solve(root->left, layer + 1);
    printf("%s", root->data);
    solve(root->right, layer + 1);
    if (layer > 1) {
      printf(")");
    }
  }
}

int main() {
  char arr[][10] = {"*", "+", "*", "a", "b", "c", "-", "#",
                    "#", "#", "#", "#", "#", "#", "d"};

  char arr1[][10] = {"+", "*", "-", "a", "b", "#", "-",
                     "#", "#", "#", "#", "c", "d"};
  BTree* root = NULL;
  init(root, arr, 15);
  // init(root, arr1, 13);

  solve(root, 1);
}