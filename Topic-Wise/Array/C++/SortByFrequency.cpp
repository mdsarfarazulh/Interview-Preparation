/* 
    Problem:    https://practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency/0
    Editorial:  https://www.geeksforgeeks.org/sort-elements-by-frequency/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

unordered_map<int, int> umap;

bool comparator(int a, int b){
    if(umap[a]==umap[b])
        return a<b;
    return umap[a]>umap[b];
}

void solve(){
    umap.clear();
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
        if(umap.find(arr[i]) != umap.end()){
            umap[arr[i]]++;
        }
        else{
            umap[arr[i]] = 1;
        }
    }

    sort(arr.begin(), arr.end(), comparator);
    for(int i=0;i<n;++i)
        cout<<arr[i]<<" ";
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