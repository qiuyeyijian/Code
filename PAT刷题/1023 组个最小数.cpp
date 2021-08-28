#include <iostream>
using namespace std;

int main() {
  int a[12] = {0};

  for (int i = 0; i < 10; ++i) {
    scanf("%d", &a[i]);
  }

  // 打印第一个非0的数
  for (int i = 1; i < 10; ++i) {
    if (a[i] != 0) {
      printf("%d", i);
      --a[i];
      break;  // 找到第一个之后及时中断循环
    }
  }

  for (int i = 0; i < 10; ++i) {
    while (a[i]) {
      printf("%d", i);
      --a[i];
    }
  }

  return 0;
}