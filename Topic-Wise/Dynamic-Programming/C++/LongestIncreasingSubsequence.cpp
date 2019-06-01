/* 
    Problem:    https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0
    Editorial:  https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n), dp(n);
    for(int i=0;i<n;++i)
        cin>>arr[i], dp[i] = 1;
    int ans = 0;
    for(int i=1;i<n;++i){
        for(int j=0;j<i;++j){
            if(arr[i]>arr[j]){
                dp[i] = max(dp[i], dp[j]+1);
                ans = max(ans, dp[i]);
            }
        }
    }
    cout<<ans<<endl;
}

int LIS(vector<int> &arr, vector<int> &dp, int n){
    if(dp[n])
        return dp[n];
    dp[n] = 1;
    int temp;
    for(int i=0;i<n;++i){
        temp = LIS(arr, dp, i);
        if(arr[i]<arr[n] && temp+1 > dp[n])
            dp[n] = temp+1;
    }
    return dp[n];
}
void _solve(){
    int n;
    cin>>n;
    vector<int> arr(n), dp(n, 0);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    dp[0] = 1;
    LIS(arr, dp, n-1);
    int ans = 1;
    for(int i=0;i<n;++i)
        ans = max(ans, dp[i]);
    cout<<ans<<endl;
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