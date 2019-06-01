/* 
    Problem:    https://practice.geeksforgeeks.org/problems/unsorted-array/0
    Editorial:  https://www.geeksforgeeks.org/find-the-element-before-which-all-the-elements-are-smaller-than-it-and-after-which-all-are-greater-than-it/
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
    
    int possible_answer = -1;
    int largest = 0;
    for(int i=1;i<n-1;++i){
        if(arr[largest] > arr[i]){
            if(possible_answer != -1 && arr[i]<arr[possible_answer])
                possible_answer = -1;
        }
        else if(arr[largest] <= arr[i]){
            if(possible_answer == -1)
                possible_answer = i;
            else{
                if(arr[i] < arr[possible_answer])
                    possible_answer = -1;
            }
            largest = i;
        }
    }
    if(possible_answer !=-1 && arr[n-1]<arr[possible_answer])
        possible_answer = -1;
    if(possible_answer == -1)
        cout<<possible_answer<<endl;
    else
        cout<<arr[possible_answer]<<endl;
}

void _solve(){
    int n;
    cin>>n;
    vector<int> arr(n), left_max(n), right_min(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    left_max[0] = arr[0];
    right_min[n-1] = arr[n-1];
    for(int i=1;i<n;++i)
        if(arr[i]>left_max[i-1])
            left_max[i] = arr[i];
        else
            left_max[i] = left_max[i-1];

    for(int i=n-2;i>=0;--i)
        if(arr[i]<right_min[i+1])
            right_min[i] = arr[i];
        else
            right_min[i] = right_min[i+1];
    for(int i=1;i<n-1;++i){
        if(arr[i]==left_max[i] && arr[i]==right_min[i]){
            cout<<arr[i]<<endl;
            return;
        }
    }
    cout<<"-1"<<endl;
}

void __solve(){
    int n;
    cin>>n;
    vector<int> arr(n), right_min(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    
    right_min[n-1] = arr[n-1];
    for(int i=n-2;i>=0;--i)
        if(right_min[i+1] > arr[i])
            right_min[i] = arr[i];
        else
            right_min[i] = right_min[i+1];
    
    int left_max = arr[0];
    for(int i=1;i<n-1;++i){
        if(left_max < arr[i]){
            left_max = arr[i];
        }
        if(arr[i]>=left_max && arr[i]<=right_min[i]){
            cout<<arr[i]<<endl;
            return;
        }
    }
    cout<<"-1"<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tcases;
    cin>>tcases;
    while(tcases--){
        _solve();
    }
}