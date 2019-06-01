/*
    Editorial:  https://www.geeksforgeeks.org/find-k-closest-numbers-in-an-unsorted-array/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int
struct node{
    int num, diff;
};

void heapify(vector<node> &heap, int n, int i){
    int largest = i;
    int left = 2*largest+1;
    int right = left + 1;

    if(left<n && heap[largest].diff < heap[left].diff)
        largest = left;
    if(right<n && heap[largest].diff < heap[right].diff)
        largest = right;
    if(largest != i){
        swap(heap[largest], heap[i]);
        heapify(heap, n, largest);
    }
}

void solve(){
    int n, x, k;
    cin>>n>>x>>k;
    vector<int> arr(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    vector<node> heap(k);
    for(int i=0;i<k;++i){
        heap[i].diff = abs(arr[i]-x);
        heap[i].num = arr[i];
    }

    for(int i=k/2-1;i>=0;--i)
        heapify(heap, k, i);
    int temp;
    for(int i=k;i<n;++i){
        temp = abs(arr[i]-x);
        if(heap[0].diff > temp){
            heap[0].num = arr[i];
            heap[0].diff = temp;
            heapify(heap, k, 0);
        }
    }

    for(int i=0;i<k;++i)
        cout<<heap[i].num<<" ";
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