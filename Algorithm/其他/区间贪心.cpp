
#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn = 100010;

// 定义区间结构体 start:开始点，end结束点
struct Interval {
  int start;
  int end;
} arr[maxn];

bool cmp(Interval a, Interval b) { return a.end < b.end; }

int main() {
  int n = 0;
  int ans = 1;  // 最少能选中一个区间

  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &arr[i].start, &arr[i].end);
  }

  // 按照右端点从小到大排序
  sort(arr, arr + n, cmp);

  int index = arr[0].end;
  for (int i = 1; i < n; ++i) {
    if (arr[i].start >= index) {
      ++ans;
      index = arr[i].end;
    }
  }

  printf("%d", ans);

  return 0;
}