#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 1010;

struct MoonCake {
  double stock;  // 库存
  double price;  // 总售价
} k[maxn];

bool cmp(MoonCake a, MoonCake b) {
  return (a.price / a.stock) > (b.price / b.stock);
}

int main() {
  int n, d;          // 月饼的种类数和市场最大需求量
  double ans = 0.0;  // 最后结果

  scanf("%d %d", n, d);
  for (int i = 0; i < n; ++i) {
    scanf("%lf", k[i].stock);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%lf", k[i].price);
  }

  // 将月饼按照单价从高到底排序
  sort(k, k + n, cmp);

  for (int i = 0; i < n; ++i) {
    if (k[i].stock <= d) {  // 如果需求量高于月饼库存量
      ans += k[i].price;
      d -= k[i].stock;
    } else {
      ans += k[i].price / k[i].stock * d;
      break;
    }
  }

  printf("%.2f", ans);

  return 0;
}
