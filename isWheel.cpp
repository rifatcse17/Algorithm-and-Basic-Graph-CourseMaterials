#include <bits/stdc++.h>
using namespace std;

int  ar[100];
int n;

bool isNull(){
    bool ck =false;
    for(int i = 0; i < n; i++)
        if(ar[i] > 0)
            ck = true;
    if(ck == true)
            return true;
    else
        return false;
}

bool isComplete(){
    bool ck = true;
    for(int i = 0; i < n; i++)
        if(ar[i] != n-1)
            ck = false;

     if(ck == true)
            return true;
    else
        return false;
}

bool isCycle(){
    bool ck = true;

     for(int i = 0; i < n; i++)
        if(ar[i] != 2)
            ck = false;

     if(ck == true)
            return true;
    else
        return false;
}

bool isWheel(){
    bool ck = false;
    int indx = -1;
    for(int i = 0; i < n; i++){
        if(ar[i] == n-1){
            ck = true;
            indx = i;
        }
    }

    if(ck){
   // cout << "indx = " << indx << endl;
    int chk = 0;
    for(int i = 0; i < n; i++){
            if(ck == true && i == indx){
                if(ar[i] == n-1);
                    chk++;
            }
            else{
                if(ar[i] == 3)
                    chk++;
            }
    }

    if(chk == n)
        return true;
    else
        return false;
    }

    else
        return false;
}

int main(){
   freopen("in.txt", "r", stdin);
    while(scanf("%d", &n)==1){
            for(int i = 0; i < n; i++){
                    int sum = 0;
                    for(int j = 0; j < n; j++){
                        int x;
                        cin >> x;
                        if(x >= 1)
                            sum++;
                    }
                    ar[i] =sum;
            }
            if(isNull())
                cout << "Input Graph Is Not Null\n";
            else
                 cout << "Input Graph Is Null\n";

            if(isComplete())
                cout << "Input Graph Is Complete\n";
            else
                 cout << "Input Graph Is Not Complete\n";

            if(isCycle())
                cout << "Input Graph Is Cycle\n";
            else
                 cout << "Input Graph Is Not Cycle\n";

            if(isWheel())
                cout << "Input Graph Is A Wheel\n";
            else
                 cout << "Input Graph Is Not Wheel\n";
    }
    return 0;
}
