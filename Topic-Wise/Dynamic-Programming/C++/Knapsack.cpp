/* 
    Problem:    https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
    Editorial:  https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

int _dp[1001][1001];


void solve(){
    int n, W;
    cin>>n>>W;
    int val[n], wt[n];
    
    for(int i=0;i<n;++i)
        cin>>val[i];    // Taking values
        
    for(int i=0;i<n;++i)
        cin>>wt[i];     // Taking weights
        
    int dp[n+1][W+1];
    memset(dp, 0, sizeof(dp));
    for(int i=1;i<=n;++i){
        for(int j=1;j<=W;++j){
            if(wt[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - wt[i-1]] + val[i-1]);
        }
    }
    cout<<dp[n][W]<<endl;
}

int knapsack(int val[], int wt[], int n, int W){
    if(!n || !W)
        return 0;
    if(_dp[n][W]!=-1)
        return _dp[n][W];
    if(wt[n-1]>W)
        _dp[n][W] = knapsack(val, wt, n-1, W);
    else
        _dp[n][W] = max(knapsack(val, wt, n-1, W), knapsack(val, wt, n-1, W-wt[n-1]) + val[n-1]);
    return _dp[n][W];
}

void _solve(){
    int n, W;
    cin>>n>>W;
    int val[n], wt[n];
    for(int i=0;i<n;++i)
        cin>>val[i];
    for(int i=0;i<n;++i)
        cin>>wt[i];
    int dp[n+1][W+1];
    memset(_dp, -1, sizeof(dp));
    cout<<knapsack(val, wt, n, W)<<endl;
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