#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  int arr[30][30];
  scanf("%d", &n);
  for (int i = 0; i < 30; ++i) {
    fill(arr[i], arr[i] + 30, 1);
  }

  // 计算下一行元素的同时输出本行元素
  for (int i = 0; i < n; ++i) {
    printf("%d", arr[i][0]);
    for (int j = 1; j <= i; ++j) {
      arr[i + 1][j] = arr[i][j] + arr[i][j - 1];
      printf(" %d", arr[i][j]);
    }
    printf("\n");
  }

  return 0;
}

int main(int argc, char const *argv[]) {
  int nums[20] = {1}, i, j, n;
  scanf("%d", &n);
  for (; i != n; ++i) {
    printf("%d", nums[0]);
    for (j = i; j; --j) {
      nums[j] += nums[j - 1];
    }
    for (j = 1; j <= i; ++j) {
      printf(" %d", nums[j]);
    }
    putchar('\n');
  }
  return 0;
}
