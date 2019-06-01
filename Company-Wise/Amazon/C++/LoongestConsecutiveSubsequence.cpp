/*
    Problem:    https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence/0
    Editorial:  https://www.geeksforgeeks.org/longest-consecutive-subsequence/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    int n;
    cin>>n;
    int temp;
    vector<bool> hash(100005, false);
    int _max = 0;
    for(int i=0;i<n;++i){
        cin>>temp; 
        _max = max(_max, temp);
        hash[temp] = true; 
    }
    int ans = 0;
    temp = 0;
    for(int i=0;i<=_max;++i){
        if(hash[i])
            ++temp;
        else 
            ans = max(ans, temp), temp = 0;
    }
    ans = max(ans, temp);
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