
// addition是指针函数，一个返回类型是指针的函数
int* addition(int a, int b) {
  int* sum = new int(a + b);
  return sum;
}

int subtraction(int a, int b) { return a - b; }

int operation(int x, int y, int (*func)(int, int)) { return (*func)(x, y); }

// miuns是函数指针，指向函数的指针
int (*minus)(int, int) = subtraction;

int* m = addition(1, 2);
int n = operation(3, *m, minus);
