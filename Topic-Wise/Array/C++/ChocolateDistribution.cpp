/* 
    Problem:    https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem/0
    Editorial:  https://www.geeksforgeeks.org/chocolate-distribution-problem/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    int n, m;
    cin>>n;
    vector<LL> arr(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    
    cin>>m;
    sort(arr.begin(), arr.end());
    LL ans = LONG_MAX;
    for(int i=0;i+m-1<n;++i)
        if((arr[i+m-1]-arr[i])<ans)
            ans = arr[i+m-1] - arr[i];
    cout<<ans<<endl;
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
    return 0;
}