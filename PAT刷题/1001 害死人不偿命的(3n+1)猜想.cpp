#include <stdio.h>

int main() {
  int n;        // 待输入的正整数n
  int ans = 0;  // 要输出的答案

  scanf("%d", &n);

  while (n != 1) {  // 只要等于1就一直循环计算
    if (n % 2) {
      n = (3 * n + 1) / 2;
    } else {
      n /= 2;
    }
    ans++;  // 记录步数
  }

  printf("%d", ans);

  return 0;
}