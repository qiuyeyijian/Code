#include <iostream>

using namespace std;

int main() {
  int a, b;

  // 考虑到输出格式问题，首先计算最高项
  scanf("%d", &a);
  scanf("%d", &b);
  if (b) {  // 如果b不为0
    printf("%d %d", a * b, b - 1);
  } else {
    printf("0 0");
  }

  while (scanf("%d", &a) != EOF && scanf("%d", &b) != EOF) {
    if (b) {
      printf(" %d %d", a * b, b - 1);
    }
  }

  return 0;
}