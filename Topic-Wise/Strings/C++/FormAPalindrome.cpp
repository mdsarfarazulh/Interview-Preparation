/*
    Problem:    https://practice.geeksforgeeks.org/problems/form-a-palindrome/0
    Editorial:  https://www.geeksforgeeks.org/minimum-insertions-to-form-a-palindrome-dp-28/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

int findMinInsertion(string str, int l, int r, vector<vector<int> > &dp){
    if(l>r)
        return INT_MAX;
    if(dp[l][r])
        return dp[l][r];
    if(l==r)
        dp[l][r] = 0;
    else if(l==(r-1))
        dp[l][r] = (str[l]==str[r])?0:1;
    else{
        if(str[l]==str[r])
            dp[l][r] = findMinInsertion(str, l+1, r-1, dp);
        else
            dp[l][r] = min(findMinInsertion(str, l+1, r, dp), findMinInsertion(str, l, r-1, dp)) + 1;
    }
    return dp[l][r];
}

void solve(){
    string str;
    cin>>str;
    vector<vector<int> > dp(str.size(), vector<int>(str.size()));
    for(int i=0;i<str.size();++i)
        for(int j=0;j<str.size();++j)
            dp[i][j] = 0;
    cout<<findMinInsertion(str, 0, str.size()-1, dp)<<endl;
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