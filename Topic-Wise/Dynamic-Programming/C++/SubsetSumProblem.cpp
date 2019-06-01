/* 
    Problem:    https://practice.geeksforgeeks.org/problems/subset-sum-problem/0
    Editorial:  https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
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
    if(sum%2){
        cout<<"NO"<<endl;
        return;
    }
    sort(arr, arr+n);
    int m = sum/2;
    bool dp[n+1][m+1];
    memset(dp, false, sizeof(dp));
    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j){
            if(!j)
                dp[i][j] = true;
            else if(!i)
                dp[i][j] = false;
            else if(arr[i-1]>j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j - arr[i-1]];
        }
    }
    if(dp[n][m])
        cout<<"YES"<<endl;
    else 
        cout<<"NO"<<endl;
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