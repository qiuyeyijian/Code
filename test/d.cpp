#include <stdio.h>

void show(int *arr, int len) {
  for (int i = 0; i < len; ++i) {
    printf(" %c", arr[i]);
  }
  printf("\n");
}

void preToPost(char *arr, int begin, int end) {
  // 保存根结点数值，留待最后输出，开始位置向后挪动一个位置
  // 相当于将先序遍历头结点转变成后序遍历最后结点
  char root = arr[begin++];

  // 继续划分左右子树，递归
  // 因为是满二叉树，中间位置正好是左右子树界限
  int mid = (begin + end) / 2;
  if (begin <= end) {
    preToPost(arr, begin, mid);
    preToPost(arr, mid + 1, end);
  }
  printf(" %c", root);
}

int main() {
  // 先序序列
  char arr[] = {'a', 'b', 'd', 'e', 'c', 'f', 'g'};

  preToPost(arr, 0, 6);
}