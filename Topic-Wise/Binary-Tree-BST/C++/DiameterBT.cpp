/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
/* Computes the diameter of binary tree with given root.  */
int diameterUtil(Node *root, int &ans){
    if(!root)
        return 0;
    
    int left = diameterUtil(root->left, ans);
    int right = diameterUtil(root->right, ans);
    int temp = left + right + 1;
    if(temp>ans)
        ans = temp;
    return max(left, right) + 1;
}
int diameter(Node* node)
{
    // Your code here
    int ans = 0;
    diameterUtil(node, ans);
    return ans;
}