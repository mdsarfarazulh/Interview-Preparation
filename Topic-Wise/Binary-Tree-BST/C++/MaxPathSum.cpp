/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the function below
Node is as follows
struct Node{
	int data;
	Node *left, *right;
};
*/
int maxPathUtil(Node *root, int &ans){
    if(!root)
        return 0;
    int left = maxPathUtil(root->left, ans);
    int right = maxPathUtil(root->right, ans);
    int temp = left+right+root->data;
    if(temp > ans)
        ans = temp;
    return max(left, right) + root->data;
}
int maxPathSum(struct Node *root)
{
    //add code here.
    int ans = INT_MIN;
    maxPathUtil(root, ans);
    return ans;
}