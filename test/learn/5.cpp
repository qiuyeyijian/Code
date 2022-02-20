#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void add(int &v) {
  static int i = 0;
  v += ++i;
}

int main(int argc, char const *argv[]) {
  vector<int> vect(10, 100);

  //  for_each(vect.begin(), vect.end(), add);

  vect.insert(vect.begin() + 3, 3, 10);

  for (int i = 0; i < vect.size(); ++i) {
    printf(" %d", vect[i]);
  }

  // printf("\nFirst way\n");
  // for (int i = 0; i < vect.size(); ++i) {
  //   printf(" %d", vect[i]);
  // }

  // printf("\nSecond way\n");
  // for (auto it = vect.begin(); it != vect.end(); it++) {
  //   printf(" %d", *it);
  // }

  // printf("\nThird way\n");
  // for (vector<int>::iterator it = vect.begin(); it != vect.end(); it++) {
  //   printf(" %d", *it);
  // }

  // printf("\nFourth way\n");
  // for_each(vect.begin(), vect.end(), [](int i) { printf(" %d", i); });

  // printf("\nFifth way\n");
  // for (int i : vect) {
  //   printf(" %d", i);
  // }

  return 0;
}
