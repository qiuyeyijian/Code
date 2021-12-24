#include <stdio.h>

int Find(int *arr, int x) {
  while (arr[x] > 0) {
    x = arr[x];
  }

  return x;

  // if(arr[x] < 0) return x;
  // return Find(arr, arr[x]);
}

int FindPro(int *arr, int x) {
  if (arr[x] < 0) {
    return x;
  }

  int rx = FindPro(arr, arr[x]);
  arr[x] = rx;
  return rx;
}

void Union(int *arr, int a, int b) {
  int ra = Find(arr, a);
  int rb = Find(arr, b);

  if (ra != rb) {
    arr[rb] = ra;
  }
}

void UnionPro(int *arr, int a, int b) {
  if (a == b) return;

  int ra = Find(arr, a);
  int rb = Find(arr, b);

  int r1 = ra > rb ? ra : rb;
  int r2 = ra > rb ? rb : ra;

  arr[r2] += r1;
  arr[r1] = r2;
}
