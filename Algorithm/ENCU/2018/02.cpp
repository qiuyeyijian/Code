#include <iostream>
using namespace std;

const int maxn = 1e9 + 10;
bool vist[maxn] = {false};

int main(int argc, char const *argv[]) {
  int cnt = 0, i = 0;
  int n, a;

  while (i < maxn) {
    vist[i] = 1;
    i += ++cnt;
  }

  scanf("%d", &n);
  while (n--) {
    scanf("%d", &a);
    printf("%d\n", vist[--a]);
  }

  return 0;
}

// #include <iostream>
// using namespace std;
// const int maxn = 1e9 + 5;
// bool a[maxn] = {false};

// int main() {
//   int n, temp;
//   scanf("%d", &n);

//   int cnt = 0;  //¼ä¸ôÎª1
//   for (int i = 1; i <= maxn; i += cnt) {
//     a[i] = 1;
//     cnt++;
//   }

//   while (n--) {
//     scanf("%d", &temp);
//     printf("%d\n", a[temp]);
//   }
//   return 0;
// }