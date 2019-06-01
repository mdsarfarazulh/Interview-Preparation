/*
    Problem:    https://practice.geeksforgeeks.org/problems/minimum-difference-pair/0
    Editorial:  https://www.geeksforgeeks.org/find-minimum-difference-pair/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    sort(arr.begin(), arr.end());
    int ans = INT_MAX;
    for(int i=0;i<n-1;++i){
        if(arr[i+1] - arr[i] < ans)
            ans = arr[i+1] - arr[i];
    }
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