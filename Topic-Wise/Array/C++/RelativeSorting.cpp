/* 
    Problem:    https://practice.geeksforgeeks.org/problems/relative-sorting/0
    Editorial:  https://www.geeksforgeeks.org/sort-array-according-order-defined-another-array/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    int n, m;
    cin>>n>>m;
    vector<int> a1(n), a2(m);
    unordered_map<int, int> umap;
    for(int i=0;i<n;++i){
        cin>>a1[i];
        if(umap.find(a1[i]) == umap.end()){
            umap[a1[i]] = 1;
        }
        else{
            umap[a1[i]]++;
        }
    }

    for(int i=0;i<m;++i)
        cin>>a2[i];
    
    int indx = 0;
    vector<int> ans(n);
    sort(a1.begin(), a1.end());
    int count;

    for(int i=0;i<m;++i){
        if(umap.find(a2[i]) == umap.end()){
            count = 0;
        }else{
            count = umap[a2[i]];
            umap[a2[i]] = 0;
        }
        for(int j=0;j<count;++j){
            ans[indx++] = a2[i];
        }
    }

    for(int i=0;i<n;++i){
        if(umap[a1[i]]){
            count = umap[a1[i]];
            for(int j=0;j<count;++j){
                ans[indx++] = a1[i];
            }
            umap[a1[i]] = 0;
        }
    }
    for(int i=0;i<n;++i)
        cout<<ans[i]<<" ";
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