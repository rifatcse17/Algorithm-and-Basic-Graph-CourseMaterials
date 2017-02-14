#include <bits/stdc++.h>
using namespace std;

#define M 1 << 128
#define I int
#define L long
#define LL long long
#define memSize 10101010

typedef vector <I> vi;
#define UNVISITED -1
#define VISITED 1

vi dfs_low,dfs_num,S,visited,AdjList[memSize];
I dfsNumberCount,numSSC;

void tarjanSSC(I u){        //tarjan's Algorithm
    dfs_low[u] = dfs_num[u] = dfsNumberCount++;
    S.push_back(u);
    visited[u] = VISITED;
    for(I j = 0; j < (int)AdjList[u].size(); j++){
        I v = AdjList[u][j];
        if(dfs_num[v] == UNVISITED)
            tarjanSSC(v);
        if(visited[v])
            dfs_low[u] = min(dfs_low[u],dfs_low[v]);
    }
    if(dfs_low[u] == dfs_num[u]){
        printf("SSC %d :", ++numSSC);
        while(1){
            I v = S.back();
            S.pop_back();
            visited[v] = 0;
            printf(" %d",v);
            if(u == v)
                break;
        }
        printf("\n");
    }
}

int main(){
    freopen("in.txt", "r", stdin);
    I V,E;   //V-> vertex, E-> Edge
    while(cin >> V >> E){
        for(I i = 0; i < E; i++){
            I u,v;
            cin >> u >> v;
            AdjList[u].push_back(v);
        }
        dfs_num.assign(V,UNVISITED);
        dfs_low.assign(V,0);
        visited.assign(V,0);
        dfsNumberCount = numSSC = 0;
        for(I i = 0; i < V; i++)
            if(dfs_num[i] == UNVISITED)
                tarjanSSC(i);
    }
    return 0;
}

/* Input

8 9
0 1
1 3
3 2
2 1
3 4
4 5
5 7
7 6
6 4

*/



