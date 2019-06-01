/* 
    Problem:    https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0
    Editorial:  https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i)
        cin>>arr[i];
    
    int jumps[n];
    jumps[0] = 0;
    for(int i=1;i<n;++i){
        jumps[i] = INT_MAX;
        for(int j=0;j<i;++j){
            if(i<=j+arr[j] && jumps[j]!=INT_MAX){
                jumps[i] = min(jumps[i], jumps[j]+1);
                break;
            }
        }
    }
    cout<<jumps[n-1]<<endl;
}

void _solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i)
        cin>>arr[i];
    int maxReach = arr[0];
    int step = arr[0];
    int jump = 1;
    int flag = 0;
    if(!arr[0]){
        cout<<"-1"<<endl;
        return;
    }
    for(int i=1;i<n;++i){
        if(i == n-1){
            flag = 1;
            break;
        }
        if(i+arr[i] > maxReach)
            maxReach = i + arr[i];
        step--;

        if(!step){
            jump++;
            if(i >= maxReach){
                cout<<"-1"<<endl;
                return;
            }
            step = maxReach - i;
        }
    }
    if(flag)
        cout<<jump<<endl;
    else
        cout<<"-1"<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tcases;
    cin>>tcases;
    while(tcases--)
        _solve();
    return 0;
}