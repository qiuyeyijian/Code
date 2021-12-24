#include <iostream>

void show(int* arr, int len) {
  for (int i = 0; i < len; ++i) {
    printf(" %d", arr[i]);
  }
  printf("\n");
}

void swap(int& a, int& b) {
  int c = a;
  a = b;
  b = c;
}

int sum(int* arr, int len) {
  int ans = 0;
  for (int i = 0; i < len; ++i) {
    ans += arr[i];
  }
  return ans;
}

int solve(int* arr, int len) {
  int mid = len / 2;
  for (int i = 0; i < mid; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] > arr[j]) swap(arr[i], arr[j]);
    }
  }

  return sum(arr + mid, len - mid) - sum(arr, mid);
}

int main() {
  int arr[] = {1, 2};
  int len = sizeof(arr) / sizeof(arr[0]);

  printf("ans: %d\n", solve(arr, len));
  show(arr, len);

  return 0;
}