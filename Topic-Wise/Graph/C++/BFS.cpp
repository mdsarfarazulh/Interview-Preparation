/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* You have to complete this function*/
void bfs(int s, vector<int> adj[], bool vis[])
{
    // Your code here
    queue<int> Q;
    int v;
    Q.push(s);
    vis[s] = true;
    while(!Q.empty()){
        s = Q.front();
        Q.pop();
        cout<<s<<" ";
        for(int v: adj[s]){
            if(!vis[v]){
                Q.push(v);
                vis[v] = true;
            }
        }
    }
}