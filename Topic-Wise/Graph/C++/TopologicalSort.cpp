
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* You need to complete this function */


void sort(int s, bool vis[],vector<int> graph[], stack<int>&S){
    vis[s]=true;
    vector<int>::iterator i;
    
    for(i=graph[s].begin();i!=graph[s].end();i++){
        if(!vis[*i]){
            sort(*i,vis,graph,S);
        }
    }
    S.push(s);
}
int * topoSort(vector<int> graph[], int N)
{
   // Your code here
   stack<int> S;
   bool * vis= new bool[N];
   int arr[N],k=0;
   for(int i=0;i<N;i++){
       vis[i]=false;
   }
   
   for(int i=0;i<N;i++){
       if(!vis[i]){
           sort(i,vis,graph,S);
       }
   }
   
   while(!S.empty()){
      // cout<<S.top()<<" ";
       arr[k++]=S.top();
       S.pop();
   }
   
  int *p=arr;
  return p;
}

