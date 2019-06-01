/* 
    Problem:    https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0
    Editorial:  https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    
    deque<int> Q(k);
    int i = 0;
    for(;i<k;++i){
        while(!Q.empty() && arr[Q.back()] <= arr[i]){
            Q.pop_back();
        }

        Q.push_back(i);
    }

    for(;i<n;++i){
        cout<<arr[Q.front()]<<" ";

        while(!Q.empty() && Q.front()<=i-k)
            Q.pop_front();
        while(!Q.empty() && arr[Q.back()] < arr[i]){
            Q.pop_back();
        }
        Q.push_back(i);
    }
    cout<<arr[Q.front()]<<endl;
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
    return 0;
}