/*
    Problem:    https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream/0
    Editorial:  https://www.geeksforgeeks.org/kth-largest-element-in-a-stream/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void heapify(vector<int> &heap, int n, int i){
    int smallest = i;
    int left = 2*i+1;
    int right = 2*right + 2;
    if(left<n && heap[left]<heap[smallest])
        smallest = left;
    if(right<n && heap[right]<heap[smallest])
        smallest = right;
    if(smallest != i){
        swap(heap[i], heap[smallest]);
        heapify(heap, n, smallest);
    }
}

void solve(){
    int k, n;
    cin>>k>>n;
    int temp;
    vector<int> heap(k);
    for(int i=0;i<k-1;++i){
        cin>>heap[i];
        cout<<-1<<" ";
    }
    cin>>temp;
    heap[k-1] = temp;
    for(int i=k/2-1;i>=0;--i)
        heapify(heap, k, i);
    cout<<heap[0]<<" ";

    for(int i=k;i<n;++i){
        cin>>temp;
        if(temp>heap[0]){
            heap[0] = temp;
            heapify(heap, k, 0);
        }
        cout<<heap[0]<<" ";
    }
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