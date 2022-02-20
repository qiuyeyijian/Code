#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef struct Node {
  int data;
  string priority;
} Node;

bool cmp(Node a, Node b) { return a.priority > b.priority; }

int main(int argc, char const* argv[]) {
  int n, data;
  string priority;
  Node arr[30];
  stringstream stream;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &data);
    stream << data;
    stream >> priority;

    while (priority.length() < 4) {
      priority += priority;
    }
    priority = priority.substr(0, 4);
    arr[i].data = data;
    arr[i].priority = priority;

    stream.clear();
  }

  sort(arr, arr + n, cmp);

  for (int i = 0; i < n; ++i) {
    printf("%d", arr[i].data);
  }

  return 0;
}

// int main() {
//   unsigned n;
//   cin >> n;
//   vector<string> nums(n);
//   for (auto& i : nums) cin >> i;
//   sort(nums.begin(), nums.end(),
//        [](string const& a, string const& b) { return b + a < a + b; });
//   for (auto const& i : nums) cout << i;
// }