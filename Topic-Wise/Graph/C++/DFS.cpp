/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* You have to complete this function
which prints out the depth first level traversal of the 
graph starting from node s
the vector<int> g[i] represent the adjacency 
list of the ith node of the graph
 */
void dfs(int s, vector<int> g[], bool vis[])
{
    // Your code here
    cout<<s<<" ";
    vis[s] = true;
    for(int v: g[s])
        if(!vis[v])
            dfs(v, g, vis);
}