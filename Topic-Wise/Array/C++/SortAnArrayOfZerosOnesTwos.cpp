/* 
    Problem:    https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0
    Editorial:  https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/
*/

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> count(3, 0), arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
        count[arr[i]]++;
    }
    for(int i=0, j=0;i<n;++i){
        if(count[j])
            arr[i] = j, --count[j];
        else
            ++j, --i;
    }
    for(int i=0;i<n;++i)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void __solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    int zero = 0;
    int two = n-1;
    for(int i=0;i<=two;){
        if(!arr[i]){
            swap(arr[i], arr[zero]);
            ++zero;
            ++i;
        }
        else if(arr[i]==2){
            swap(arr[i], arr[two]);
            --two;
        }
        else
            ++i;        
    }

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
}