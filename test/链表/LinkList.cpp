#include "LinkList.h"

#include <stdio.h>

/**
 * 函数功能：初始化一个带头结点的单链表
 * 函数参数：无
 * 函数返回值：返回单链表的头指针
 */
LinkList initLinkList() {
  LinkList l = new Node;
  l->next = NULL;
  l->data = 0;
  return l;
}

/**
 * 函数功能：在指定位置插入元素
 * 函数参数：
 *      @head: 待插入的线性表的头指针
 *      @pos: 指定的位置，<=0头插，大于表长尾插
 *      @e: 待插入的数据
 * 函数返回值：插入成功返回true，否则返回false
 */
bool insertElem(LinkList &head, int pos, ElemType data) {
  Node *p = head;
  Node *s = new Node;
  s->data = data;

  // 获取指定位置的前驱结点，这里默认用户输入的pos大于0
  while (p->next != NULL && --pos) {
    p = p->next;
  }

  // 将节点插入p的后面
  s->next = p->next;
  p->next = s;

  return true;
}

/**
 * 函数功能：删除指定位置的元素
 * 函数参数：
 *      @head: 待删除的线性表的头指针
 *      @pos: 指定的位置
 *
 * 此处没有对pos进行检查，需要注意输入范围正确
 * 函数返回值：删除成功返回true，否则返回false
 */
bool deleteElem(LinkList &head, int pos) {
  Node *p = head, *q;

  // 找到待删除结点的前驱
  while (p != NULL && --pos) {
    p = p->next;
  }

  q = p->next;
  p->next = q->next;

  delete q;

  return true;
}

/**
 * 函数功能：获取指定位置元素,0代表头结点
 * 函数参数：
 *      @head: 待查找到线性表的头指针
 *      @pos: 指定的位置
 * 函数返回值：返回找到的元素，否则返回NULL
 */
ElemType getElem(LinkList head, int pos) {
  Node *p = head;

  while (p != NULL && pos--) {
    p = p->next;
  }
  return p != NULL ? p->data : NULL;
}

/**
 * 函数功能：查找元素，返回第一次出现位序
 * 函数参数：
 *      @head: 待查找的链表的头指针
 * 函数返回值：查找成功，返回位序，否则返回-1
 */
int findElem(LinkList head, ElemType data) {
  Node *p = head->next;
  int count = 1;

  while (p != NULL) {
    if (p->data == data) {
      return count;
    }
    count++;
  }

  return -1;
}

/**
 * 函数功能：打印线性表中的全部元素
 * 函数参数：
 *     @head: 待打印的线性表的头指针
 * 函数返回值：void
 */
void show(LinkList head) {
  Node *p = head->next;

  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

/**
 * 函数功能：获取单链表的表长，不计算头结点
 * 函数参数：
 *     @head: 单链表的头指针
 * 函数返回值：void
 */
int getLength(LinkList head) {
  Node *p = head->next;
  int len = 0;

  while (p != NULL) {
    len++;
    p = p->next;
  }

  return len;
}

int getLen(LinkList list) {
  Node *p = list->next;
  int ans = 0;

  while (p != NULL) {
    ans++;
    p = p->next;
  }

  return ans;
}

LinkList solve(LinkList str1, LinkList str2) {
  int len1 = getLength(str1);
  int len2 = getLength(str2);

  Node *l1 = str1->next;
  Node *l2 = str2->next;

  while (len1 > len2 && len1 != NULL) {
    l1 = l1->next;
    len1--;
  }

  while (len2 > len1 && l2 != NULL) {
    l2 = l2->next;
    len2--;
  }
  Node *p = l1;
  while (l1 != NULL) {
    // 如果发生一次不匹配，则要重新开始
    if (l1->data != l2->data) {
      p = l1;
    }
    l1 = l1->next;
    l2 = l2->next;
  }

  return p;
}

int main() {
  LinkList l1 = initLinkList();
  LinkList l2 = initLinkList();

  for (int i = 1; i < 10; ++i) {
    static int k = 11;
    insertElem(l1, i, k);
    k /= 2;
  }

  for (int i = 1; i < 8; ++i) {
    static int k = 13;
    insertElem(l2, i, k);
    k /= 2;
  }

  show(l1);
  show(l2);

  Node *p = solve(l1, l2);

  show(p);

  return 0;
}