#include <iostream>

using namespace std;

int strToInt(char s[], int len) {
  int id = 0;
  for (int i = 0; i < len; ++i) {
    id = id * 26 + (s[i] - 'A');
  }

  return id;
}