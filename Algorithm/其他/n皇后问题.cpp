#include <math.h>
#include <stdio.h>
const int maxn = 11;

bool hashTable[maxn] = {false};
int count = 0, n, p[maxn];

void nQueen(int index) {
  // 递归边界，生成一个n皇后排列方案
  if (index == n + 1) {
    // 设置一个标志，判断是否是合法方案
    bool flag = true;
    // 遍历任意两个皇后
    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        if (abs(i - j) == abs(p[i] - p[j])) {
          flag = false;
        }
      }
    }

    if (flag) ++count;
    return;
  }

  for (int x = 1; x <= n; x++) {
    if (hashTable[x] == false) {
      p[index] = x;
      hashTable[x] = true;
      nQueen(index + 1);
      hashTable[x] = false;
    }
  }
}

void nQueenPro(int index) {
  if (index == n + 1) {
    ++count;
    return;
  }

  // 第x行
  for (int x = 1; x < n; ++x) {
    // 第x行还没有皇后
    if (hashTable[x] == false) {
      bool flag = true;
      for (int pre = 1; pre < index; ++pre) {
        if (abs(index - pre) == abs(x - p[pre])) {
          flag = false;
          break;
        }
      }
      // 如果皇后可以放在第x行
      if (flag) {
        // 令第index列皇后的行号为x
        p[index] = x;
        // 第x行已经被占用
        hashTable[x] = true;
        // 递归处理第index+1行皇后
        nQueenPro(index + 1);
        // 递归完毕，还原第x行为未占用
        hashTable[x] = false;
      }
    }
  }
}