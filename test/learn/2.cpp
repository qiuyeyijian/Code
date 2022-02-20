#include <stdio.h>

const double PI = 3.14;

class Circle {
 public:
  int m_r;

  double calc() { return 2 * PI * m_r; }
};

class Person {
 public:
  Person() { printf("Create!\n"); }

  ~Person() { printf("Delete!\n"); }
};
