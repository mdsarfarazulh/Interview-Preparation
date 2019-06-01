/* 
    Problem:    https://practice.geeksforgeeks.org/problems/edit-distance/0
    Editorial:  https://www.geeksforgeeks.org/edit-distance-dp-5/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

int editDistance(string a, string b, int _a, int _b){
    if(!_a)
        return _b;
    if(!_b)
        return _a;
    
    if(a[_a]==b[_b])
        return editDistance(a, b, _a-1, _b-1);
    return min(editDistance(a, b, _a-1, _b), min(editDistance(a, b, _a, _b-1), editDistance(a, b, _a-1, _b-1))) + 1;
}

void solve(){
    int _a, _b;
    string a, b;
    cin>>_a>>_b;
    cin>>a>>b;
    int dp[_a+1][_b+1];
    for(int i=0;i<=_a;++i){
        for(int j=0;j<=_b;++j){
            if(!i)
                dp[i][j] = j;
            else if(!j)
                dp[i][j] = i;
            else if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;            
        }
    }
    cout<<dp[_a][_b]<<endl;
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