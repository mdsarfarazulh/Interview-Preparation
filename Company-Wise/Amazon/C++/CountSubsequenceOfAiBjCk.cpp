/*
    Problem:    https://practice.geeksforgeeks.org/problems/count-subsequences-of-type-ai-bj-ck/0
    Editorial:  https://www.geeksforgeeks.org/number-subsequences-form-ai-bj-ck/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    string str;
    cin>>str;
    vector<LL> temp_c(str.size(), 0);
    LL temp = 1;
    for(int i=str.size()-1;i>=0;--i){
        temp_c[i] = temp;
        if(str[i] == 'c')
            temp *= 2;
    }
    LL ans = 0;
    LL temp_a = 1;
    LL temp_b = 1;
    for(int i=0;i<str.size();++i){
        if(str[i] == 'a'){
            temp_b = 1;
            for(int j=i+1;j<str.size();++j){
                if(str[j] == 'b'){
                    ans += temp_a*temp_b*(temp_c[j]-1);
                    temp_b *= 2;
                }
            }
            temp_a *= 2;
        }
    }
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