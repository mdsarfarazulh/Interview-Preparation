/* 
    Problem:    https://practice.geeksforgeeks.org/problems/count-number-of-hops/0
    Editorial:  https://www.geeksforgeeks.org/count-number-of-ways-to-cover-a-distance/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

int countHops(int dp[], int n){
    if(n<0)
        return 0;
    if(!n)
        return 1;
    if(dp[n])
        return dp[n];
    dp[n] = countHops(dp, n-1) + countHops(dp, n-2) + countHops(dp, n-3);
    return dp[n];
}

void solve(){
    int n;
    cin>>n;
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    cout<<countHops(dp, n)<<endl;
}

void _solve(){
    int n;
    cin>>n;
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i=1;i<=n;++i)
        for(int j=i-1; j>=i-3 && j>=0; --j)
            dp[i] += dp[j];
    cout<<dp[n]<<endl;
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