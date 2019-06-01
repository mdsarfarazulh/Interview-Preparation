/* 
    Problem:    https://practice.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places/0
    Editorial:  https://www.geeksforgeeks.org/check-string-can-obtained-rotating-another-string-2-places/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    string a, b;
    cin>>a>>b;

    if(a.size() != b.size()){
        cout<<"0"<<endl;
        return;
    }

    string a_clock = a.substr(2, a.size()-2) + a.substr(0, 2);
    string a_anti = a.substr(a.size()-2, 2) + a.substr(0, a.size()-2);

    if(b.compare(a_clock) == 0 || b.compare(a_anti) == 0)
        cout<<"1"<<endl;
    else
        cout<<"0"<<endl;
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

