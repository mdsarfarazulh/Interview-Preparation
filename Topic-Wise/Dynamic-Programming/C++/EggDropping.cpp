/* 
    Problem:    https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0
    Editorial:  https://www.geeksforgeeks.org/egg-dropping-puzzle-dp-11/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

int eggDrop(vector<vector<int> > dp, int n_egg, int n_floor) { 
    if (n_floor == 1 || n_floor == 0) 
        return n_floor; 

    if (n_egg == 1) 
        return n_floor; 
    if(dp[n_egg][n_floor] != -1)
        return dp[n_egg][n_floor];
    int min = INT_MAX, x, res; 
    for (x = 1; x <= n_floor; x++){ 
        res = max(eggDrop(dp, n_egg-1, x-1), eggDrop(dp, n_egg, n_floor-x)); 
        if (res < min) 
            min = res; 
    } 
    dp[n_egg][n_floor] = min + 1; 
}

void solve(){
    int n_egg, n_floor;
    cin>>n_egg>>n_floor;
    vector<vector<int> > dp(n_egg+1, vector<int>(n_floor+1, -1));
    cout<<eggDrop(dp, n_egg, n_floor)<<endl;
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