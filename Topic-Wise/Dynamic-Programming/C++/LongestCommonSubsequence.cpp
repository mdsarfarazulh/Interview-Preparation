/* 
    Problem:    https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0
    Editorial:  https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    int _a, _b;
    cin>>_a>>_b;
    string a, b;
    cin>>a>>b;
    vector<vector<int> > dp(_a + 1, vector<int>(_b + 1));
    for(int i=0;i<=_a;++i){
        for(int j=0;j<=_b;++j){
            if(!i || !j)
                dp[i][j] = 0;
            else{
                dp[i][j] = 0;
                if(a[i-1] == b[j-1]){
                    dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
    }
    cout<<dp[_a][_b]<<endl;
}

int LCS(string &a, string &b, vector<vector<int> > &dp, int _a, int _b){
    if(_a<=0 || _b<=0)
        return 0;
    if(dp[_a][_b]!=-1)
        return dp[_a][_b];
    if(a[_a - 1] == b[_b - 1])
        dp[_a][_b] = LCS(a, b, dp, _a-1, _b-1) + 1;
    else
        dp[_a][_b] = max(LCS(a, b, dp, _a-1, _b), LCS(a, b, dp, _a, _b-1));
    return dp[_a][_b];
}

void _solve(){
    int _a, _b;
    cin>>_a>>_b;
    string a, b;
    cin>>a>>b;
    vector<vector<int> > dp(_a + 1, vector<int>(_b + 1, -1));
    
    cout<<LCS(a, b, dp, _a, _b)<<endl;
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