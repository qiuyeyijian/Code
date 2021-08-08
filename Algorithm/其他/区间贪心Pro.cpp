#include <stdio.h>

#include <algorithm>

using namespace std;

const int maxn = 100010;

struct Interval {
  int left;
  int right;
} intervals[maxn];

// 先按照右端点从小到大排序
// 如果右端点相等，按照左端点从大到小排序
bool cmp(Interval a, Interval b) {
  return (a.right != b.right) ? a.right < b.right : a.left > b.left;
}

int main() {
  int n;        // 将要输入的区间个数
  int ans = 1;  // 第0个区间肯定会被选择到
  int index;    // 记录上一个被选择区间的右端点

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &intervals[i].left, &intervals[i].right);
  }

  sort(intervals, intervals + n, cmp);

  index = intervals[0].right;
  for (int i = 1; i < n; ++i) {
    // 如果该区间的左端点大于上一个选中的区间的右端点，则选中该区间，记录加1
    if (intervals[i].left >= index) {
      index = intervals[i].right;
      ++ans;
    }
  }

  printf("%d", ans);

  return 0;
}