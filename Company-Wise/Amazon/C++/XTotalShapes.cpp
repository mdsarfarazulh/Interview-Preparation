/*
    Problem:    https://practice.geeksforgeeks.org/problems/x-total-shapes/0
    Editorial:  
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void dfs(int x, int y, vector<vector<bool> > &vis, vector<string> &arr){
    vis[x][y] = true;
    int _x, _y;
    for(int i=0;i<4;++i){
        _x = x + dx[i];
        _y = y + dy[i];
        if(_x>=0 && _x<arr.size() && _y>=0 && _y<arr[0].size() && !vis[_x][_y] && arr[_x][_y]=='X')
            dfs(_x, _y, vis, arr);
    }
}

void solve(){
    int n, m;
    cin>>n>>m;
    vector<string> arr(n);

    for(int i=0;i<n;++i)
        cin>>arr[i];
    
    vector<vector<bool> > vis(n, vector<bool>(m, false));
    int ans = 0;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(arr[i][j]=='X' && !vis[i][j] && ++ans)
                dfs(i, j, vis, arr);
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