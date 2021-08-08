#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>

using namespace std;

typedef struct Node {
  double num;
  char op;
  bool flag;
} Node;

string str;
// 操作符栈
stack<Node> st;
// 后缀表达式序列
queue<Node> qu;
map<char, int> op;