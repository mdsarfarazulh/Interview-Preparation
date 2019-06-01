/* 
    Problem:    https://practice.geeksforgeeks.org/problems/find-whether-path-exist/0
    Editorial:  https://www.geeksforgeeks.org/find-whether-path-two-cells-matrix/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void solve(){
    int n;
    cin>>n;
    int mat[n][n];
    int s_x, s_y;
    int d_x, d_y;
    int x, y, _x, _y;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>mat[i][j];
            if(mat[i][j] == 1){
                s_x = i;
                s_y = j;
            }
        }
    }

    bool vis[n][n];
    memset(vis, false, sizeof(vis));
    queue<pair<int, int> > Q;

    Q.push(make_pair(s_x, s_y));
    vis[s_x][s_y] = true;
    while(!Q.empty()){
        x = Q.front().first;
        y = Q.front().second;
        for(int i=0;i<4;++i){
            _x = x + dx[i];
            _y = y + dy[i];
            if(_x>=0 && _x<n && _y>=0 && _y<n && !vis[_x][_y]){
                if(mat[_x][_y] == 2){
                    cout<<"1"<<endl;
                    return;
                }else if(mat[_x][_y] == 3){
                    vis[_x][_y] = true;
                    Q.push(make_pair(_x, _y));
                }
            }
        }
    }
    cout<<"0"<<endl;
    return;
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