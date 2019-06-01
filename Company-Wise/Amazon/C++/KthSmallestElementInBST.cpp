/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    int lCount;
 
    Node* left;
    Node* right;
};*/

void KthSmallestElementUtil(Node *root, int &k, int &ans){
    if(root){
        KthSmallestElementUtil(root->left, k, ans);
        --k;
        if(!k){
            ans = root->data;
            return;
        }
        KthSmallestElementUtil(root->right, k, ans);
    }
}

int KthSmallestElement(Node *root, int k){
    int ans = -1;
    KthSmallestElementUtil(root, k, ans);
    return ans;
}