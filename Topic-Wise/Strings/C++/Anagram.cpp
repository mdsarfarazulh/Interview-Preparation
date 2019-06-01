/*
    Problem:    https://practice.geeksforgeeks.org/problems/anagram/0
    Editorial:  https://www.geeksforgeeks.org/check-whether-two-strings-are-anagram-of-each-other/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    string a, b;
    cin>>a>>b;

    if(!(a.compare(b))){
        cout<<"NO"<<endl;
        return;
    }

    vector<int> count(26, 0);

    for(char c: a)
        count[c-'a']++;

    for(char c: b)
        count[c-'a']--;
    
    for(int i=0;i<26;++i){
        if(count[i]){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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