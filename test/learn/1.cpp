#include <stdio.h>

#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int a = 10;
  int &b = a;

  b = 20;

  printf("%d", a);
  return 0;
}
