/* 
    Problem:    https://practice.geeksforgeeks.org/problems/longest-distinct-characters-in-string/0
    Editorial:  https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    string str;
    cin>>str;
    vector<int> indices(26, -1);
    int start = 0;
    int length = 0;
    int ans = 0;
    int temp;
    for(int i=start;i<str.size();++i){
        if(indices[str[i] - 'a']<start){
            indices[str[i] - 'a'] = i;
            ++length;
        }
        else{
            temp = indices[str[i] - 'a'];
            indices[str[i] - 'a'] = i;
            start = temp + 1;
            ans = max(length, ans);
            length = i - temp;
        }
    }
    ans = max(ans, length);
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