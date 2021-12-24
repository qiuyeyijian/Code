#include <stdio.h>

// 假设根结点保存的值都是小于0，非根结点保存父结点的下标，所以大于0
// 以此判断结点是否为根结点。
// 初始化并查集，每个结点都是根结点
// int father[] = {-1, -1, -1, -1};

int Find(int *arr, int x) {
  // 递推形式
  while (arr[x] > 0) {
    x = arr[x];
  }
  return x;

  // 递归形式
  // if(arr[x] < 0) return x;
  // return Find(arr, arr[x]);
}

// 查找优化，压缩路径
int FindPro(int *arr, int x) {
  if (arr[x] < 0) {  // 如果是根结点，直接返回
    return x;
  }

  int rx = FindPro(arr, arr[x]);  // 递归查找根结点
  arr[x] = rx;                    // 将结点x直接指向根结点
  return rx;                      // 返回根结点

  /* 非递归版本
  // int root = x;
  // while (arr[x] >= 0) {  // 循环找到根结点
  //   root = arr[root];
  // }

  // // 压缩路径，将从x到根结点查找过程中的所有结点
  // // 都直接指向根结点，以后查找时间复杂度都为O(1)
  // while (x != root) {
  //   int t = arr[x];
  //   arr[x] = root;
  //   x = t;
  // }
  // return root;
  */
}

void Union(int *arr, int a, int b) {
  int ra = Find(arr, a);
  int rb = Find(arr, b);
  if (ra != rb) {
    arr[rb] = ra;  // 将b所在集合的并到a所在集合
  }
}

// 小树并到大树，使得查找时间复杂度不超过O(log_2 n)
// 根结点保存的是负数，其绝对值是该集合的结点数量
void UnionPro(int *arr, int a, int b) {
  if (a == b) return;
  int ra = Find(arr, a);
  int rb = Find(arr, b);

  // 因为是负数比较
  // ra > rb 则ra结点数较少。寻找二者中结点数较少的赋值给r1
  int r1 = ra > rb ? ra : rb;
  // 寻找二者中结点数较多的的赋值给r2
  int r2 = ra > rb ? rb : ra;

  // 小树并到大树，结点少的并到结点多的
  arr[r2] += r1;  // 结点数相加
  arr[r1] = r2;
}

void show(int *arr, int len) {
  for (int i = 0; i < len; ++i) {
    printf(" %d", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[5] = {0, 2, 3, 4, 0};
  int arr1[10] = {1, 2, 3, 4, 4, 6, 7, 8, 9, 9};

  printf("ans = %d\n", Find(arr, 3));
  printf("ans = %d\n", Find(arr1, 3));
  printf("ans = %d\n", Find(arr1, 6));
  Union(arr1, 3, 6);
  printf("ans = %d\n", Find(arr1, 3));
  printf("ans = %d\n", Find(arr1, 6));
  show(arr1, 10);

  return 0;
}