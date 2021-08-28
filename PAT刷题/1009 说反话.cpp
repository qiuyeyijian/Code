#include <iostream>
#include <stack>
#include <string>

using namespace std;

// 利用栈后进先出的特性实现题目要求
int main() {
  char buff[80];  // 缓冲区
  string str;     // 单词字符串
  stack<string> st;

  // 读入每个单词，依次入栈
  while (scanf("%s", buff) != EOF) {
    str = buff;  // 字符数组转字符串
    st.push(str);
  }

  // 按照格式打印
  printf("%s", st.top().c_str());
  st.pop();
  while (!st.empty()) {
    printf(" %s", st.top().c_str());
    st.pop();
  }

  return 0;
}