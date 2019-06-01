/*
    Problem:    https://practice.geeksforgeeks.org/problems/is-sudoku-valid/0
    Editorial:  https://www.geeksforgeeks.org/check-if-given-sudoku-board-configuration-is-valid-or-not/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

bool rowValid(int row, vector<vector<int> > &mat){
    vector<bool> num(10, false);
    for(int i=0;i<9;++i){
        if(!mat[row][i])
            continue;
        if(num[mat[row][i]])
            return false;
        num[mat[row][i]] = true;
    }
    return true;
}

bool colValid(int col, vector<vector<int> > &mat){
    vector<bool> num(10, false);
    for(int i=0;i<9;++i){
        if(!mat[i][col])
            continue;
        if(num[mat[i][col]])
            return false;
        num[mat[i][col]] = true;
    }
    return true;
}

bool checkBoard(int row, int col, vector<vector<int> > &mat){
    vector<bool> num(10, false);
    for(int i=row;i<row+3;++i){
        for(int j=col;j<col+3;++j){
            if(!mat[i][j])
                continue;
            if(num[mat[i][j]])
                return false;
            num[mat[i][j]] = true;
        }
    }
    return true;
}

void solve(){
    vector<vector<int> > board(9, vector<int>(9));
    for(int i=0;i<9;++i)
        for(int j=0;j<9;++j)
            cin>>board[i][j];
    
    int flag = true;
    for(int i=0;i<9;++i){
        flag = rowValid(i, board) && colValid(i, board);
        if(!flag)
            break;
    }
    if(!flag){
        cout<<"0"<<endl;
        return;
    }
    for(int i=0;i<=6;i+=3){
        for(int j=0;j<=6;j+=3){
            if(!checkBoard(i, j, board)){
                cout<<"0"<<endl;
                return;
            }
        }
    }
    cout<<"1"<<endl;
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