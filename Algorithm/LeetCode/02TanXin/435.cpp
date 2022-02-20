#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Cmp {
 public:
  bool operator()(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
  }
};

class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int n = intervals.size();
    // 按照结尾从小到大排序
    // 比较函数使用了lambda表达式
    sort(
        intervals.begin(), intervals.end(),
        [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });

    // 第一个肯定被选中
    int ans = 1, prev = intervals[0][1];

    for (int i = 1; i < n; ++i) {
      if (intervals[i][0] >= prev) {
        ++ans;
        prev = intervals[i][1];
      }
    }

    return n - ans;
  }
};