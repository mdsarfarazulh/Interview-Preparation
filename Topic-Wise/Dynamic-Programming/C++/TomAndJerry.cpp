/* 
    Problem:    https://practice.geeksforgeeks.org/problems/tom-and-jerry/0
    Editorial:  https://www.geeksforgeeks.org/optimal-strategy-for-a-game-dp-31/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    int n;
    cin>>n;
    cout<<(n-1)%2<<endl;
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