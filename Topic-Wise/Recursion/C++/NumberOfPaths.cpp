/*
    Problem:    https://practice.geeksforgeeks.org/problems/number-of-paths/0
    Editorial:  https://www.geeksforgeeks.org/count-possible-paths-top-left-bottom-right-nxm-matrix/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

int numOfPaths(int n, int m){
    if(n<= 0 || m<=0)
        return 0;
    if(n==1 || m==1)
        return 1;
    return numOfPaths(n-1, m) + numOfPaths(n, m-1);
}

void solve(){
    int n, m;
    cin>>n>>m;
    cout<<numOfPaths(n, m)<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tcases;
    cin>>tcases;
    while(tcases--)
        solve();
    return 0;
}