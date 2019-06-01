/* 
    Problem:    https://practice.geeksforgeeks.org/problems/minimum-platforms/0
    Editorial:  https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<pair<int, char> > arr;
    vector<int> a(n);
    vector<int> d(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=0;i<n;++i)
        cin>>d[i];
    
    for(int i=0;i<n;++i)
        arr.push_back({a[i], 'a'}), arr.push_back({d[i], 'd'});
    
    sort(arr.begin(), arr.end());

    int plat_needed = 0;
    int ans = 0;
    for(pair<int, char> v: arr){
        if(v.second == 'a')
            ++plat_needed;
        else
            --plat_needed;
        if(plat_needed>ans)
            ans = plat_needed;
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
        solve();
    }
}