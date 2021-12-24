#include <stdio.h>

// 时间复杂度O(n)，空间复杂度O(n)
void solve(int* arr, int len) {
  // 创建大小为n的辅助空间
  int* t = new int[len]{0};
  int ans = -1;

  // 统计各元素出现次数
  for (int i = 0; i < len; ++i) {
    t[arr[i]]++;
  }

  // 寻找出现次数最高的元素
  for (int i = 0; i < len; ++i) {
    if (t[i] > len / 2) ans = i;
  }

  printf("%d\n", ans);
  delete t;
}

//摩尔投票法思想：如果某元素是主元素的话，
//那么他与剩下的其他元素一一抵消的话他也会胜出
//时间复杂度O(n)，空间复杂度O(1)
void moleVote(int* arr, int len) {
  // 选择第一个元素作为临时主元，计数器初始化1
  int ans = arr[0], count = 1;
  for (int i = 1; i < len; ++i) {
    // 如果遇到的元素和临时主元相等，计数器加1，否则抵消减1
    ans == arr[i] ? count++ : count--;

    // 如果计数器为0，则选择当前元素为新的主元
    if (count == 0) {
      ans = arr[i];
      count++;
    }
  }

  count = 0;
  // 统计最后剩下来的临时主元出现次数
  for (int i = 0; i < len; ++i) {
    if (ans == arr[i]) count++;
  }

  printf("%d\n", count > len / 2 ? ans : -1);
}

int main() {
  int arr1[8] = {0, 0, 0, 0, 0, 7, 2, 2};
  int arr2[8] = {0, 5, 5, 3, 5, 1, 5, 7};
  int arr3[8] = {5, 5, 5, 5, 3, 3, 3, 3};

  solve(arr1, 8);
  solve(arr2, 8);

  // moleVote(arr1, 8);
  // moleVote(arr3, 8);

  return 0;
}