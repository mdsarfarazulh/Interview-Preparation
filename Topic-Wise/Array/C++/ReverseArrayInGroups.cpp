/* 
    Problem:    https://practice.geeksforgeeks.org/problems/reverse-array-in-groups/0
    Editorial:  https://www.geeksforgeeks.org/reverse-an-array-in-groups-of-given-size/
*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    int n, k;
    cin>>n>>k;
    vector<LL> arr(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    int prev;
    for(int i=0;i<n;){
        prev = (i+k-1)>=n?n-1:(i+k-1);
        for(int j=prev;j>i;--j, ++i)
            swap(arr[i], arr[j]);
        i = prev+1;
    }
    for(int i=0;i<n;++i)
        cout<<arr[i]<<" ";
    cout<<endl;
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
