/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node structure
struct Node {
    int data;
    Node* left, * right;
}; */
// This function should return tree if passed  tree 
// is balanced, else false. 
int isBalancedUtil(Node *root, bool &ans){
    if(!root)
        return 0;
    int left = isBalancedUtil(root->left, ans);
    int right = isBalancedUtil(root->right, ans);
    if(abs(left - right)>1)
        ans = false;
    return max(left, right) + 1;
}

bool isBalanced(Node *root)
{
    //  Your Code here
    bool ans = true;
    isBalancedUtil(root, ans);
    return ans;
}
