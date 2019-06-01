/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Tree node class
struct Node
{
    int data; 
    Node *left, *right; 
}; */
// Method that prints the bottom view.
void bottomViewUtil(Node *root, int dis, map<int, int> &_map){
    if(root){
        bottomViewUtil(root->left, dis-1, _map);
        _map[dis] = root->data;
        bottomViewUtil(root->right, dis+1, _map);
    }
}
void bottomView(Node *root)
{
    // Your Code Here
    map<int, int> _map;
    bottomViewUtil(root, 0, _map);
    for(auto it=_map.begin(); it!=_map.end(); ++it)
        cout<<it->second<<" ";
}
