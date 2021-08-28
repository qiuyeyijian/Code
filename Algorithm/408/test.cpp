int midNum2(int* a, int* b, int n) {
  int s1 = 0, d1 = n - 1, s2 = 0, d2 = n - 1;
  int m1, m2;

  while (s1 != d1 || s2 != d2) {
    m1 = (s1 + d1) / 2;
    m2 = (s2 + d2) / 2;

    if (a[m1] == b[m2]) {
      return a[m1];
    } else if (a[m1] < b[m2]) {
      if ((s1 + d1) % 2 == 0) {  // 元素个数为奇数
        s1 = m1;                 // 保留中间点
        d2 = m2;                 // 保留中间点
      } else {                   // 元素个数为偶数
        s1 = m1 + 1;             // 不保留中间点
        d2 = m2;                 // 保留中间点
      }
    } else {
      if ((s2 + d2) % 2 == 0) {  // 元素个数为奇数
        s2 = m2;                 // 保留中间点
        d1 = m1;                 // 保留中间点
      } else {                   // 元素个数为偶数
        s2 = m2 + 1;             // 不保留中间点
        d1 = m1;                 // 保留中间点
      }
    }

  }  // end of while

  return (a[s1] < b[s2]) ? a[s1] : b[s2];
}
