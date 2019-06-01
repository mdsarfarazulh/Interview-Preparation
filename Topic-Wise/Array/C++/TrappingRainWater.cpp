/* 
    Problem:    https://practice.geeksforgeeks.org/problems/trapping-rain-water/0
    Editorial:  https://www.geeksforgeeks.org/trapping-rain-water/
*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    int n;
    cin>>n;

    vector<int> front(n), back(n), arr(n);
    LL ans = 0;
    for(int i=0;i<n;++i)
        cin>>arr[i];
    
    front[0] = arr[0];
    for(int i=1;i<n;++i){
        front[i] = max(front[i-1], arr[i]);
    }

    back[n-1] = arr[n-1];
    for(int i=n-2;i>=0;--i)
        back[i] = max(arr[i], back[i+1]);
    
    for(int i=0;i<n;++i)
        ans += (LL) min(front[i], back[i]) - (LL) arr[i];
    cout<<ans<<endl;
}


void _solve(){
    int n;
    cin>>n;

    vector<int> back(n), arr(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    
    back[n-1] = arr[n-1];
    for(int i=n-2;i>=0;--i)
        back[i] = max(arr[i], back[i+1]);
    
    int curr_max = arr[0];
    LL ans = (LL) min(curr_max, back[0]) - (LL) arr[0];
    for(int i=1;i<n;++i){
        curr_max = max(arr[i], curr_max);
        ans += (LL) min(curr_max, back[i]) - (LL) arr[i];
    }
    cout<<ans<<endl;
}

void __solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];

    int l_max = 0, r_max = 0;
    int lo = 0, hi = n-1;
    int ans = 0;
    while (lo<=hi){
        if(arr[lo] < arr[hi]){
            if(l_max < arr[lo])
                l_max = arr[lo];
            else
                ans += l_max - arr[lo];
            ++lo;
        }
        else{
            if(r_max < arr[hi])
                r_max = arr[hi];
            else
                ans += r_max - arr[hi];
            --hi;
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
    while(tcases--){
        __solve();
    }
    return 0;
}