/* 
    Problem:    https://practice.geeksforgeeks.org/problems/find-first-set-bit/0
    Editorial:  https://www.geeksforgeeks.org/position-of-rightmost-set-bit/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    int n;
    cin>>n;
    int i=0;

    while(n){
        if(n&1){
            cout<<++i<<endl;
            return;
        }
        n = n>>1;
        ++i;
    }
    cout<<i<<endl;
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