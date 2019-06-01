/* 
    Problem:    https://practice.geeksforgeeks.org/problems/alien-dictionary/1
    Editorial:  https://www.geeksforgeeks.org/given-sorted-dictionary-find-precedence-characters/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void topoSort(int s, stack<int> &S, bool vis[], vector<vector<int> > &adj){
    vis[s] = true;
    for(int v: adj[s])
        if(!vis[v])
            topoSort(v, S, vis, adj);
    S.push(s);
}

string printOrder(string dict[], int N, int k){
    vector<vector<int> > adj(k);
    for(int i=0, j;i<N-1;++i){
        j = 0;
        while(j<dict[i].size() && j<dict[i+1].size()){
            if(dict[i][j] != dict[i+1][j]){
                adj[dict[i][j] - 'a'].push_back(dict[i+1][j] - 'a');
                break;
            }
            ++j;
        }            
    }
    stack<int> S;
    bool vis[k];
    memset(vis, false, sizeof(vis));
    for(int i=0;i<k;++i){
        if(!vis[i])
            topoSort(i, S, vis, adj);
    }
    string ans = "";
    while(!S.empty()){
        ans += S.top() + 'a';
        S.pop();
    }
    return ans;
}


void solve(){
    int n, k;
    cin>>n>>k;
    string arr[n];
    for(int i=0;i<n;++i)
        cin>>arr[i];
    cout<<printOrder(arr, n, k)<<endl;
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