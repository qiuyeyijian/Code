#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int n;
  int flag = 1;
  int a[110] = {0};

  scanf("%d", &n);

  // 读入待验证的数字，将数组对应位置的值设为1
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    a[t] = 1;
  }

  // 进行卡拉兹运算，每进行一步，就将数组对应位置的值设为0
  for (int i = 2; i < 101; i++) {
    if (a[i]) {
      int t = i;
      while (t != 1) {
        if (t % 2) {
          t = (3 * t + 1) / 2;
        } else {
          t /= 2;
        }
        if (t <= 100) {  // 用户输入的是100以内的数，所以我们只考虑100以内的数字
          a[t] = 0;
        }
      }
    }
  }

  // 最后，数组中值为1的下标就是没有被数列中的其他数字所覆盖的”关键数“
  for (int i = 100; i > 1; i--) {
    if (a[i]) {
      if (flag) {
        printf("%d", i);
        flag = 0;
      } else {
        printf(" %d", i);
      }
    }
  }

  return 0;
}