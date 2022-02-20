#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    /* 解法1
    // int i1 = m, i2 = 0;

    // for (int i = 0; i < n; ++i) {
    //   nums1[i1++] = nums2[i2++];
    // }

    // sort(nums1.begin(), nums1.end());
    */

    // 解法2
    int pos = (m--) + (n--) - 1;
    while (n >= 0) {
      nums1[pos--] = m >= 0 && nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
    }
  }
};