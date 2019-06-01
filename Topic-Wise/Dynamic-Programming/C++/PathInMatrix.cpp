/* 
    Problem:    https://practice.geeksforgeeks.org/problems/path-in-matrix/0
    Editorial:  https://www.geeksforgeeks.org/maximum-path-sum-matrix/
*/ 
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

int dr[] = {1, 1, 1};
int dc[] = {0, -1, 1};

void solve(){
    int n;
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            cin>>arr[i][j];
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    int r, c;
    for(int i=0;i<n-1;++i){
        for(int j=0;j<n;++j){
            if(!i)
                dp[i][j] = arr[i][j];
            for(int k=0;k<3;++k){
                r = i + dr[k];
                c = j + dc[k];
                if(r<n && c<n && c>=0){
                    dp[r][c] = max(dp[r][c], dp[i][j] + arr[r][c]);
                }
            }
        }
    }
    int ans = 0;
    for(int j=0;j<n;++j)
        ans = max(ans, dp[n-1][j]);
    cout<<ans<<endl;
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