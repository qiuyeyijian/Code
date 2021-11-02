#include <math.h>
#include <stdio.h>

#include <vector>

using namespace std;

/**
 * DFS(u) {   // 访问顶点u
 *  vis[u] = true;      // 设置u已被访问
 *  for(从u出发能到达的所有顶点 v)
 *      if(vis[v] == false)
 *          DFS(v)
 * }
 *
 * DFSTrave(G) {
 *    for(G的所有顶点 u)
 *      if(vis[u] == false)
 *          DFS(u);
 * }
 *
 */
/* 邻接矩阵版 */
const int MAXV = 1000;  // 最大顶点数
const int INF = 65535;

int n, G[MAXV][MAXV];  // n为顶点数，MAXV为最大顶点数
// 如果顶点i已被访问，则vis[i] == true。 初值为false
bool vis[MAXV] = {false};

// u为当前访问顶点标号，depth为深度
void DFS(int u, int depth) {
  vis[u] = true;  // 设置u已被访问
  // 如果需要对u进行一些操作，可以在这里进行
  // 下面对所有从u出发能到达的分支顶点进行枚举
  for (int v = 0; v < n; ++v) {
    // 如果v未被访问，且u可到达v
    if (vis[n] == false && G[u][v] != INF) {
      DFS(v, depth + 1);  // 访问v，深度加1
    }
  }
}

void DFSTrave() {
  for (int u = 0; u < n; ++u) {  // 对每个顶点u
    if (vis[u] == false) {       // 如果u未被访问
      DFS(u, 1);
    }
  }
}

/* 邻接表版 */
vector<int> Adj[MAXV];

int n;  // n为顶点数，MAXV为最大顶点数
bool vis[MAXV] = {false};

void DFS(int u, int depth) {
  vis[u] = true;

  for (int i = 0; i < Adj[u].size(); ++i) {
    int v = Adj[u][i];

    if (vis[v] == false) {
      DFS(v, depth + 1);
    }
  }
}

void DFSTrave() {
  for (int u = 0; u < n; ++u) {
    if (vis[u] == false) {
      DFS(u, 1);
    }
  }
}