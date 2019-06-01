/* 
    Problem:    https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1
    Editorial:  https://www.geeksforgeeks.org/implement-stack-using-queue/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void _push(queue<int> &q1, int x){
    q1.push(x);
}

int _pop(queue<int> &q1, queue<int> &q2){
    int ans = -1;
    while(!q1.empty()){
        if(q1.size()==1){
            ans = q1.front();
            q1.pop();
            continue;
        }
        q2.push(q1.front());
        q1.pop();
    }
    while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();
    }
    return ans;
}
void solve(){
    int Q;
    cin>>Q;
    queue<int> q1, q2;
    int c, x;
    while(Q--){
        cin>>c;
        if(c==1){
            cin>>x;
            _push(q1, x);
        }else{
            cout<<_pop(q1, q2)<<" ";
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