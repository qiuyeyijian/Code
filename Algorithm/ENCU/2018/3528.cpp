#include <iostream>
#include <set>

using namespace std;

int main(int argc, char const *argv[]) {
  int m, n, t;
  int ans = 0;
  scanf("%d%d", &m, &n);

  for (int i = 0; i < m; ++i) {
    set<int> s;
    for (int j = 0; j < n; ++j) {
      scanf("%d", &t);
      s.insert(t);
    }

    ans += *(--s.end());
  }
  printf("%d", ans);
  return 0;
}
