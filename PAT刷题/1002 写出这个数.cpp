#include <string.h>

#include <iostream>
#include <string>

using namespace std;

string n = "";  // 输入的自然数
int sum = 0;    // n的各位数字之和
char ch[10];    // 临时字符数组
string strArr[10] = {"ling", "yi",  "er", "san", "si",
                     "wu",   "liu", "qi", "ba",  "jiu"};

int main() {
  cin >> n;

  // 求n各位数字之和
  for (int i = 0; i < n.length(); i++) {
    sum += n[i] - '0';
  }

  // 将sum转换成拼音输出
  sprintf(ch, "%d", sum);  // 将整型转换成字符数组
  for (int i = 0; i < strlen(ch); i++) {
    if (i < strlen(ch) - 1) {
      cout << strArr[ch[i] - '0'] << " ";
    } else {
      cout << strArr[ch[i] - '0'];
    }
  }

  return 0;
}