#include <stdio.h>

#include <stack>

using namespace std;

const int n = 5;

void show(int *arr, int len) {
  for (int i = 0; i < len; ++i) {
    printf(" %d", arr[i]);
  }
  printf("\n");
}

// 查找根结点，返回在数组中的下标
int Find(int *arr, int x) {
  if (arr[x] < 0) return x;
  return Find(arr, arr[x]);
}

int Union(int *arr, int a, int b) {
  int fa = Find(arr, a);
  int fb = Find(arr, b);
  if (fa != fb) {
    arr[fb] = fa;
  }
}

void showlian(int *arr, int len) {
  for (int i = 0; i < len; ++i) {
    stack<int> st;
    if (arr[i] < 0) {
      for (int j = 0; j < len; ++j) {
        if (Find(arr, j) == i) {
          st.push(j);
        }
      }

      printf("liantong: ");
      while (!st.empty()) {
        printf(" %d", st.top());
        st.pop();
      }
      printf("\n");
    }
  }
}

int main() {
  int arr[10] = {1, 1, 1, -1, -1, -1, -1, -1, -1, 1};
  int father[5] = {-1, -1, -1, -1, -1};

  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      int weight = (i - 2) * (i - 1) / 2 + j - 1;
      if (arr[weight] > 0) {
        Union(father, j - 1, i - 1);
      }
    }
  }

  show(father, 5);
  showlian(father, 5);

  return 0;
}