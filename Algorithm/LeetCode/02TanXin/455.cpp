#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i = 0, j = 0;

    for (; i < g.size() && j < s.size(); ++j) {
      if (s[j] >= g[i]) {
        ++i;  // 满足一个孩子
      }
    }
    return i;
  }
};