/*
    Problem:    https://practice.geeksforgeeks.org/problems/row-with-max-1s/0
    Editorial:  https://www.geeksforgeeks.org/find-the-row-with-maximum-number-1s/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

int countOne(int l, int r, vector<int> &arr){
    if((r-l)>1){
        int m = l + (r-l)/2;
        if(arr[m])
            return countOne(l, m, arr);
        else
            return countOne(m, r, arr);
    }
    if(arr[l])
        return arr.size()-l;
    if(arr[r])
        return arr.size()-r;
    return 0;
}

void solve(){
    int n, m;
    cin>>n>>m;
    vector<vector<int> > mat(n, vector<int>(m));
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            cin>>mat[i][j];
    int ans = -1, max_one = -1;
    int temp;
    for(int i=0;i<n;++i){
        temp = countOne(0, m-1, mat[i]);
        if(temp>max_one){
            ans = i;
            max_one = temp;
        }
    }
    cout<<ans<<endl;
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