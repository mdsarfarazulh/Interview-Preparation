/* 
    Problem:    https://practice.geeksforgeeks.org/problems/coin-change/0
    Editorial:  https://www.geeksforgeeks.org/coin-change-dp-7/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    int n, m;
    cin>>m;
    int arr[m];
    for(int i=0;i<m;++i)
        cin>>arr[i];
    cin>>n;
    int dp[m+1][n+1];
    for(int i=0;i<=m;++i){
        for(int j=0;j<=n;++j){
            if(!i)
                dp[i][j] = 0;
            else if(!j)
                dp[i][j] = 1;
            else if(arr[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else 
                dp[i][j] = dp[i-1][j] + dp[i][j - arr[i-1]];
        }
    }
    cout<<dp[m][n]<<endl;
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