/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the function below
Node is as follows:
struct Node{
	int data;
	Node *left,*right;
};
*/

void util(Node *root, Node* &head, Node* &prev)
{
    if(!root)
        return;
    if(!root->left && !root->right){
        if(!head){
            head = root;
            root->left = prev;
            prev = root;
        }
        else{
            root->left = prev;
            prev->right = root;
            prev = prev->right;
        }
        return;
    }
    if(root->left)
        util(root->left, head, prev);
    if(root->right)
        util(root->right, head, prev);
}
Node *convertToDLL(Node *root,Node **head_ref)
{
    //add code here.
    Node *prev = NULL;
    *head_ref = NULL;
    util(root, *head_ref, prev);
    return *head_ref;
    
}