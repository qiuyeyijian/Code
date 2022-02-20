#include <stdio.h>

#include <iostream>
#include <vector>
using namespace std;

DWORD first_time;
DWORD last_time;
DWORD time;
vector<int> v_i_1;
int k = 0;
//********************************************************
first_time = GetTickCount();
for (k = 0; k < 100000000; k++) {
  v_i_1.push_back(k);
}
last_time = GetTickCount();

time = last_time - first_time;
cout << "循环:" << time << endl;
//********************************************************
first_time = GetTickCount();
for (int i = 0; i < v_i_1.size(); i++) {
  int d = v_i_1[i];
}
last_time = GetTickCount();

time = last_time - first_time;
cout << "方法1:" << time << endl;
//********************************************************
first_time = GetTickCount();
int size = v_i_1.size();
for (int i = 0; i < size; i++) {
  int d = v_i_1[i];
}
last_time = GetTickCount();

time = last_time - first_time;
cout << "方法2:" << time << endl;
//********************************************************
//接上面代码：
first_time = GetTickCount();
for (auto it = v_i_1.begin(); it != v_i_1.end(); it++) {
  int d = *it;
}
last_time = GetTickCount();

time = last_time - first_time;
cout << "方法3:" << time << endl;
////********************************************************
first_time = GetTickCount();
for (int i : v_i_1) {
  int d = i;
}
last_time = GetTickCount();

time = last_time - first_time;
cout << "方法4:" << time << endl;
//********************************************************
first_time = GetTickCount();
for_each(v_i_1.begin(), v_i_1.end(), [](int i) { int d = i; });
last_time = GetTickCount();

time = last_time - first_time;
cout << "方法5:" << time << endl;
//********************************************************

for (auto it = v_i_1.begin(); it != v_i_1.end(); it++) {
  int d = *it;
}