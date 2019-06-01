/* 
    Problem:    https://practice.geeksforgeeks.org/problems/merge-sort/1
    Editorial:  https://www.geeksforgeeks.org/merge-sort/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int
void merge(int arr[], int l, int m, int r){
    int sz = r-l+1;
    int m_arr[sz];
    int _l = l;
    int _r = m+1;
    int i = 0;
    while(_l<=m && _r<=r){
        if(arr[_l]<arr[_r])
            m_arr[i++] = arr[_l++];
        else
            m_arr[i++] = arr[_r++];
    }
    while(_l<=m)
        m_arr[i++] = arr[_l++];
    while(_r<=r)
        m_arr[i++] = arr[_r++];
    for(int j=l;j<=r;++j){
        arr[j] = m_arr[j-l];
    }
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int m = l + (r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i)
        cin>>arr[i];
    mergeSort(arr, 0, n-1);
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
    while(tcases--)
        solve();
    return 0;
}