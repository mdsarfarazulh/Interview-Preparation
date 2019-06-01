
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
class Graph 
{ 
	int V; 
	vector<int> *adj; 
	vector<int> *transpose_adj;
    void transpose();
    
public: 
    Graph(int V); 
	void addEdge(int u, int v); 
	int kosaraju();
}; 
Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new vector<int>[V+1]; 
	transpose_adj = new vector list<int>[V+1];
} 
void Graph::addEdge(int u, int v) 
{ 
    adj[u].push_back(v); 
} 
void Graph::transpose()
{
    for(int u=1;u<=V;u++)
        for(auto v : adj[u])
            transpose_adj[v].push_back(u);
}
*/
// Function to find number of Stongly Connected Components
void topoSort(int s, bool vis[], stack<int> &S, vector<int> *adj){
    vis[s] = true;
    for(int v: adj[s])
        if(!vis[v])
            topoSort(v, vis, S, adj);
    S.push(s);
}

void dfs(int s, bool vis[], vector<int> *transpose_adj){
    vis[s] = true;
    for(int v: transpose_adj[s])
        if(!vis[v])
            dfs(v, vis, transpose_adj);
}

int Graph::kosaraju()
{
    // Your code here
    bool vis[V+1];
    memset(vis, false, sizeof(vis));
    stack<int> S;
    for(int i=1;i<=V;++i){
        if(!vis[i]){
            topoSort(i, vis, S, adj);
        }
    }
    
    
    int ans = 0;
    memset(vis, false, sizeof(vis));
    int u;
    transpose(); 
    while(!S.empty()){
        u = S.top();
        S.pop();
        if(!vis[u]){
            ++ans;
            dfs(u, vis, transpose_adj);
        }
    }
    return ans;
}