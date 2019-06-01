/* 
    Problem:    https://practice.geeksforgeeks.org/problems/longest-common-substring/0
    Editorial:  https://www.geeksforgeeks.org/longest-common-substring-dp-29/
*/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin>>n>>m;
    string a, b;
    cin>>a>>b;
    int ans = 0;
    int i, j, k, l;
    for(i=0;i<n;++i){
        for(j=0;j<m;++j){
            l = j;
            k = i;
            while(k<n && l<m && a[k]==b[l]){
                l++;
                k++;
            }
            ans = max(ans, k-i);
        }
    }
    cout<<ans<<endl;
}

void _solve(){
    int n, m;
    cin>>n>>m;
    string a, b;
    cin>>a>>b;
    int ans = 0;
    int dp[n+1][m+1];
    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j){
            if(!i || !j)
                dp[i][j] = 0;
            else{
                if(a[i-1]==b[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    ans = max(ans, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
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
    while(tcases--){
        _solve();
    }
    return 0;
}