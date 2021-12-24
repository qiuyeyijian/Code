#include <stdio.h>

void sum(int n) {
  // 你给的答案
  printf("\nans1: %d\n", n * (n - 1) * (2 * n - 1) / 6);
  // 我的答案
  printf("\nans2: %d\n", n * (n + 1) * (n + 2) / 6);
}

int main() {
  int n = 5;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      for (int k = 1; k <= j; ++k) {
        ans++;
      }
    }
  }
  // 程序运行结果
  printf("\nans: %d\n", ans);
  sum(n);
  return 0;
}

// main.c
int g(int x) { return x + 3; }

int f(int x) { return g(x); }

int main(void) { return f(8) + 1; }