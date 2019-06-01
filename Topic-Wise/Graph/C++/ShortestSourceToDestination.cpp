/* 
    Problem:    https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path/0
    Editorial:  https://www.geeksforgeeks.org/shortest-path-in-a-binary-maze/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool isValid(int x, int y, int n, int m){
    return (x>=0 && x<n && y>=0 && y<m);
}

void solve(){
    int n, m;
    cin>>n>>m;
    int mat[n][m];
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            cin>>mat[i][j];
    int d_x, d_y;
    cin>>d_x>>d_y;
    int dis[n][m];
    memset(dis, -1, sizeof(dis));
    int x, y, _x, _y;
    x = y = 0;
    queue<pair<int, int> > Q;
    if(mat[x][y]){
        dis[x][y] = 0;
        Q.push(make_pair(x, y));
    }
    while(!Q.empty()){
        x = Q.front().first;
        y = Q.front().second;
        Q.pop();
        for(int i=0;i<4;++i){
            _x = x + dx[i];
            _y = y + dy[i];
            if(isValid(_x, _y, n, m) && dis[_x][_y]==-1 && mat[_x][_y]){
                dis[_x][_y] = dis[x][y] + 1;
                Q.push(make_pair(_x, _y));
            }
            if(_x == d_x && _y == d_y){
                cout<<dis[d_x][d_y]<<endl;
                return;
            }
        }
    }
    cout<<dis[d_x][d_y]<<endl;
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