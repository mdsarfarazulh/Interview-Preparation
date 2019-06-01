/* 
    Problem:    https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array/0
    Editorial:  https://www.geeksforgeeks.org/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number/
*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long int

bool comparator(string X, string Y){
    string XY, YX;
    XY = X.append(Y);
    YX = Y.append(X);

    return XY.compare(YX) > 0 ? 1 : 0;
}

void solve(){
    int n;
    cin>>n;
    vector<string> arr(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    sort(arr.begin(), arr.end(), comparator);

    for(string w: arr)
        cout<<w;
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
    return 0;
}