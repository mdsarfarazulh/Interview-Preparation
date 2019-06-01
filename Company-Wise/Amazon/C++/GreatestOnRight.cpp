/*
    Problem:    https://practice.geeksforgeeks.org/problems/greater-on-right-side/0
    Editorial:  https://www.geeksforgeeks.org/replace-every-element-with-the-greatest-on-right-side/
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
    int curr = -1;
    for(int i=n-1;i>=0;--i){
        if(arr[i]>curr)
            swap(curr, arr[i]);
        else 
            arr[i] = curr;
    }
    for(int v: arr)
        cout<<v<<" ";
    cout<<endl;
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