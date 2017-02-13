#include <bits/stdc++.h>
using namespace std;
#define I int
#define L long
#define LL long long
#define M 1 << 28

I mat[1010][1010];
I next[1010][1010];

void prIPath(I i,I j){
    if(i != j)
        prIPath(i,next[i][j]);
    printf(" %d",j);
}

I main(){
   // freopen("in.txt", "r", stdin);
    I n,e;
    while(cin >> n >> e){
        for(I i = 1; i <= n; i++)
            for(I j = 1; j <= n; j++)
                mat[i][j] = M;          //Initilize Matrix with infinity value
        for(I i = 0; i <= n; i++)
            for(I j = 0; j <= n; j++)
                next[i][j] = i;         //Initilize Parent value
        for(I i = 1; i <= e; i++){
            I u,v,x;
            cin >> u >> v >> x;
            mat[u][u] = 0;              //same node costs 0
            mat[v][v] = 0;
            mat[u][v] = x;
        }
        //Floyed Warshall...
        for(I k = 1; k <= n; k++)
            for(I i = 1; i <= n; i++)
                for(I j = 1; j <= n; j++)
                    if(mat[i][j] > (mat[i][k]+mat[k][j])){
                        mat[i][j] = (mat[i][k]+mat[k][j]);
                        next[i][j] = next[k][j];
                    }
        //Floyed Warshall Ends...
        prIPath(4,1);               //recursive function to print path
        cout << "\nCost Of 4 To 1 is = " << mat[4][1] << endl;
    }
    return 0;
}
