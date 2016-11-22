#include <bits/stdc++.h>
using namespace std;

string clr[100];
int d[100];
int par[100];
int ftime[100];
int n;
int time1;
vector <int> Gv[100];

void DFSVisit(int);

void DFS(){
    for(int i = 0; i <= n; i++){
        clr[i] = "White";
        par[i] = -1;
    }
    time1 = 0;
    for(int i = 1; i < n; i++){
        if(clr[i] == "White"){
            DFSVisit(i);
        }
    }
}

void DFSVisit(int u){
    cout << "In Stack = " << u << endl;
    time1++;
    d[u] = time1;
    clr[u] = "Gray";
    for(int x = 0; x < Gv[u].size(); x++){
            int v = Gv[u][x];
            if(clr[v] == "White"){
                par[v] = u;
                DFSVisit(v);
            }
        }
    clr[u] = "Black";
    time1++;
    ftime[u] = time1;
}

int main(){
    freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i++){
        int u,v;
        cin >> u >> v;
        Gv[v].push_back(u);
        Gv[u].push_back(v);
    }
    time1 = 0;
    DFS();
    return 0;
}

