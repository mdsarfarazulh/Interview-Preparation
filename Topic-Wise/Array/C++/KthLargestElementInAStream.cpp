/* 
    Problem:    https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream/0
    Editorial:  https://www.geeksforgeeks.org/kth-largest-element-in-a-stream/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void heapify(vector<int> &heap, int k, int index){
    int smallest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;
    if(left<k && heap[smallest]>heap[left]){
        smallest = left;
    }
    if(right<k && heap[smallest]>heap[right]){
        smallest = right;
    }

    if(smallest!=index){
        swap(heap[index], heap[smallest]);
        heapify(heap, k, smallest);
    }
}

void solve(){
    int k, n;
    cin>>k>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    
    vector<int> heap(k);
    for(int i=1;i<k;++i){
        heap[i-1] = arr[i-1];
        cout<<"-1 ";
    }
    heap[k-1] = arr[k-1];
    for(int i=k/2-1;i>=0;--i)
        heapify(heap, k, i);
    
    cout<<heap[0]<<" ";
    for(int i=k;i<n;++i){
        if(arr[i]>heap[0]){
            heap[0] = arr[i];
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