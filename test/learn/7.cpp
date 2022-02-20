#include <stdio.h>

#include <algorithm>
#include <string>
using namespace std;

class Log {
 public:
  void operator()(std::string str) { printf("%s", str.c_str()); }
};

class Cmp {
 public:
  bool operator()(int a, int b) { return a > b; }
};

// bool cmp(int a, int b) { return a > b; }

int main(int argc, char const *argv[]) {
  Log log;  // 新建一个对象，该对象的使用和一般函数一样
  log("Hello, word");

  int arr[] = {3, 5, 2, 1};
  sort(arr, arr + 7, Cmp());

  return 0;
}
