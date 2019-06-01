/* 
    Problem:    https://practice.geeksforgeeks.org/problems/cutted-segments/0
    Editorial:  https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    int n, k = 3;
    cin>>n;
    int arr[k];
    for(int i=0;i<k;++i)
        cin>>arr[i];
    sort(arr, arr+k);
    int dp[k+1][n+1];
    for(int i=0;i<=k;++i){
        for(int j=0;j<=n;++j){
            if(!j)
                dp[i][j] = 0;
            else if(!i)
                dp[i][j] = -1;
            else if(arr[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else{
                if(dp[i][j-arr[i-1]] == -1)
                    dp[i][j] = dp[i-1][j];
                else 
                    dp[i][j] = max(dp[i][j - arr[i-1]] + 1, dp[i-1][j]);
            }
        }
    }
    cout<<dp[k][n]<<endl;
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