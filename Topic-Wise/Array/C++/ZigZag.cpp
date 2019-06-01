/* 
    Problem:    https://practice.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion/0
    Editorial:  https://www.geeksforgeeks.org/convert-array-into-zig-zag-fashion/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    
    sort(arr.begin(), arr.end());
    for(int i=1;i<n;i+=2)
        swap(arr[i], arr[i-1]);
    for(int i=0;i<n;++i)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void _solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    
    bool flag = true;
    for(int i=0;i<n-1;++i){
        if(flag){
            if(arr[i] > arr[i+1])
                swap(arr[i], arr[i+1]);
        }
        else{
            if(arr[i]<arr[i+1])
                swap(arr[i], arr[i+1]);
        }
        flag = !flag;
    }
    for(int v: arr)
        cout<<v<<" ";
    cout<<endl;
}

int main(void){
    int tcases;
    cin>>tcases;
    while(tcases--){
        _solve();
    }
    return 0;
}