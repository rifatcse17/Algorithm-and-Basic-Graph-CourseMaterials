#include <bits/stdc++.h>
using namespace std;

string clr[100];
int d[100];
int par[100];
int finishTime[100];
int n;
int time1;
vector <int> Gv[100];

void DFS();
void DFSVisit(int);
void topSort();

struct sortNode{
    int node;
    int _time;
};

bool cmp(sortNode a, sortNode b){
    return a._time < b._time;
}

vector <sortNode> vN;


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
    //cout << "In Stack = " << u << endl;
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
    finishTime[u] = time1;
    sortNode sN;
    sN.node = u;
    sN._time = finishTime[u];
    vN.push_back(sN);
    //cout << "Finish Time Of " << u << " = " << finishTime[u] << endl;
}

void topSort(){
    DFS();
    sort(vN.begin(), vN.end(), cmp);
    for(int i = 0; i < n; i++){
        cout << "node = " << vN[i].node << " , Time = " << vN[i]._time << endl;
    }
    vN.clear();
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
    topSort();
    Gv[100].clear();
    vN.clear();
    return 0;
}


