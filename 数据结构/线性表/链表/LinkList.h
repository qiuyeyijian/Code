#include <stdio.h>

// 顺序表中元素类型，这里定义为int
typedef int ElemType;

typedef struct Node {
  ElemType data;
  struct Node *next;
} Node, *LinkList;

/**
 * 函数功能：初始化一个带头结点的单链表
 * 函数参数：无
 * 函数返回值：返回单链表的头指针
 */
LinkList initLinkList();

/**
 * 函数功能：在指定位置插入元素
 * 函数参数：
 *      @head: 待插入的线性表的头指针
 *      @pos: 指定的位置
 *      @e: 待插入的数据
 * 函数返回值：插入成功返回true，否则返回false
 */
bool insertElem(LinkList &head, int pos, ElemType data);

/**
 * 函数功能：删除指定位置的元素
 * 函数参数：
 *      @head: 待删除的线性表的头指针
 *      @pos: 指定的位置
 * 函数返回值：删除成功返回true，否则返回false
 */
bool deleteElem(LinkList &head, int pos);

/**
 * 函数功能：获取指定位置元素,0代表头结点
 * 函数参数：
 *      @head: 待查找到线性表的头指针
 *      @pos: 指定的位置
 * 函数返回值：返回找到的元素，否则返回NULL
 */
ElemType getElem(LinkList head, int pos);

/**
 * 函数功能：查找元素，返回第一次出现位序
 * 函数参数：
 *      @head: 待查找的链表的头指针
 * 函数返回值：查找成功，返回位序，否则返回-1
 */
int findElem(LinkList head, ElemType data);

/**
 * 函数功能：打印线性表中的全部元素
 * 函数参数：
 *     @head: 待打印的线性表的头指针
 * 函数返回值：void
 */
void show(LinkList head);

/**
 * 函数功能：获取单链表的表长，不计算头结点
 * 函数参数：
 *     @head: 单链表的头指针
 * 函数返回值：void
 */
int getLength(LinkList head);