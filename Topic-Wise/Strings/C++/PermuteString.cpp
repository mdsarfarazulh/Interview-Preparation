/* 
    Problem:    https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0
    Editorial:  https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
*/
#include<bits/stdc++.h>
using namespace std;

vector<string> ans;

void permute(string str, int l, int r){
    if(l == r){
        ans.push_back(str);
        return;
    }
    for(int i=l;i<=r;++i){
        swap(str[i], str[l]);
        permute(str, l+1, r);
        swap(str[i], str[l]);
    }
}

void solve(){
    ans.clear();
    string str;
    cin>>str;
    permute(str, 0, str.size()-1);
    sort(ans.begin(), ans.end());
    for(string w: ans)
        cout<<w<<" ";
    cout<<endl;
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