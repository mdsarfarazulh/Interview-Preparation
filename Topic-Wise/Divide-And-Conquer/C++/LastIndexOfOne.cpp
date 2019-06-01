/* 
    Problem:    https://practice.geeksforgeeks.org/problems/last-index-of-1/0
    Editorial:  
*/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    string str;
    cin>>str;
    for(int i=str.size()-1;i>=0;--i){
        if(str[i]=='1'){
            cout<<i<<endl;
            return;
        }
    }
    cout<<"-1"<<endl;
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