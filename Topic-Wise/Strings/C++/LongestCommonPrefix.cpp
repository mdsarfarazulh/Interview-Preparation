/*
    Problem:    https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array/0
    Editorial:  https://www.geeksforgeeks.org/longest-common-prefix-using-binary-search/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    int n;
    cin>>n;
    vector<string> arr(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    int min_idx = 0;
    for(int i=1;i<n;++i)
        if(arr[i].size()<arr[min_idx].size())
            min_idx = i;
        
    swap(arr[0], arr[min_idx]);
    
    int l = 0, m;
    int r = arr[0].size()-1;
    bool flag;
    int l_size;
    string ans = "";
    while(l<=r){
        m = l + (r-l)/2;
        l_size = (m-l+1);
        flag = true;
        for(int i=1;i<n;++i){
            if(arr[0].substr(l, l_size).compare(arr[i].substr(l, l_size))){
                flag = false;
                break;
            }
        }
        if(flag){
            ans.append(arr[0].substr(l, l_size));
            l = m+1;
        }else{
            r = m-1;
        }
    }
    if(ans.size()==0)
        cout<<"-1"<<endl;
    else
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