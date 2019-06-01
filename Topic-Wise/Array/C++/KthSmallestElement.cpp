/* 
    Problem:    https://practice.geeksforgeeks.org/problems/kth-smallest-element/0
    Editorial:  https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/
*/

#include<bits/stdc++.h>
using namespace std;

void maxHeapify(vector<int> &arr, int n, int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && arr[largest]<arr[l])
        largest = l;
    if(r<n && arr[largest]<arr[r])
        largest = r;
    if(largest!=i){
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void minHeapify(vector<int> &arr, int n, int i){
    int smallest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && arr[smallest]>arr[l])
        smallest = l;
    if(r<n && arr[smallest]>arr[r])
        smallest = r;
    if(smallest!=i){
        swap(arr[smallest], arr[i]);
        minHeapify(arr, n, smallest);
    }
}

void solve(){
    // Using Min Heap
    int n, k;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    cin>>k;
    for(int i = n/2 - 1; i >= 0; --i)
        minHeapify(arr, n, i);

    for(int i = n - 1, j = 0; i >= 0, j<k; --i,++j){
        swap(arr[i], arr[0]);
        minHeapify(arr, i, 0);
    }
    cout<<arr[n-k]<<endl;
}

void _solve(){
    int n, k;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    cin>>k;

    for(int i=k/2-1; i>=0; --i)
        maxHeapify(arr, k, i);
    
    for(int i=k;i<n;++i){
        if(arr[i]<arr[0]){
            swap(arr[i], arr[0]);
            maxHeapify(arr, k, 0);
        }
    }
    cout<<arr[0]<<endl;
}

int partition(vector<int> &arr, int l, int r){
    int pivot = rand()%(r-l) + l;
    swap(arr[pivot], arr[r]);

    pivot = l-1;
    for(int i=l;i<r;++i){
        if(arr[i]<=arr[r]){
            ++pivot;
            swap(arr[i], arr[pivot]);
        }
    }
    ++pivot;
    swap(arr[r], arr[pivot]);
    return pivot;
}


void randomizedQuickSelect(vector<int> &arr, int l, int r, int k){
    if(l<r){
        int pivot = partition(arr, l, r);
        if(k==pivot+1){
            cout<<arr[pivot]<<endl;
            return;
        }
        else if(k<=pivot)
            randomizedQuickSelect(arr, l, pivot-1, k);
        else{
            randomizedQuickSelect(arr, pivot+1, r, k);
        }
    }
}

void __solve(){
    int n, k;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    
    cin>>k;
    randomizedQuickSelect(arr, 0, n, k);
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tcases;
    cin>>tcases;
    while(tcases--){
        __solve();
    }
}