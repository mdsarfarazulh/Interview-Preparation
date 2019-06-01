
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The function prints V space separated integers where 
    the ith integer denote the shortest distance of ith vertex
    from source vertex */
void dijkstra(int graph[MAX][MAX], int s,int V)
{
    //Your code here
    int dis[V];
    //memset(dis, INT_MAX, sizeof(dis));
    for(int i=0;i<V;++i)
        dis[i] = INT_MAX;
    priority_queue<pair<int, int> > Q;
    dis[s] = 0;
    Q.push(make_pair(-1*dis[s], s));
    int u, v;
    pair<int, int> node;
    while(!Q.empty()){
        node = Q.top();
        Q.pop();
        u = node.second;
        for(v=0;v<V;++v){
            if(v==u)
                continue;
            if(dis[v] > (dis[u] + graph[u][v])){
                dis[v] = dis[u] + graph[u][v];
                Q.push(make_pair(-1*dis[v], v));
            }
        }
    }
    for(int i=0;i<V;++i)
        cout<<dis[i]<<" ";
}