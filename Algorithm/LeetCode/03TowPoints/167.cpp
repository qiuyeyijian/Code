#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    int t = 0;

    while (left < right) {
      t = numbers[left] + numbers[right];
      if (t > target) {
        --right;
      } else if (t < target) {
        ++left;
      } else {
        break;
      }
    }
    return vector<int>{left + 1, right + 1};
  }
};