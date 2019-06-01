/*
    Problem:    https://practice.geeksforgeeks.org/problems/flood-fill-algorithm/0
    Editorial:  https://www.geeksforgeeks.org/flood-fill-algorithm-implement-fill-paint/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(vector<vector<int> > &mat, int x, int y, int s, int k){
    mat[x][y] = k;
    int _x, _y;
    for(int i=0;i<4;++i){
        _x = dx[i] + x;
        _y = dy[i] + y;
        if(_x>=0 && _x<mat.size() && _y>=0 && _y<mat[0].size() && mat[_x][_y] == s)
            dfs(mat, _x, _y, s, k);
    }
}

void solve(){
    int n_rows, n_cols;
    cin>>n_rows>>n_cols;
    vector<vector<int> > mat(n_rows, vector<int>(n_cols));
    for(int i=0;i<n_rows;++i)
        for(int j=0;j<n_cols;++j)
            cin>>mat[i][j];
    int x, y, k, s;
    cin>>x>>y>>k;
    s = mat[x][y];
    dfs(mat, x, y, s, k);
    for(vector<int> V: mat)
        for(int v: V)
            cout<<v<<" ";
    cout<<endl;
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