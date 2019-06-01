/* 
    Problem:    https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0
    Editorial:  https://www.geeksforgeeks.org/leaders-in-an-array/
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    // Took 0.25 Sec
    int n;
    cin>>n;
    vector<int> arr(n), r_max(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    
    r_max[n-1] = arr[n-1];
    for(int i=n-2;i>=0;--i)
        r_max[i] = max(arr[i], r_max[i+1]);
    
    for(int i=0;i<n;++i){
        if(arr[i]==r_max[i])
            cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void __solve(){
    // Took 0.35 Sec
    int n;
    cin>>n;
    vector<int> arr(n);
    stack<int> st;
    int c_max;
    for(int i=0;i<n;++i)
        cin>>arr[i];
    
    st.push(arr[n-1]);
    c_max = arr[n-1];
    for(int i=n-2;i>=0;--i){
        if(arr[i]>=c_max){
            c_max = arr[i];
            st.push(c_max);
        }
    }
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
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