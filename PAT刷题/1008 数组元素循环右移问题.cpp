#include <iostream>

using namespace std;

// 开始是首元素的地址，结束是尾元素地址的下一个地址
void reverseArr(int* start, int* end) {
  int n = (end - start) / 2;
  for (int i = 0; i < n; i++) {
    int t = *(start + i);
    *(start + i) = *(end - i - 1);
    *(end - i - 1) = t;
  }
}

int main() {
  int n, m;
  int arr[110];
  scanf("%d %d", &n, &m);

  m %= n;  // m的值可能大于数组长度n, 所以需要取模
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  reverseArr(arr, arr + n);  // 先将整个数组[0，N)逆置一遍；
  reverseArr(arr, arr + m);  // 再将数组的前部分区间[0，M)进行逆置；
  reverseArr(arr + m, arr + n);  // 最后将数组的后部分区间[M，N)进行逆置；

  printf("%d", arr[0]);
  for (int i = 1; i < n; i++) {
    printf(" %d", arr[i]);
  }

  return 0;
}