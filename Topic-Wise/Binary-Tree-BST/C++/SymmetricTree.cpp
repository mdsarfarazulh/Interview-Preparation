/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
Structure of the node of the tree is as
struct Node
{
	int key;
	struct Node* left, *right;
};
*/
// complete this function
// return true/false if the is Symmetric or not
bool isSymmetricUtil(Node *r1, Node *r2){
    if(!r1 && !r2)
        return true;
    if(!r1 || !r2)
        return false;
    if(r1->key == r2->key)
        return isSymmetricUtil(r1->left, r2->right) && isSymmetricUtil(r1->right, r2->left);
    return false;
}
bool isSymmetric(struct Node* root)
{
    // Code here
    return isSymmetricUtil(root, root);
}