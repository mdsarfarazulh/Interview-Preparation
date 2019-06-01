/*
    Problem:    https://practice.geeksforgeeks.org/problems/rearrange-characters/0
    Editorial:  https://www.geeksforgeeks.org/rearrange-characters-string-no-two-adjacent/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    string str;
    cin>>str;
    vector<int> _freq(26, 0);
    for(char ch : str)
        _freq[ch - 'a']++;
    int limit = str.size()+1;
    limit = limit>>1;
    bool flag = true;
    for(int v : _freq){
        if(v > limit){
            flag = false;
            break;
        }
    }
    cout<<flag<<endl;
}

void _solve(){
    string str;
    cin>>str;
    int n = str.size();
    vector<int> _freq(26, 0);
    for(char ch: str)
        _freq[ch - 'a']++;
    priority_queue<pair<int, char> > Q;
    for(int i=0;i<26;++i){
        if(_freq[i]){
            Q.push({_freq[i], (i + 'a')});
        }
    }
    str = "";
    pair<int, char> prev, key;
    prev = make_pair(-1, '#');
    while(!Q.empty()){
        key = Q.top();
        Q.pop();
        str = str + key.second;

        if(prev.first > 0)
            Q.push(prev);
        (key.first)--;
        prev = key;
    }
    if(n != str.length())
        cout<<"Not Possible"<<endl;
    else 
        cout<<str<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tcases;
    cin>>tcases;
    while(tcases--)
        _solve();
    return 0;
}