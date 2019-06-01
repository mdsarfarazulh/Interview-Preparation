/* 
    Problem:    https://practice.geeksforgeeks.org/problems/equilibrium-point/0
    Editorial:  https://www.geeksforgeeks.org/equilibrium-index-of-an-array/
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
    if(n==1){
        cout<<"1"<<endl;
        return;
    }
    LL l_sum = 0;
    LL r_sum = 0;
    int l = 0, r = n-1;
    l_sum = arr[l];
    r_sum = arr[r];
    while(l<n-1 && r>0){
        if(l+1==r-1)
            break;
        if(l_sum<r_sum)
            l_sum += (LL)arr[++l];
        else if(l_sum>r_sum)
            r_sum += (LL)arr[--r];
        else
            l_sum += (LL)arr[++l];
    }
    if(l+1==r-1 && l_sum==r_sum)
        cout<<r<<endl;
    else
        cout<<"-1"<<endl;
}

void __solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    LL sum = 0, l_sum = 0;
    for(int i=0;i<n-1;++i)
        cin>>arr[i], sum += arr[i];
    for(int i=0;i<n;++i){
        if(l_sum == sum - arr[i]){
            cout<<(i+1)<<endl;
            return;
        }
        sum -= arr[i];
        l_sum += arr[i];
    }
    cout<<"-1"<<endl;
}


int main(void){
    int tcases;
    cin>>tcases;
    while(tcases--){
        solve();
    }
    return 0;
}