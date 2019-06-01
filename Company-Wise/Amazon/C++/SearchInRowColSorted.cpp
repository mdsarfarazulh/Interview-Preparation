/*
    Problem:    https://practice.geeksforgeeks.org/problems/search-in-a-matrix/0
    Editorial:  https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    int n, m;
    cin>>n>>m;
    int key;
    vector<vector<int> > mat(n, vector<int>(m));
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            cin>>mat[i][j];
    cin>>key;
    int _row, _col;
    _row = 0;
    _col = m-1;
    while(_col>=0 && _row<n){
        if(mat[_row][_col]>key)
            --_col;
        else if(mat[_row][_col]<key)
            ++_row;
        else{
            cout<<"1"<<endl;
            return;
        }
    }
    cout<<"0"<<endl;
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