#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001

struct edge{
	int u,v,w;
	bool operator < ( const edge& p ) const{
		return w < p.w;
	}
};

int pr[MAXN];
vector<edge>e;
int find(int r)
{
   return (pr[r]==r) ? r:  find(pr[r]);
}
int mst(int n)
{
	sort(e.begin(),e.end());
	for(int i=1;i<=n;i++)pr[i]=i;

	int count=0,s=0;
	for(int i=0;i<(int)e.size();i++)
	{
		int u=find(e[i].u);
		int v=find(e[i].v);
		if(u!=v)
		{
			pr[u]=v;
			count++;
			s+=e[i].w;
			if(count==n-1) break;
		}
	}
	return s;
}

int main(){
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int cs = 1; cs <= t; cs++){
        e.clear();
        int n,m,a, nr = 0,air;
        cin>>n>>m>>a;
        air = abs(n-m);
        if(air == 0)
            air = 1;
        for(int i=1;i<=m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            edge get;
            get.u=u; get.v=v; get.w=w;
            if(w < a)
                e.push_back(get);
            else
                nr++;
        }
        int sub_ans = 0;
        //cout <<"air = " << air << " nr = " << nr <<endl;
        sub_ans += (air*a) + (a*nr);
        int ans = mst(n) + sub_ans;
        cout<<"Case #" << cs << ": " << ans << " " << air <<endl;
    }
	return 0;

}
