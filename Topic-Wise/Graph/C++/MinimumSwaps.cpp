/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* You are required to complete this method */
void dfs(int s, int c_sum, bool vis[], unordered_map<int, int> &umap, int A[], int &ans){
    vis[s] = true;
    c_sum++;
    int u = umap[A[s]];
    if(!vis[u]){
        dfs(u, c_sum, vis, umap, A, ans);
    }else{
        ans += c_sum - 1;
        return;
    }
    
}
int minSwaps(int A[], int N){
    /*Your code here */
    unordered_map<int, int> umap;
    bool vis[N];
    memset(vis, false, sizeof(vis));
    for(int i=0;i<N;++i)
        umap[A[i]] = i;
    sort(A, A+N);
    int ans = 0;
    for(int i=0;i<N;++i)
        if(!vis[i])
            dfs(i, 0, vis, umap, A, ans);
    return ans;
}
