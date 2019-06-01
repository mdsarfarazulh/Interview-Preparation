/* 
    Problem:    https://practice.geeksforgeeks.org/problems/binary-search/1
    Editorial:  https://www.geeksforgeeks.org/binary-search/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

int bin_search(int arr[], int left, int right, int k){
    if(left<=right){
        int m = left + (right - left)/2;
        if(arr[m] == k)
            return m;
        if(arr[m]<k)
            return bin_search(arr, m+1, right, k);
        return bin_search(arr, left, m-1, k);
    }
    return -1;
}

void solve(){
    int n, k;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i)
        cin>>arr[i];
    cin>>k;
    cout<<bin_search(arr, 0, n-1, k)<<endl;
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