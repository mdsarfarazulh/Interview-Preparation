/*
    Problem:    https://practice.geeksforgeeks.org/problems/count-all-possible-paths-from-top-left-to-bottom-right/0
    Editorial:  https://www.geeksforgeeks.org/count-possible-paths-top-left-bottom-right-nxm-matrix/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

const int mod = 1e9 + 7;

void solve(){
    int n, m;
    vector<vector<LL> > dp(n, vector<LL>(m));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(!i || !j)
                dp[i][j] = 1;
            else 
                dp[i][j] = ((dp[i-1][j]%mod) + (dp[i][j-1]%mod))%mod;
        }
    }
    cout<<dp[n-1][m-1]<<endl;
}

void _solve(){
    int n, m;
    cin>>n>>m;
    vector<LL> dp(n, 1);
    for(int i=1;i<m;++i){
        for(int j=1;j<n;++j){
            dp[j] =  (dp[j]%mod + dp[j-1]%mod)%mod;
            dp[j] %= mod;
        }
    }
    cout<<dp[n-1]<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tcases;
    cin>>tcases;
    while(tcases--)
        _solve();
    return 0;
}