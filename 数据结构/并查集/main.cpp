#include <stdio.h>

// 递推实现find
int find(int *arr, int x) {
  while (x != arr[x]) {  // 如果不是根结点，继续循环
    x = arr[x];          // 获取自己的父亲结点
  }
  return x;
}

// 递归实现find
int find2(int *arr, int x) {
  if (x == arr[x])
    return x;
  else
    return find2(arr, arr[x]);
}

void Union(int *arr, int a, int b) {
  int fa = find(arr, a);
  int fb = find(arr, b);

  if (fa != fb) {
    arr[fb] = fa;
  }
}

int findFather(int *arr, int x) {
  // 由于x在下面的while中会变成根结点，因此先把原先的x保存一下
  int a = x;
  while (x != arr[x]) {  // 寻找根结点
    x = arr[x];
  }

  // 到这里，想存放的是根结点。下面把路径上的所有结点的Father都改成根结点
  while (a != arr[a]) {
    int z = a;
    a = arr[a];
    arr[z] = x;
  }
  return x;
}

int find3(int *arr, int x) {
  if (x == arr[x]) return x;

  int f = find3(arr, arr[x]);
  arr[x] = f;
  return f;
}

int main() { return 0; }