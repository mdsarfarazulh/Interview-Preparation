/* 
    Problem:    https://practice.geeksforgeeks.org/problems/stock-buy-and-sell/0
    Editorial:  https://www.geeksforgeeks.org/stock-buy-sell/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    
    int flag = 0;
    int l = 0, r = 0;
    for(int i=1;i<n;){
        while(i<n && arr[i]>arr[i-1]){
            r = i;
            ++i;
        }
        if(l!=r){
            cout<<"("<<l<<" "<<r<<") ";
            flag = 1;
        }
        l = r = i;
        ++i;
    }
    if(!flag)
        cout<<"No Profit";
    cout<<endl;   
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