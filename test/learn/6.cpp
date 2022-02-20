#include <iostream>
#include <list>
#include <set>

using namespace std;

class cmp {
 public:
  bool operator()(int a, int b) { return a > b; }
};

// 2、函数对象可以有自己的状态
class MyPrint {
 public:
  int count;  // 计数器

 public:
  MyPrint() { count = 0; }
  void operator()(string test) {
    cout << test << endl;
    count++;  //统计使用次数
  }
};

// bool cmp(int a, int b) { return a > b; }

int main(int argc, char const *argv[]) {
  set<int, cmp> st;

  for (int i = 0; i < 10; ++i) {
    st.insert(i % 3 * 7 + i);
  }
  for (int i : st) {
    printf(" %d", i);
  }

  return 0;
}
