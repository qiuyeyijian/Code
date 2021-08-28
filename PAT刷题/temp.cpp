#include <iostream>
using namespace std;

int main() {
  int N;
  int M;
  cin >> N;
  getchar();
  cin >> M;
  getchar();
  int *arr = new int[N];
  for (int i = 0; i < N; i++) {
    int pos = (i + M) % N;
    cin >> arr[pos];
    getchar();
  }
  for (int i = 0; i < N; i++) {
    if (i != 0) {
      cout << " ";
    }
    cout << arr[i];
  }
  return 0;
}