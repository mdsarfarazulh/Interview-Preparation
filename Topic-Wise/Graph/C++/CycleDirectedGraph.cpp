
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

// The Graph structure is as folows
/*
class Graph 
{ 
	int V; 
	vector<int> *adj; 
    
public: 
    Graph(int V); 
	void addEdge(int u, int v); 
	int countPaths(int s, int d); 
}; 
Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new vector<int>[V+1]; 
} 
void Graph::addEdge(int u, int v) 
{ 
    adj[u].push_back(v); 
} 
*/
/*You are required to complete this method*/
bool dfs(int s, vector<bool> vis, vector<bool> insideStack, vector<int> adj[]){
    vis[s] = true;
    insideStack[s] = true;
    for(int v: adj[s]){
        if(!vis[v] && dfs(v, vis, insideStack, adj))
            return true;
        if(insideStack[v])
            return true;
    }
    insideStack[s] = false;
    return false;
}

bool Graph::isCyclic(int V)
{
    // Your Code Here
    vector<bool> vis(V, false), insideStack(V, false);
    bool flag = false;
    for(int i=0;i<V;++i){
        if(!vis[i]){
            flag = dfs(i, vis, insideStack, adj);
            if(flag)
                return flag;
        }
    }
    return flag;
}