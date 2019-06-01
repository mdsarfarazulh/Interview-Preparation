/* 
    Problem:    https://practice.geeksforgeeks.org/problems/shortest-common-supersequence/0
    Editorial:  https://www.geeksforgeeks.org/shortest-common-supersequence/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    string a, b;
    cin>>a>>b;
    int dp[a.size()+1][b.size()+1];
    for(int i=0;i<=a.size();++i){
        for(int j=0;j<=b.size();++j){
            if(!i || !j)
                dp[i][j] = 0;
            else if(a[i-1]==b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout<<(a.size()+b.size()-dp[a.size()][b.size()])<<endl;
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