/*
    Problem:    https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes/0
    Editorial:  https://www.geeksforgeeks.org/connect-n-ropes-minimum-cost/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    int n;
    cin>>n;
    priority_queue<LL> pq;
    LL temp;
    for(int i=0;i<n;++i){
        cin>>temp;
        pq.push(-1*temp);
    }
    LL num1;
    LL ans = 0;
    while(pq.size()>1){
        num1 = -1*pq.top();
        pq.pop();
        num1 += -1*pq.top();
        pq.pop();
        ans += num1;
        pq.push(-1*num1);
    }
    pq.pop();
    cout<<ans<<endl;
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