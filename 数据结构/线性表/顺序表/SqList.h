#include <stdio.h>

// 顺序表中元素类型，这里定义为int
typedef int ElemType;

// 定义顺序表的最大长度
const int maxn = 1000;

typedef struct SqList {
  ElemType data[maxn];
  int length = 0;  // 顺序表当前长度
} Sqlist;

/**
 * 函数功能：获取指定位置元素，采用线性表的位序，从1开始编号
 * 函数参数：
 *      @l: 待查找到线性表
 *      @pos: 指定的位置
 * 函数返回值：返回找到的元素，否则返回NULL
 */
ElemType getElem(Sqlist l, int pos);

/**
 * 函数功能：在指定位置插入元素
 * 函数参数：
 *      @l: 待插入的线性表
 *      @pos: 指定的位置
 *      @e: 待插入的数据
 * 函数返回值：插入成功返回true，否则返回false
 */
bool insertElem(Sqlist &l, int pos, ElemType e);

/**
 * 函数功能：删除指定位置的元素
 * 函数参数：
 *      @l: 待删除的线性表
 *      @pos: 指定的位置
 * 函数返回值：删除成功返回true，否则返回false
 */
bool deleteElem(Sqlist &l, int pos);

/**
 * 函数功能：查找元素，返回第一次出现位序
 * 函数参数：
 *      @l: 待查找的链表
 * 函数返回值：查找成功，返回位序，否则返回-1
 */
int findElem(Sqlist l, ElemType e);

/**
 * 函数功能：打印线性表中的全部元素
 * 函数参数：
 *     @l: 待打印的线性表
 * 函数返回值：void
 */
void show(Sqlist l);