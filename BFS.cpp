#include <bits/stdc++.h>
using namespace std;

string clr[100];
int d[100];
int par[100];
int n;
vector <int> Gv[100];

void BFS(int s){
    for(int i = 0; i < n; i++){
        clr[i] = "White";
        d[i] = 0;
        par[i] = 0;
    }
    clr[s] = "Gray";
    d[s] = 0;
    par[s] = -1;
    queue <int> q;
    q.push(s);

    while(!q.empty()){
        int v,u = q.front();
        q.pop();
        cout << "In Queue = " << u << endl;
        for(int x = 0; x < Gv[u].size(); x++){
            v = Gv[u][x];
            if(clr[v] == "White"){
                clr[v] = "Gray";
                d[v] = d[u]+1;
                par[v] = u;
                q.push(v);
            }
        }
        clr[u] = "Black";
    }
}

int main(){
    //freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i++){
        int u,v;
        cin >> u >> v;
        Gv[v].push_back(u);
        Gv[u].push_back(v);
    }
    int startNode;
    cin >> startNode;
    BFS(startNode);
    return 0;
}
