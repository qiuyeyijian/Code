#include <iostream>
#include <string>
using namespace std;

// 获取next数组
void getNext(string str, int* next) {
  int i = 1, j = 0;
  next[0] = -1;

  while (i < str.length()) {
    if (j == -1 || (str[i - 1] == str[j] && i - 1 != j)) {
      next[i] = ++j;
      ++i;
    } else
      j = next[j];
  }
}

int main() {
  string str = "ababaaaba";
  int next[20];
  getNext(str, next);
  for (int i = 0; i < 10; i++) {
    cout << next[i];
  }
  cout << "Hello World";
  return 0;
}