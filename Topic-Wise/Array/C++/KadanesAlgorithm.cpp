/* 
    Problem:    https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0
    Editorial:  https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long int


void solve(){
    int n;
    cin>>n;
    LL arr;
    LL max_sum_so_far = LONG_MIN;
    LL sum_so_far = 0;
    for(int i=0;i<n;++i){
        cin>>arr;
        sum_so_far = max(arr, sum_so_far + arr);
        max_sum_so_far = max(sum_so_far, max_sum_so_far);
    }
    cout<<max_sum_so_far<<endl;
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
}