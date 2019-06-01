/*
    Problem:    https://practice.geeksforgeeks.org/problems/combination-sum-part-2/0
    Editorial:  
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void backtracking(int start, vector<int> &arr, vector<int> &ans, int sum, int B, vector<vector<int> > &res){
    if(sum == B){
        res.push_back(ans);
        return;
    }
    if(sum>B || start == arr.size())
        return;
    ans.push_back(arr[start]);
    sum += arr[start];
    backtracking(start+1, arr, ans, sum, B, res);
    sum -= ans[ans.size()-1];
    ans.pop_back();
    int endIndex = 0;
    for(int endIndex=start+1; endIndex<arr.size() && arr[endIndex]==arr[start]; ++endIndex)
        ++start;
    backtracking(start+1, arr, ans, sum, B, res);
}

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    int B;
    cin>>B;
    sort(arr.begin(), arr.end());
    vector<int> ans;
    vector<vector<int> > res;
    backtracking(0, arr, ans, 0, B, res);
    if(!res.size()){
        cout<<"Empty";
    }else{
        for(vector<int> V: res){
            cout<<"("<<V[0];
            for(int i=1;i<V.size();++i){
                cout<<" "<<V[i];
            }
            cout<<")";
        }
    }
    cout<<endl;
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