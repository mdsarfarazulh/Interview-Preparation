/*
    Problem:    https://practice.geeksforgeeks.org/problems/triplet-sum-in-array/0
    Editorial:  https://www.geeksforgeeks.org/find-a-triplet-that-sum-to-a-given-value/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    int sum;
    int ans = 0;
    sort(arr.begin(), arr.end());
    for(int i=0;i<n-2;++i){
        for(int l=i+1, r= n-1;l<r;){
            sum = arr[i] + arr[l] + arr[r];
            if(sum>k)
                --r;
            else if(sum<k)
                ++l;
            else{
                int ql, qr;
                qr = r;
                if(arr[l]==arr[r]){
                    ans += r-l+1;
                    break;
                }
                int cl, cr;
                cr = cl = 0;
                while(qr > l && arr[qr--]==arr[r])
                    ++cr;
                ql = l;
                while(ql < r && arr[ql++]==arr[l])
                    ++cl;
                l = ql, r = qr;
                ans += cl*cr;
            }
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