#include <stdio.h>

int func(int n) {
  if (n == 1)
    return 1;
  else
    return func(n - 1) * n;
}

int fibo(int n) {
  if (n <= 1)
    return 1;
  else
    return fibo(n - 1) + fibo(n - 2);
}

int main() {
  int n;
  scanf("%d", &n);
  //   printf("%d", func(n));
  printf("%d", fibo(n));

  return 0;
}
