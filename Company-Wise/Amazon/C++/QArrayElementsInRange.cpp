/*
    Editorial:  https://www.geeksforgeeks.org/queries-counts-array-elements-values-given-range/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

int query(vector<int> &arr, int l, int r, int key, bool left){
    if((r-l)>1){
        int m = l + (r-l)/2;
        if(arr[m]>key)
            return query(arr, l, m, key, left);
        return query(arr, m, r, key, left);
    }

    if(left){
        if(arr[l]>=key)
            return l;
        return r;
    }else{
        if(arr[r]<=key)
            return r;
        return l;
    }
}

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    int Q;
    cin>>Q;
    int l, r;
    int ql, qr;
    sort(arr.begin(), arr.end());
    while(Q--){
        cin>>l>>r;
        if(r<arr[0] || l>arr[arr.size()-1]){
            cout<<0<<endl;
        }else{
            ql = query(arr, 0, n-1, l, true);
            qr = query(arr, 0, n-1, r, false);
            cout<<ql<<" "<<qr<<endl;
            cout<<(qr-ql+1)<<endl;
        }
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