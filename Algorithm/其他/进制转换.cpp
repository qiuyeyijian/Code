#include <iostream>

using namespace std;

// p进制数x转换成十进制数y
int toDecimal(int x, int p) {
  // weight: x各位的权值
  // weight: 会在循环中不断乘权值p，得到1、p^2、p^3...
  int y = 0, weight = 1;
  while (x != 0) {
    y = y + (x % 10) * weight;  // 每次加上x的个位数乘以权值
    x /= 10;                    // 去掉x的各位数
    weight *= p;
  }

  return y;
}

// 十进制数x转换成p进制数
void toOther(int x, int p) {
  int z[100] = {0};  //用于存放p进制的每一位
  int index = 0;
  do {
    z[index++] = x % p;
    x /= p;
  } while (x != 0);

  for (int i = index - 1; i >= 0; --i) {
    printf("%d", z[i]);
  }
}

int main() {
  int x = 15;
  toOther(x, 2);

  return 0;
}