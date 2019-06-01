
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*you are required to complete this method*/
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


int findIslands(int A[MAX][MAX], int N, int M)
{
    //Your code here
    bool vis[MAX][MAX];
    int ans = 0;
    memset(vis, false, sizeof(vis));
    pair<int, int> node;
    int x, y;
    int _x, _y;
    queue<pair<int, int> > Q;
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            if(!vis[i][j] && A[i][j]){
                ++ans;
                Q.push(make_pair(i, j));
                vis[i][j] = true;
                while(!Q.empty()){
                    node = Q.front();
                    Q.pop();
                    x = node.first;
                    y = node.second;
                    for(int k=0;k<8;++k){
                        _x = x + dx[k];
                        _y = y + dy[k];
                        if(_x>=0 && _x<N && _y>=0 && _y<M && !vis[_x][_y] && A[_x][_y]){
                            vis[_x][_y] = true;
                            Q.push(make_pair(_x, _y));
                        }
                    }
                }
            }
        }
    }
    return ans;
}