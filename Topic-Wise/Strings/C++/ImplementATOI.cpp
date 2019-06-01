/*
    Problem:    https://practice.geeksforgeeks.org/problems/implement-atoi/1
    Editorial:  https://www.geeksforgeeks.org/write-your-own-atoi/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    string str;
    cin>>str;
    LL ans = 0;
    int neg = 1;
    int start = 0;
    if(str[0]=='-'){
        neg = -1;
        start = 1;
    }
    bool flag = true;
    for(int i=start;i<str.size();++i){
        if(str[i]<'0' || str[i]>'9'){
            ans = -1;
            flag = false;
            break;
        }
        ans = ans*10 + (str[i]-'0');
    }
    if(flag)
        cout<<neg*ans<<endl;
    else
        cout<<"-1"<<endl;
    
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