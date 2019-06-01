/* 
    Problem:    https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream/0
    Editorial:  https://www.geeksforgeeks.org/find-first-non-repeating-character-stream-characters/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    int n;
    cin>>n;
    char c;
    queue<char> Q;
    vector<int> vis(26, 0);
    for(int i=0;i<n;++i){
        cin>>c;
        if(!vis[c-'a'])
            Q.push(c);
        vis[c-'a']++;
        while(vis[Q.front()-'a']>=2 && !Q.empty())
            Q.pop();
        if(Q.empty())
            cout<<"-1 ";
        else
            cout<<Q.front()<<" ";
    }
    cout<<endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tcases;
	cin>>tcases;
	while(tcases--)
	    solve();
	return 0;
}