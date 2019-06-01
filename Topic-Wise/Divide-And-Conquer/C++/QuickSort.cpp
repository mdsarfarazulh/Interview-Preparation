/* 
    Problem:    https://practice.geeksforgeeks.org/problems/quick-sort/1
    Editorial:  https://www.geeksforgeeks.org/quick-sort/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

int partition(int arr[], int l, int r){
    int key = r;
    int pivot = l-1;
    for(int i=l;i<r;++i){
        if(arr[i]<=arr[key])
            swap(arr[++pivot], arr[i]);
    }
    swap(arr[key], arr[++pivot]);
    return pivot;
}

void quickSort(int arr[], int l, int r){
    if(l<r){
        int pivot = partition(arr, l, r);
        quickSort(arr, l, pivot-1);
        quickSort(arr, pivot+1, r);
    }
}

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i)
        cin>>arr[i];
    quickSort(arr, 0, n-1);
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