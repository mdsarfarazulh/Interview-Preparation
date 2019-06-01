/* 
    Problem:    https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix/0
    Editorial:  https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/
*/

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin>>n>>m;
    vector<vector<int> > mat(n, vector<int>(m));
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            cin>>mat[i][j];
    
    int top = 0, bottom = n-1, left = 0, right = m-1;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;++i)
            cout<<mat[top][i]<<" ";
        top++;
        for(int i=top;i<=bottom;++i)
            cout<<mat[i][right]<<" ";
        right--;
        if(top>bottom || left>right)
            break;
        for(int i=right;i>=left;--i)
            cout<<mat[bottom][i]<<" ";
        bottom--;
        if(top>bottom || left>right)
            break;
        for(int i=bottom;i>=top;--i)
            cout<<mat[i][left]<<" ";
        left++;
    }
    cout<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tcases;
    cin>>tcases;
    while(tcases--){
        solve();
    }
    return 0;
}