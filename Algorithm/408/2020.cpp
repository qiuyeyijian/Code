#include <stdio.h>

int abs(int a) { return a > 0 ? a : -a; }

// 时间复杂度O(n^3)，空间复杂度O(1)
void solve(int* arr1, int len1, int* arr2, int len2, int* arr3, int len3) {
  int ans = 65535;
  for (int i = 0; i < len1; ++i) {
    for (int j = 0; j < len2; ++j) {
      for (int k = 0; k < len3; ++k) {
        int t = abs(arr1[i] - arr2[j]) + abs(arr1[i] - arr3[k]) +
                abs(arr2[j] - arr3[k]);
        if (t < ans) ans = t;
      }
    }
  }

  printf("%d\n", ans);
}

int main() {
  int arr1[3] = {-1, 0, 9};
  int arr2[4] = {-25, 10, 10, 11};
  int arr3[5] = {2, 9, 17, 30, 41};

  solve(arr1, 3, arr2, 4, arr3, 5);

  return 0;
}