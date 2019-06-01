/*
    Problem:    https://practice.geeksforgeeks.org/problems/find-median-in-a-stream/0
    Editorial:  https://www.geeksforgeeks.org/median-of-stream-of-integers-running-integers/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

void solve(){
    int n;
    cin>>n;
    int temp, num;
    priority_queue<int> max_heap, min_heap;

    int median = -1;
    for(int i=0;i<n;++i){
        cin>>num;
        if(max_heap.size() > min_heap.size()){
            if(num<median){
                min_heap.push(-1*max_heap.top());
                max_heap.pop();
                max_heap.push(num);
            }else{
                min_heap.push(-1*num);
            }
            median = (-1*min_heap.top() + max_heap.top())/2;
        }else if(min_heap.size() > max_heap.size()){
            if(num>median){
                max_heap.push(-1*min_heap.top());
                min_heap.pop();
                min_heap.push(-1*num);
            }else{
                max_heap.push(num);
            }
            median = (-1*min_heap.top() + max_heap.top())/2;
        }else{
            if(num < median){
                max_heap.push(num);
                median = max_heap.top();
            }else{
                min_heap.push(-1*num);
                median = -1*min_heap.top();
            }
        }
        cout<<median<<" ";
    }
    cout<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}