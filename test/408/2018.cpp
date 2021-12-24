#include <stdio.h>

int solve(int *arr, int n) {
  int *visited = new int[n + 1];

  for (int i = 0; i < n; ++i) {
    if (arr[i] > 0 && arr[i] <= n) visited[arr[i]] = 1;
  }

  for (int i = 1; i <= n; ++i) {
    if (visited[i] == 0) return i;
  }

  return n + 1;
}

int main() {
  int arr[5] = {-5, -2, 3, 2, 3};
  int arr1[3] = {1, 2, 3};
  printf("%d\n", solve(arr, 5));
  printf("%d\n", solve(arr1, 3));
  return 0;
}