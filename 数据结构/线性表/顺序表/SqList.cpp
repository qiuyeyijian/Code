#include "SqList.h"

/**
 * 函数功能：获取指定位置元素，采用线性表的位序，从1开始编号
 * 函数参数：
 *      @l: 待查找到线性表
 *      @pos: 指定的位置
 * 函数返回值：返回找到的元素，否则返回NULL
 */
ElemType getElem(Sqlist l, int pos) {
  if (pos < 1 || pos > l.length) return NULL;
  return l.data[pos - 1];
}

/**
 * 函数功能：在指定位置插入元素
 * 函数参数：
 *      @l: 待插入的线性表
 *      @pos: 指定的位置
 *      @e: 待插入的数据
 * 函数返回值：返回找到的元素，否则返回NULL
 */
bool insertElem(Sqlist &l, int pos, ElemType e) {
  if (pos < 1 || pos > l.length + 1 || pos >= maxn) return false;

  // 从指定位置开始向后移动一个单位
  for (int i = l.length; i >= pos; i--) {
    l.data[i] = l.data[i - 1];
  }

  l.data[pos - 1] = e;
  l.length++;

  return true;
}

/**
 * 函数功能：删除指定位置的元素
 * 函数参数：
 *      @l: 待删除的线性表
 *      @pos: 指定的位置
 * 函数返回值：删除成功返回true，否则返回false
 */
bool deleteElem(Sqlist &l, int pos) {
  if (pos < 1 || pos > l.length) return false;
  // 从指定位置开始向前移动一个单位，覆盖指定位置元素，达到删除目的
  for (int i = pos; i < l.length; i++) {
    l.data[i - 1] = l.data[i];
  }

  l.length--;
  return true;
}

/**
 * 函数功能：查找元素，返回第一次出现位序（数组下标加1）
 * 函数参数：
 *      @l: 待查找的链表
 * 函数返回值：查找成功，返回位序，否则返回-1
 */
int findElem(Sqlist l, ElemType e) {
  for (int i = 0; i < l.length; i++) {
    if (l.data[i] == e) return i + 1;
  }

  return -1;
}

/**
 * 函数功能：打印线性表中的全部元素
 * 函数参数：
 *     @l: 待打印的线性表
 * 函数返回值：void
 */
void show(Sqlist l) {
  for (int i = 0; i < l.length; ++i) {
    printf("%d ", l.data[i]);
  }
  printf("\n\n");
}

int main() {
  SqList l;
  for (int i = 1; i < 10; i++) {
    insertElem(l, i, i);
  }

  deleteElem(l, 2);

  printf("index: %d\n", findElem(l, 5));

  show(l);

  return 0;
}