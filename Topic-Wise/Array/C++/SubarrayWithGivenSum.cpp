/* 
    Problem:    https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
    Editorial:  https://www.geeksforgeeks.org/find-subarray-with-given-sum/
*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long int

vector<int> arr;

void solve(){
    int n;
    LL k;
    cin>>n>>k;
    arr.resize(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    
    LL sum = 0;
    int L = 0, R;
    for(R=0;R<n;++R){
        sum += arr[R];
        while(sum>k && L<=R){
            sum -= arr[L];
            ++L;
        }
        if(sum==k){
            cout<<++L<<" "<<++R<<endl;
            return;
        }
    }
    cout<<"-1"<<endl;
    return;
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
