/*
    Problem:    https://practice.geeksforgeeks.org/problems/pythagorean-triplet/0
    Editorial:  https://www.geeksforgeeks.org/find-pythagorean-triplet-in-an-unsorted-array/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
        arr[i] = arr[i]*arr[i];
    }
    sort(arr.begin(), arr.end());
    int left, right;
    for(int i=n-1;i>1;--i){
        for(int l=0, r=i-1;l<r;){
            if(arr[i] == (arr[l] + arr[r])){
                cout<<"Yes"<<endl;
                return;
            }

            (arr[i] > (arr[l] + arr[r]))?++l:--r;
        }
    }
    cout<<"No"<<endl;
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