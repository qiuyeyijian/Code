#include <stdio.h>

#include <iostream>
#include <string>
using namespace std;

template <class NameType, class AgeType = int>
class Person {
 public:
  NameType mName;
  AgeType mAge;

 public:
  Person(NameType name, AgeType age) {
    this->mName = name;
    this->mAge = age;
  }
  void showPerson() {
    cout << "name:" << this->mName << "age:" << this->mAge << endl;
  }
};