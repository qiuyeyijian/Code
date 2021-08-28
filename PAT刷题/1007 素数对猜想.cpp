#include <math.h>
#include <stdio.h>

bool isPrime(int n) {  // 判断一个数是否为素数
  if (n <= 1) return false;
  int sqr = (int)sqrt(n * 1.0);
  for (int i = 2; i <= sqr; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  int n;
  int ans = 0;

  scanf("%d", &n);
  for (int i = 3; i + 2 <= n; i += 2) {  // 从第二个素数开始判断，每次自增2
    if (isPrime(i) && isPrime(i + 2)) ans++;
  }
  printf("%d", ans);
  return 0;
}