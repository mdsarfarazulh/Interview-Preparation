/* 
    Problem:    https://practice.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array/0
    Editorial:  https://www.geeksforgeeks.org/find-the-element-that-appears-once-in-a-sorted-array/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){   // 0.01 Sec
    int n;
    cin>>n;
    vector<LL> arr(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    for(int i=1;i<n;i+=2){
        if(arr[i]!=arr[i-1]){
            cout<<arr[i-1]<<endl;
            return;
        }
    }
    cout<<arr[n-1]<<endl;
}

void _solve(){  // 0.01 Sec
    int n;
    cin>>n;
    vector<LL> arr(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    
    LL ans = arr[0];
    for(int i=1;i<n;++i)
        ans = ans^arr[i];
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
}