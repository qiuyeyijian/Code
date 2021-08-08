#include <stdio.h>

const int maxn = 11;

// p为当前排列，hashTable记录整数x是否已经在p中
int n, p[maxn], hashTable[maxn] = {false};

// 当前处理排列的第index号位
// 注意排列数的值从1开始，为了便于记录，所以数组的第0位不用
void generateP(int index) {
  if (index == n + 1) {  // 递归边界，已经处理完排列，打印输出结果
    for (int i = 1; i <= n; i++) {
      printf("%d", p[i]);
    }
    printf("\n");
    return;
  }

  // 枚举1-n，试图将x填入p[index]中
  for (int x = 1; x <= n; x++) {
    // 如果x还没有参与排列
    if (hashTable[x] == false) {
      // 将x加入当前排列
      p[index] = x;
      // 标记x已经参与排列
      hashTable[x] = true;
      // 处理下一个
      generateP(index + 1);
      // 已经处理完p[index]为x的问题，还原状态
      hashTable[x] = false;
    }
  }
}

int main() {
  n = 3;
  generateP(1);

  return 0;
}