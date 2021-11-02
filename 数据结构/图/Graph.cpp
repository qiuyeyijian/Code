#include <stdio.h>

const int maxn = 100;

typedef char VertexType;
typedef int EdgeType;

/* 邻接矩阵存储方式，顺序存储 */
typedef struct {
  VertexType vex[maxn];       // 顶点表
  EdgeType edge[maxn][maxn];  // 边表（邻接矩阵）
  int vexNum, arcNum;         // 图的顶点数和边数
} MGraph;

/* 邻接表存储方式，顶点数组加边链表 */

// 边链表
typedef struct ArcNode {
  int adjvex;  // 边指向的顶点的数组下标，根据此下标可以找出对应的顶点信息
  struct ArcNode *next;  // 指向下一条边的指针
} ArcNode;

// 顶点
typedef struct VNode {
  VertexType data;  // 顶点信息
  ArcNode *first;   // 顶点第一条边

} VNode;

// 图
typedef struct ALGraph {
  VNode vex[maxn];     // 顶点数组
  int vexNum, arcNum;  // 顶点数和边数
} ALGraph;