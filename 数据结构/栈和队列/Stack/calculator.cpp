/**
 * @Author: 秋叶依剑
 * @Blog: blog.csdn.net/qiuyeyijian
 *
 * @实现功能:
 *    1. 实现格式化中缀表达式，主要是去掉空格
 *    2. 实现检查括号是否匹配
 *    3. 实现中缀表达式转后缀，结果存放在队列中
 *    4. 实现后缀表达式求值
 *
 * @未考虑细节：
 *    1. 只能检查括号是否匹配，不能检测到用户输入中文括号的情况
 *    2. 假设用户所给的中缀表达式是正确的，并未考虑错误检查
 *
 */

#include <stdio.h>

#include <map>
#include <queue>
#include <stack>
#include <string>

using namespace std;

// 定义一个结构体，用来表示操作数或者操作符
typedef struct Node {
  double num = 0.0;  // 操作数，这里设置成double类型的，提高精确度
  char op;           // 操作符
  bool flag = true;  // 标记是操作数还是操作符，true表示操作数，false表示操作符
} Node;

// 格式化表达式，去掉空格
// expr: 传进来的表达式
void formatExpression(string& expr) {
  // 不断寻找空格，然后删除
  for (int i = expr.find(" "); i != -1; i = expr.find(" ")) {
    // string容器的erase和insert方法传的参数必须是迭代器
    expr.erase(expr.begin() + i);
  }
}

// 检查括号是否匹配
bool bracketsCheck(string expr) {
  // 创建一个操作符栈
  stack<char> op;
  map<char, char> mp;  // 括号配对
  mp['}'] = '{';
  mp[']'] = '[';
  mp[')'] = '(';

  for (int i = 0; i < expr.length(); ++i) {
    char ch = expr[i];
    // 如果遇到了左括号就进栈
    if (ch == '{' || ch == '[' || ch == '(') {
      op.push(ch);
    }
    // 如果遇到了右括号，就判断与栈顶元素是否匹配
    else if (ch == '}' || ch == ']' || ch == ')') {
      // 如果当前栈空，或者括号和栈顶元素不匹配，就返回false
      // 否则说明匹配，就弹出当前栈顶元素，继续下一轮检查
      if (op.empty() || mp[ch] != op.top()) {
        return false;
      } else {
        op.pop();
      }
    }
  }

  // 如果最后栈为空，则说明括号都匹配，返回true
  // 否则返回false
  return op.empty();
}

// 传入两个数和操作符，返回计算的结果
// a在前，b在后，中间是操作符
double getResult(double a, char op, double b) {
  switch (op) {
    case '+':
      return a + b;
      break;
    case '-':
      return a - b;
      break;
    case '*':
      return a * b;
      break;
    case '/':
      return a / b;
      break;
    default:
      printf("输入有误！");
      return 0;
      break;
  }
}

// 传入中缀表达式，将中缀表达式转化成后缀表达式，存放到队列中
void infixToPostfix(string expr, queue<Node>& qu) {
  stack<char> opStack;  // 操作符栈
  Node node;            // 保存当前扫描到的操作数或者操作符

  // 建立操作符和优先级之间的映射，使用STL容器中的map
  map<char, int> priorityMap;
  priorityMap['+'] = 1;
  priorityMap['-'] = 1;
  priorityMap['*'] = 2;
  priorityMap['/'] = 2;

  for (int i = 0; i < expr.length(); ++i) {
    node.num = 0;
    node.flag = false;
    //==========首先考虑处理操作数=============
    // 操作数可能不止一位，所以需要拼接一下
    while (expr[i] - '0' >= 0 && expr[i] - '0' <= 9) {
      node.num = node.num * 10 + (expr[i] - '0');
      node.flag = true;
      ++i;
    }

    // 1. 如果是操作数，则直接进入队列，成为后缀表达式的一部分
    if (node.flag) qu.push(node);

    //==========接下来处理操作符=============
    char ch = expr[i];  // 定义一个变量保存当前操作符

    // 2. 如果操作符栈为空，或者栈顶是左括号，或者当前扫描到的元素是左括号。
    //    直接将当前符号进栈。
    if (opStack.empty() || ch == '(' || opStack.top() == '(') {
      opStack.push(ch);
    }

    // 3. 如果是右括号
    // 4. 或者是中缀表达式结束符'\0', 或者优先级不高于栈顶元素，
    //    则依次弹出栈顶元素，弹出的元素成为后缀表达式的一部分；
    //    直到遇到左括号，或者栈空
    else if (ch == ')' || ch == '\0' ||
             priorityMap[ch] <= priorityMap[opStack.top()]) {
      while (!opStack.empty() && opStack.top() != '(') {
        node.op = opStack.top();
        node.flag = false;
        qu.push(node);
        opStack.pop();
      }
      // 3.1 如果当前是右括号，还需要弹出栈中的左括号
      if (ch == ')') {
        opStack.pop();
      } else {
        // 4.1 否则将当前扫描到的符号进栈
        opStack.push(ch);
      }
    }
    // 5. 其他情况都是扫描到的符号优先级高于栈顶元素优先级，直接进栈
    else {
      opStack.push(ch);
    }
  }
}

// 后缀表达式求值
double evaluatePostfix(queue<Node> qu) {
  stack<double> op;  // 操作数栈
  Node node;         // 保存从栈中弹出来的元素
  // 从左到右扫描所给的后缀表达式，一直到最后
  while (!qu.empty()) {
    node = qu.front();
    qu.pop();
    // 1. 如果是操作数，则直接进操作数栈
    if (node.flag) {
      op.push(node.num);
    }
    // 2. 否则从栈中弹出两个操作数参与计算，先弹出来的放在后面
    //    计算的结果重新进栈
    else {
      double b = op.top();
      op.pop();
      double a = op.top();
      op.pop();
      op.push(getResult(a, node.op, b));
    }
  }

  // 最后栈中的数就是结果
  return op.top();
}

int main() {
  string str = "3 - 2 + ( 5 * 5 - 4 * 4 ) / 3";
  // 1. 格式化中缀表达式
  formatExpression(str);
  // 2. 检查括号是否匹配
  if (bracketsCheck(str))
    printf("Yes!\n");
  else
    printf("No!\n");

  // 3. 中缀转后缀
  queue<Node> qu;
  infixToPostfix(str, qu);

  // 4. 打印后缀表达式求得值
  printf("Result: %f\n", evaluatePostfix(qu));

  return 0;
}