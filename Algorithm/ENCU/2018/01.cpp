#include <stdio.h>

int main(int argc, char const *argv[]) {
  int m, n, k;
  int male = 0, female = 0;
  scanf("%d %d %d", &m, &n, &k);

  for (int i = 0; i < k; ++i) {
    printf("%d %d\n", (male++ % m) + 1, (female++ % n) + 1);
  }

  return 0;
}
