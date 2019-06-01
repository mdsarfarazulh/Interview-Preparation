/* 
    Problem:    https://practice.geeksforgeeks.org/problems/minimum-sum-partition/0
    Editorial:  https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/
*/ 
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    int n;
    cin>>n;
    int arr[n];
    int sum = 0;
    for(int i=0;i<n;++i)
        cin>>arr[i], sum += arr[i];
    bool dp[n + 1][sum + 1];
    for(int i=0;i<=n;++i){
        for(int j=0;j<=sum;++j){
            if(!j)
                dp[i][j] = true;
            else if(!i)
                dp[i][j] = false;
            else{
                dp[i][j] = dp[i-1][j];
                if(arr[i-1]<=j){
                    dp[i][j] |= dp[i-1][j-arr[i-1]];
                }
            }
        }
    }

    int ans = INT_MAX;
    for(int i=sum/2;i>=0;--i){
        if(dp[n][i]){
            ans = sum - 2*i;
            break;
        }
    }
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