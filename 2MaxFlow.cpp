#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

#define MAX_V 40
#define INF 1000000000
#define I int
#define L long
#define LL long long
#define M 1 << 28

typedef vector<I> vi;

I res[MAX_V][MAX_V], mf, f, s, t;
vi p;

void augment(I v, I minEdge) {
  if (v == s) { f = minEdge; return; }
  else if (p[v] != -1) {
      augment(p[v], min(minEdge, res[p[v]][v]));
      res[p[v]][v] -= f; res[v][p[v]] += f; }
}

I main() {
  I V, k, vertex, weight;
  scanf("%d %d %d", &V, &s, &t);  //V->vertex, s->sources, t->Destination

  memset(res, 0, sizeof res);
  for (I i = 0; i < V; i++) {
    scanf("%d", &k);
    for (I j = 0; j < k; j++) {
      scanf("%d %d", &vertex, &weight);
      res[i][vertex] = weight;
    }
  }

  mf = 0;
  while (1) {
    f = 0;
    // BFS
    vi dist(MAX_V, INF); dist[s] = 0; queue<I> q; q.push(s);
    p.assign(MAX_V, -1);
    while (!q.empty()) {
      I u = q.front(); q.pop();
      if (u == t) break;
      for (I v = 0; v < MAX_V; v++)
        if (res[u][v] > 0 && dist[v] == INF)
          dist[v] = dist[u] + 1, q.push(v), p[v] = u;
    }
    augment(t, INF);
    if (f == 0) break;
    mf += f;
  }
  printf("%d\n", mf);
  return 0;
}
