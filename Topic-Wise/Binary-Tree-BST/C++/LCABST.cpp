/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of a BST Node is as follows:
struct Node {
    int data;
    Node * right, * left;
};*/
/*You are required to complete
this function*/

bool find(Node *root, int key){
    if(!root)
        return false;
    if(root->data == key)
        return true;
    if(key < root->data)
        return find(root->left, key);
    return find(root->right, key);
}
Node* LCAUtil(Node *root, int n1, int n2){
    if(!root)
        return NULL;
    if(root->data == n1 || root->data == n2)
        return root;
    if((root->data > n1 && root->data < n2) || (root->data < n1 && root->data > n2))
        return root;
    if(root->data < n1 && root->data < n2)
        return LCAUtil(root->right, n1, n2);
    return LCAUtil(root->left, n1, n2);
}
Node* LCA(Node *root, int n1, int n2)
{
    //Your code here
    if(find(root, n1) && find(root, n2))
        return LCAUtil(root, n1, n2);
    return NULL;
}