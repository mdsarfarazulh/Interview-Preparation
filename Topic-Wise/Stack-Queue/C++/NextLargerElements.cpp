/* 
    Problem:    https://practice.geeksforgeeks.org/problems/next-larger-element/0
    Editorial:  https://www.geeksforgeeks.org/next-greater-element/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    int n;
    cin>>n;
    vector<LL> arr(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    
    stack<LL> S;
    vector<LL> ans(n);
    for(int i=n-1;i>=0;--i){
        while(!S.empty() && S.top()<arr[i]){
            S.pop();
        }
        if(S.empty())
            ans[i] = -1;
        else
            ans[i] = S.top();
        S.push(arr[i]);
    }
    for(int i=0;i<n;++i)
        cout<<ans[i]<<" ";
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