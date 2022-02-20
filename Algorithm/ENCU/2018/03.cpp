#include <stdio.h>

const int maxn = 110;
int vist[maxn] = {0};
int n, k, t;
int ans = 0;

void dp(int deep) {
  if (vist[deep] == 1 || deep > n) {
    return;
  }
  if (deep == n) {
    ans++;
    return;
  }

  dp(deep + 1);
  dp(deep + 2);
  dp(deep + 3);
}

int main(int argc, char const *argv[]) {
  scanf("%d %d", &n, &k);
  while (k--) {
    scanf("%d", &t);
    vist[t] = 1;
  }

    dp(0);
  printf("%d", ans);
  return 0;
}
