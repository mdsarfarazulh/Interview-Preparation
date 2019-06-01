/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
void verticalOrderUtil(Node *root, int dist, map<int, vector<int> > &_map){
    if(root){
        _map[dist].push_back(root->data);
        verticalOrderUtil(root->left, dist-1, _map);
        verticalOrderUtil(root->right, dist+1, _map);
    }
}
void verticalOrder(Node *root)
{
    //Your code here
    map<int, vector<int> > _map;
    verticalOrderUtil(root, 0, _map);
    for(auto it=_map.begin();it!=_map.end();++it){
        for(int v: it->second){
            cout<<v<<" ";
        }
    }
}