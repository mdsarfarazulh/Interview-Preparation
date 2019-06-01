/* 
    Problem:    https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string/0
    Editorial:  https://www.geeksforgeeks.org/reverse-words-in-a-given-string/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    string str;
    cin>>str;

    stack<string> S;
    string temp;
    stringstream ss(str);
    while(getline(ss, temp, '.'))
        S.push(temp);
    
    while(S.size()!=1){
        cout<<S.top()<<".";
        S.pop();
    }
    cout<<S.top()<<endl;
    S.pop();
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
