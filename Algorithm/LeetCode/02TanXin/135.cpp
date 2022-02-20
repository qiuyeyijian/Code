#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  int candy(vector<int>& ratings) {
    int n = ratings.size();
    // 所有孩子的糖果数初始化为1
    vector<int> candy(n, 1);

    // 先从左往右遍历一遍，如果右边孩子评分比左边高
    for (int i = 1; i < n; ++i) {
      if (ratings[i] > ratings[i - 1]) {
        candy[i] = candy[i - 1] + 1;
      }
    }

    // 再从右向左遍历，如果左边孩子的评分比右边高
    // 且左边孩子的当前糖果数 不大于右边孩子糖果数
    for (int i = n - 1; i > 0; --i) {
      if (ratings[i - 1] > ratings[i] && candy[i - 1] <= candy[i]) {
        candy[i - 1] = candy[i] + 1;
      }
    }
    return accumulate(candy.begin(), candy.end(), 0);
  }
};