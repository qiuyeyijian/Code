#include <iostream>
#include <string>

using namespace std;

// 生成全是A的字符串，长度为n
string getStrA(int n) {
  string str = "";
  while (n--) {
    str += "A";
  }
  return str;
}

bool judge(string str) {
  int len = str.length();
  int pos1 = str.find("P");  // P首次出现的位置
  int pos2 = str.find("T");  // T首次出现位置
  // 前提：不能包含除P A T以外的其他字符
  for (int i = 0; i < len; i++) {
    if (!(str[i] == 'P' || str[i] == 'A' || str[i] == 'T')) {
      return false;
    }
  }

  // 情况1：中间是字符串PAT ，两边要么没有A，要么A的个数相同
  if (pos1 >= 0 && str == getStrA(pos1) + "PAT" + getStrA(pos1)) {
    return true;
  }

  // 情况2：形如[n个A]P[m个A]T[n * m个A]是成立的, 其中m > 0
  if ((pos2 - pos1 - 1) > 0 && str == getStrA(pos1) + "P" +
                                          getStrA(pos2 - pos1 - 1) + "T" +
                                          getStrA(pos1 * (pos2 - pos1 - 1))) {
    return true;
  }

  return false;  // 如果都不满足，返回false
}

int main() {
  int n;
  string str;
  cin >> n;
  while (n--) {
    cin >> str;
    if (judge(str)) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }

  return 0;
}
