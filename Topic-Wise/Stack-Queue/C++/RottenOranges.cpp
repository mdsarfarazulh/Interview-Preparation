#include<bits/stdc++.h>
using namespace std;

#define LL long long int

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void solve(){
    int n_rows, n_cols;
    cin>>n_rows>>n_cols;
    vector<vector<int> > mat(n_rows, vector<int>(n_cols));
    vector<vector<int> > dis(n_rows, vector<int>(n_cols));
    
    for(int i=0;i<n_rows;++i){
        for(int j=0;j<n_cols;++j){
            cin>>mat[i][j];
            dis[i][j] = INT_MAX;
        }
    }
    
    pair<int, int> cell;
    int x, y, _x, _y;
    queue<pair<int, int> > Q;
    for(int i=0;i<n_rows;++i){
        for(int j=0;j<n_cols;++j){
            if(mat[i][j]==2 && dis[i][j]){
                dis[i][j] = 0;
                Q.push(make_pair(i, j));
                while(!Q.empty()){
                    cell = Q.front();
                    Q.pop();
                    x = cell.first;
                    y = cell.second;
                    for(int k=0;k<4;++k){
                        _x = x + dx[k];
                        _y = y + dy[k];
                        if(_x<n_rows && _x>=0 && _y<n_cols && _y>=0){
                            if(mat[_x][_y]==1 && dis[_x][_y] > dis[x][y]+1){
                                dis[_x][_y] = dis[x][y] + 1;
                                Q.push(make_pair(_x, _y));
                            }else if(mat[_x][_y]==2 && dis[_x][_y]){
                                dis[_x][_y] = 0;
                                Q.push(make_pair(_x, _y));
                            }
                        }
                    }
                }
            }
        }
    }

    int ans = INT_MIN;
    for(int i=0;i<n_rows;++i){
        for(int j=0;j<n_cols;++j){
            if(dis[i][j]==INT_MAX){
                if(mat[i][j] == 1){
                    cout<<"-1"<<endl;
                    return;
                }
                continue;
            }
            ans = max(ans, dis[i][j]);
        }
    }
    cout<<ans<<endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tcases;
	cin>>tcases;
	while(tcases--)
	    solve();
	return 0;
}
