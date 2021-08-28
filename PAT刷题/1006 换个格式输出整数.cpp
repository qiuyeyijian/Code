#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int b = n / 100 % 10;
  int s = n / 10 % 10;
  int a = n % 10;

  for (int i = 0; i < b; i++) {
    printf("%c", 'B');
  }
  for (int i = 0; i < s; i++) {
    printf("%c", 'S');
  }
  for (int i = 0; i < a; i++) {
    printf("%d", i + 1);
  }
  printf("\n");

  return 0;
}