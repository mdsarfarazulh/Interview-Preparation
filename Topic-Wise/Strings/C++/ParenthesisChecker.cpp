/* 
    Problem:    https://practice.geeksforgeeks.org/problems/parenthesis-checker/0
    Editorial:  https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    string str;
    cin>>str;
    stack<char> S;
    bool flag = true;
    for(char c: str){
        if(c=='[' || c=='{' || c=='(')
            S.push(c);
        else{
            if(S.empty() || (c==']' && S.top()!='[') || (c=='}' && S.top()!='{') || (c==')' && S.top()!='(')){
                flag = false;
                break;
            }
            else
                S.pop();
        }
    }
    if(!flag || !S.empty()){
        cout<<"not balanced"<<endl;
    }
    else{
        cout<<"balanced"<<endl;
    }
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