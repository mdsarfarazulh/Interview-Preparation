/*
    Problem:    https://practice.geeksforgeeks.org/problems/coin-change/0
    Editorial:  https://www.geeksforgeeks.org/coin-change-dp-7/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    int n;
    cin>>n;
    vector<int> coins(n);
    for(int i=0;i<n;++i)
        cin>>coins[i];
    int w;
    cin>>w;
    sort(coins.begin(), coins.end());
    vector<vector<int> > dp(n+1, vector<int>(w+1));
    for(int i=0;i<=n;++i){
        for(int j=0;j<=w;++j){
            if(!j)
                dp[i][j] = 1;
            else if(!i)
                dp[i][j] = 0;
            else{
                if(coins[i-1]>j){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                }
            }
        }
    }
    cout<<dp[n][w]<<endl;
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