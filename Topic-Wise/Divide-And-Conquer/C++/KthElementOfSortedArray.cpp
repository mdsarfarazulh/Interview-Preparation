/* 
    Problem:    https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array/0
    Editorial:  https://www.geeksforgeeks.org/k-th-element-two-sorted-arrays/
*/
#include<bits.h/stdc++.h>
using namespace std;

#define LL long long int

int findKthElement(int a[], int b[], int r_a, int r_b, int k){
    
}

void solve(){
    int n, m, k;
    cin>>n>>m>>k;
    int a[n], b[m];
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=0;i<m;++i)
        cin>>b[i];
    cout<<findKthElement(a, b, n-1, m-1, k)<<endl;
}

int main(void){
    ios_base::sync_with(stdio);
    cin.tie(NULL);
    cout.tie(NULL);

    int tcases;
    cin>>tcases;
    while(tcases--)
        solve();
    return 0;
}