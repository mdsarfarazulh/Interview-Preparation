/* 
    Problem:    https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
    Editorial:  https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    int n, m;
    string a, b;
    cin>>n>>m;
    cin>>a>>b;
    int dp[n+1][m+1];

    for(int i=0;i<=m;++i)
        dp[0][i] = 0;
    for(int i=0;i<=n;++i)
        dp[i][0] = 0;
    
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i-1]==b[j-1])
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout<<dp[n][m]<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tcases;
    cin>>tcases;
    while(tcases--){
        solve();
    }
    return 0;
}