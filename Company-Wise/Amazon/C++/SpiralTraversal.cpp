vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int n_rows = A.size();
    int n_cols = A[0].size();
    vector<int> ans;
    int l = 0, r = n_cols-1, t = 0, b = n_rows-1;
    int dir = 0;
    while(t<=b && l<=r){
        switch(dir){
            case 0:
                for(int i=l;i<=r;++i)
                    ans.push_back(A[t][i]);
                dir = (dir+1)%4;
                ++t;
                break;
            case 1:
                for(int i=t;i<=b;++i)
                    ans.push_back(A[i][r]);
                dir = (dir+1)%4;
                --r;
                break;
            case 2:
                for(int i=r;i>=l;--i)
                    ans.push_back(A[b][i]);
                dir = (dir+1)%4;
                --b;
                break;
            case 3:
                for(int i=b;i>=t;--i)
                    ans.push_back(A[i][l]);
                dir = (dir+1)%4;
                ++l;
                break;
        }
    }
    return ans;
}
