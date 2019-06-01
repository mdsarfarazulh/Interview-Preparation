/*
    Problem:    https://practice.geeksforgeeks.org/problems/palindromic-array/0
    Editorial:  https://www.geeksforgeeks.org/find-minimum-number-of-merge-operations-to-make-an-array-palindrome/
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
    int left_sum = arr[0];
    int right_sum = arr[n-1];
    int l_ptr = 0;
    int r_ptr = n-1;
    int ans = 0;
    while(l_ptr<r_ptr){
        if(left_sum == right_sum){
            left_sum = arr[++l_ptr];
            right_sum = arr[--r_ptr];
        }else if(left_sum > right_sum){
            if(l_ptr == (r_ptr - 1))
                right_sum += left_sum, ++l_ptr, --r_ptr;
            else
                right_sum += arr[--r_ptr];
            ++ans;
        }else{
            if(l_ptr == (r_ptr - 1))
                left_sum += right_sum, ++l_ptr, --r_ptr;
            else
                left_sum += arr[++l_ptr];
            ++ans;
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