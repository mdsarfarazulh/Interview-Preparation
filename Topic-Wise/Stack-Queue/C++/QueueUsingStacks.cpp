/* 
    Problem:    https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1
    Editorial:  https://www.geeksforgeeks.org/queue-using-stacks/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void _push(stack<int> &s1, int x){
    s1.push(x);
}

int _pop(stack<int> &s1, stack<int> &s2){
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    int ans = -1;
    if(!s2.empty()){
        ans = s2.top();
        s2.pop();
    }
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
    return ans;
}
void solve(){
    stack<int> s1, s2;
    int Q;
    cin>>Q;
    int c, x;
    while(Q--){
        cin>>c;
        if(c==1){
            cin>>x;
            _push(s1, x);
        }else{
            cout<<_pop(s1, s2)<<" ";
        }
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