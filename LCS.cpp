#include <iostream>
#include <cstdio>
#include <cstring>
#include <math.h>
using namespace std;

int c[1010][1010];

int LCSL (char X[], char Y[]){
    int i = 0,j = 0;
    int m,n;

    m = strlen(X);
    n = strlen(Y);

    for(i = 1; i  < m; i++)
        c[i][0] = 0;

    for(j = 0; j < n; j++)
        c[0][j] = 0;

    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++){
            if(X[i-1] == Y[j-1])
                c[i][j] = c[i-1][j-1]+1;
            else if(c[i-1][j] >= c[i][j-1])
                c[i][j] = c[i-1][j];
            else
                c[i][j] = c[i][j-1];
        }
        return c[m][n];
}

int main()
{
    int k,l;
    char X[1010], Y[1010];
    printf("Enter Two string\n");

    //freopen("e:/in.txt","r",stdin);
    while(gets(X))
    {
        gets(Y);
        //cout<<"a = "<<a<<endl;
        //cout<<"b = "<<b<<endl<<endl;

        int ans = LCSL(X,Y);

        cout<<"LCSL = "<<ans<<endl;
        printf("\nEnter Two string to continue\nCNTR+Z to exit\n");

    }
    return 0;
}

