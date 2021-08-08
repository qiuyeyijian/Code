#include <iostream>
#include <string>
using namespace std;

// KMP优化
void getNextVal(string str, int* nextval) {
  int i = 1, j = 0;
  nextval[0] = -1;

  while (i < str.length()) {
    if (j == -1 || (str[i - 1] == str[j] && i - 1 != j)) {
      ++j;
      nextval[i] = str[i] == str[j] ? nextval[j] : j;
      ++i;
    } else
      j = nextval[j];
  }
}

int main() {
  string str = "aaaaaaaab";
  int nextval[20];
  getNextVal(str, nextval);
  for (int i = 0; i < str.length(); i++) {
    cout << nextval[i] + 1;
  }
  //  cout << "Hello World";
  return 0;
}