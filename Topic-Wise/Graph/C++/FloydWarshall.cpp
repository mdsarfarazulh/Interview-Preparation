/* 
    Problem:    https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall/0
    Editorial:  https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    int n;
    cin>>n;
    int arr[n][n];
    int dis[n][n];

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>arr[i][j];
            dis[i][j] = arr[i][j];
        }
    }

    for(int k=0;k<n;++k)
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                if((dis[i][k] + dis[k][j]) < dis[i][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
    
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(dis[i][j] == 10000000 )
                cout<<"INF ";
            else
                cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
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