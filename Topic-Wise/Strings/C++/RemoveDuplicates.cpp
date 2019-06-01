/* 
    Problem:    https://practice.geeksforgeeks.org/problems/remove-duplicates/0
    Editorial:  https://www.geeksforgeeks.org/remove-duplicates-from-a-given-string/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    string str;
    vector<bool> hash_table(256, false);
    getline(cin, str);
    for(char v: str){
        if(!hash_table[v])
            hash_table[v] = true, cout<<v;
    }
    cout<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tcases;
    cin>>tcases;
    string str;
    getline(cin, str);
    while(tcases--){
        solve();
    }
    return 0;
}