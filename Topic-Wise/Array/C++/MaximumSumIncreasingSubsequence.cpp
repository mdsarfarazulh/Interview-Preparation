/* 
    Problem:    https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0
    Editorial:  https://www.geeksforgeeks.org/maximum-sum-increasing-subsequence-dp-14/
*/


#include<bits/stdc++.h>
using namespace std;

#define LL long long int



void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> dp(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    dp[0] = arr[0];
    for(int i=1;i<n;++i){
        dp[i] = arr[i];
        for(int j=0;j<i;++j){
            if(arr[i]>arr[j] && dp[j]+arr[i]>dp[i])
                dp[i] = dp[j]+arr[i];
        }
    }
    int ans = 0;
    for(int i=1;i<n;++i){
        if(dp[ans]<dp[i])
            ans = i;
    }
    cout<<dp[ans]<<endl;
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
}