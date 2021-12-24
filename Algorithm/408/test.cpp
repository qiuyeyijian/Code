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

void solve(BTree* root) {
  if (root == NULL) return;

  if (root->left == NULL && root->right == NULL) {
    printf("%s", root->data);
  } else {
    // if (layer > 1) printf("(");

    printf("(");
    solve(root->left);
    printf("%s", root->data);
    solve(root->right);
    printf(")");

    // if (layer > 1) printf(")");
  }
}

int main() {
  char arr[][10] = {"*", "+", "*", "a", "b", "c", "-", "#",
                    "#", "#", "#", "#", "#", "#", "d"};

  char arr1[][10] = {"+", "*", "-", "a", "b", "#", "-",
                     "#", "#", "#", "#", "c", "d"};

  char arr2[][10] = {"+", "a", "b"};
  BTree* root = NULL;
  init(root, arr2, 3);
  // init(root, arr1, 13);

  solve(root);
}