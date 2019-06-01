/* 
    Problem:    https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0
    Editorial:  https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    string str;
    cin>>str;

    int n = str.size();
    vector<vector<bool> > dp(n, vector<bool>(n));
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            dp[i][j] = false;
    for(int i=0;i<n;++i)
        dp[i][i] = true;

    int start, ans = 0;
    for(int i=0;i<n-1;++i){
        int j = i+1;
        if(str[i]==str[j]){
            dp[i][j] = true;
            if(!ans){
                ans = 2;
                start = i;
            }
        }
    }
    for(int k=3;k<=n;++k){
        for(int i=0;i<n-k+1;++i){
            int j = i+k-1;
            if(dp[i+1][j-1] && str[i]==str[j]){
                dp[i][j] = true;
                if(k>ans){
                    ans = k;
                    start = i;
                }
            }
        }
    }
    if(!ans){
        cout<<str[0]<<endl;
    }else{
        for(int i=start;i<=start+ans-1;++i)
            cout<<str[i];
        cout<<endl;
    }
    
    
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