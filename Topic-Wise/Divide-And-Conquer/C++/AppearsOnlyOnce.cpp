/* 
    Problem:    https://practice.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array/0
    Editorial:  https://www.geeksforgeeks.org/find-the-element-that-appears-once-in-a-sorted-array/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

int bin_search(int arr[], int l, int r){
    if(l==r)
        return arr[l];
    if(l<r){
        int m = l + (r-l)/2;
        if(m%2){
            if(arr[m] ==arr[m-1])
                l = m + 1;
            else
                r = m - 1;
        }else{
            if(arr[m] == arr[m+1])
                l = m + 2;
            else
                r = m;
        }
        return bin_search(arr, l, r);
    }
}

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i)
        cin>>arr[i];
    for(int i=0;i<n;i+=2){
        if((i+1)==n || arr[i]!=arr[i+1]){
            cout<<arr[i]<<endl;
            return;
        }
    }
}

void _solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i)
        cin>>arr[i];
    cout<<bin_search(arr, 0, n-1)<<endl;
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