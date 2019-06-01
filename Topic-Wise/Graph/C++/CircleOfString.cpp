/* 
    Problem:    https://practice.geeksforgeeks.org/problems/circle-of-strings/0
    Editorial:  https://www.geeksforgeeks.org/given-array-strings-find-strings-can-chained-form-circle/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void dfs(int s, int source, int &flag, int ans, vector<bool> &inStack, vector<bool> &vis, vector<vector<int> > &adj){
    vis[s] = true;
    inStack[s] = true;
    ans++;
    for(int v : adj[s]){
        if(inStack[v] && v == source && ans == vis.size()){
            flag = 1;
            return;
        }
        if(!inStack[v])
            dfs(v, source, flag, ans, inStack, vis, adj);
    }
    inStack[s] = false;
}

void solve(){
    int n;
    cin>>n;
    vector<string> arr(n);
    vector<vector<int> > adj(n);
    
    for(int i=0;i<n;++i)
        cin>>arr[i];
    if(n==1 && arr[0][arr[0].size()-1] == arr[0][0]){
        cout<<"1"<<endl;
        return;
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(i==j)
                continue;
            if(arr[i][arr[i].size()-1] == arr[j][0])
                adj[i].push_back(j);
        }
    }
    vector<bool> inStack(n, false), vis(n, false);
    int flag = 0;
    for(int i=0;i<n;++i){
        if(!vis[i]){
            dfs(i, i, flag, 0, inStack, vis, adj);
            if(flag)
                break;
        }
    }
    cout<<flag<<endl;
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