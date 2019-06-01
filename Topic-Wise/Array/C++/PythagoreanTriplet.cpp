/* 
    Problem:    https://practice.geeksforgeeks.org/problems/pythagorean-triplet/0
    Editorial:  https://www.geeksforgeeks.org/find-pythagorean-triplet-in-an-unsorted-array/
*/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
        arr[i] = arr[i]*arr[i];
    }
    sort(arr.begin(), arr.end());
    
    for(int i=n-1;i>=2;--i){
        for(int j=0, k=i-1;j<k;){
            if(arr[i] == (arr[j] + arr[k])){
                cout<<"Yes"<<endl;
                return;
            }
            else if(arr[i] < (arr[j] + arr[k]))
                k--;
            else
                j++;
        }
    }
    cout<<"No"<<endl;
    return;
}
int main()
 {
	//code
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