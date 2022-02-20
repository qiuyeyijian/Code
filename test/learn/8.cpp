#include <algorithm>
#include <ctime>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

// negate
void test01() {
  negate<int> n;
  printf("%d", n(50));
}

// plus
void test02() {
  plus<int> add;
  printf("%d", add(10, 20));
}

// greater
void test03() {
  int arr[] = {1, 99, 33, 22, 66, 4, 9};
  sort(arr, arr + 7, less<int>());
  for (int i : arr) {
    printf(" %d", i);
  }
}

void test05() {
  int arr[] = {1, 2, 3, 4, 5};
  char* str = "123";
  printf("%d\n", accumulate(str, str + 5, 0));
}

void test04() {
  vector<int> vect;
  vect.push_back(1);
  vect.push_back(2);
  vect.push_back(3);
  vect.push_back(4);
  vect.push_back(4);

  auto it = adjacent_find(vect.begin(), vect.end());

  if (it == vect.end()) {
    printf("No\n");
  } else {
    printf("%d\n", *it);
  }
}

void test06() {
  vector<int> v;

  for (int i = 0; i < 10; ++i) {
    v.push_back(i);
  }
}

int main(int argc, char const* argv[]) {
  test05();

  return 0;
}
