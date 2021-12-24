#include <stdio.h>

const int maxn = 100;

typedef char VertexType;
typedef int EdgeType;

typedef struct {
  VertexType vex[maxn];
  EdgeType edge[maxn][maxn];
  int vexNum, arcNum;
} MGraph;

typedef struct ArcNode {
  int adjvex;
  struct ArcNode *next;
} ArcNode;

typedef struct VNode {
  VertexType data;
  ArcNode *first;
} VNode;

typedef struct ALGraph {
  VNode vex[maxn];
  int vexNum, arcNum;
} ALGraph;