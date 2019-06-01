/* 
    Problem:    https://practice.geeksforgeeks.org/problems/missing-number-in-array/0
    Editorial:  https://www.geeksforgeeks.org/find-the-missing-number/
*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    int ans = 0;
    int n;
    cin>>n;
    int temp;
    for(int i=0;i<n-1;++i){
        cin>>temp;
        ans = ans^temp;
    }
    for(int i=1;i<=n;++i)
        ans = ans^i;
    cout<<ans<<endl;
}

void __solve(){
    int ans = 0;
    int n;
    cin>>n;
    int temp;
    LL sum = 0;
    for(int i=0;i<n-1;++i){
        cin>>temp;
        sum += temp;
    }
    ans = ((LL)n * ((LL) n + 1))/2 - sum;
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
}