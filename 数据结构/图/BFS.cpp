#include <stdio.h>

#include <queue>

using namespace std;

/**
 * BFS(u)   // 遍历u所在的连通块
 * queue q;
 * 将q入队
 * inq[u] = true;   // 设置u已被加入队列
 * while(q 非空) {
 *  取出q的队首元素进行访问
 *  for(从u出发可达到的所有顶点 v)
 *      if(inq[v] == false) {
 *          将v入队
 *          inq[v] = true;
 *
 *      }
 *
 * }
 *
 * BFSTrave(G) {
 *  for(G的所有顶点 u) {
 *      if(inq[u] == false) {
 *          BFS(u);
 *      }
 * }
 * }
 */

/* 邻接矩阵版 */
const int MAXV = 1000;  // 最大顶点数
const int INF = 65535;

int n, G[MAXV][MAXV];  // n为顶点数，MAXV为最大顶点数
// 若顶点i曾入过队列，则inQu[i] == true。初值为false
bool inQu[MAXV] = {false};

void BFS(int u) {  // 遍历u所在的连通块
  queue<int> q;
  q.push(u);  // 将初始点u入队
  inQu[u] = true;

  while (!q.empty()) {  // 只要队列非空
    int u = q.front();  // 取出队首元素
    q.pop();

    for (int v = 0; v < n; ++v) {
      // 如果u的邻接点v未曾加入过队列
      if (inQu[v] == false && G[u][v] != INF) {
        q.push(v);
        inQu[v] = true;
      }
    }
  }
}

void BFSTrave() {  // 遍历图G
  for (int u = 0; u < n; ++u) {
    if (inQu[u] == false) {
      BFS(u);
    }
  }
}

/* 邻接表版 */
vector<int> Adj[MAXV];
int n;
// 若顶点i曾入过队列，则inQu[i] == true。初值为false
bool inQu[MAXV] = {false};

void BFS(int u) {
  queue<int> q;
  q.push(u);
  inQu[u] = true;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int i = 0; i < Adj[u].size(); ++i) {
      int v = Adj[u][i];
      if (inQu[v] == false) {
        q.push(v);
        inQu[v] = true;
      }
    }
  }
}

void BFSTrave() {  // 遍历图G
  for (int u = 0; u < n; ++u) {
    if (inQu[u] == false) {
      BFS(u);
    }
  }
}

/* 输出顶点所在层号，以邻接表为例 */
/*根据层号的传递关系，如果当前顶点层号为L,那么它所有出边的终点层号都为L+1*/
typedef struct Node {
  int v;
  int layer;
} Node;

vector<Node> Adj[MAXV];

void BFS(int s) {  // s为起始顶点编号
  queue<Node> q;
  Node start;  // 起始顶点
  start.v = s;
  start.layer = 0;
  q.push(start);  // 将起始顶点压入队列
  inQu[start.v] = true;

  while (!q.empty()) {
    Node topNode = q.front();  // 取出队首顶点
    q.pop();
    int u = topNode.v;  // 队首顶点编号

    for (int i = 0; i < Adj[u].size(); ++i) {
      Node next = Adj[u][i];  // 从u出发能到达的顶点next
      // next层号等于当前顶点层号加1
      next.layer = topNode.layer + 1;

      // 如果next的编号未被加入过队列
      if (inQu[next.v] == false) {
        q.push(next);
        inQu[next.v] = true;
      }
    }
  }
}
