/* 
    Problem:    https://practice.geeksforgeeks.org/problems/minimum-cost-path/0
    Editorial:  https://www.geeksforgeeks.org/min-cost-path-dp-6/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int
#define mp make_pair

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int isValid(int x, int y, int n){
    return (x>=0 && y>=0 && x<n && y<n);
}

void solve(){
    int n;
    cin>>n;
    int mat[n][n];
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            cin>>mat[i][j];

    priority_queue<pair<int, pair<int, int> > > Q;
    int dis[n][n];
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            dis[i][j] = INT_MAX;
    dis[0][0] = mat[0][0];
    Q.push(mp(-1*dis[0][0], mp(0, 0)));
    int x, y, _x, _y, d, _d;
    while(!Q.empty()){
        x = Q.top().second.first;
        y = Q.top().second.second;
        Q.pop();
        if(x == n-1 && y == n-1){
            cout<<dis[x][y]<<endl;
            return;
        }
        for(int i=0;i<4;++i){
            _x = x + dx[i];
            _y = y + dy[i];
            if(isValid(_x, _y, n) && dis[_x][_y] > (dis[x][y] + mat[_x][_y])){
                dis[_x][_y] = dis[x][y] + mat[_x][_y];
                Q.push(mp(-1*dis[_x][_y], mp(_x, _y)));
            }
        }
    }    
    //cout<<dis[n-1][n-1]<<endl;
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
