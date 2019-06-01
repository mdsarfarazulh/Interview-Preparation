/* 
    Problem:    https://practice.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1
    Editorial:  https://www.geeksforgeeks.org/largest-subarray-with-equal-number-of-0s-and-1s/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
        if(!arr[i])
            arr[i] = -1;
    }

    vector<int> sumLeft(n);
    sumLeft[0] = arr[0];
    for(int i=1;i<n;++i)
        sumLeft[i] = sumLeft[i-1] + arr[i];
    
    unordered_map<int, int> umap;
    for(int i=0;i<n;++i){
        if(umap.find(sumLeft[i]) == umap.end()){
            umap[sumLeft[i]] = i;
        }
    }
    int ans = -1;
    for(int i=n-1;i>=0;--i){
        if(!sumLeft[i]){
            ans = max(ans, i+1);
        }else{
            if(umap.find(sumLeft[i]) != umap.end()){
                ans = max(ans, abs(i- umap[sumLeft[i]]));
            }
        }
    }
    cout<<ans<<endl;
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