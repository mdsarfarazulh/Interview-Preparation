/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node {
    int data;
    Node* left, * right;
}; */

bool isBSTUtil(Node* root, int &prev){
    if(root){
        bool left = isBSTUtil(root->left, prev);
        if(root->data<prev){
            return false;
        }
        prev = root->data;
        bool right = isBSTUtil(root->right, prev);
        return right && left;
    }
    return true;
}
bool isBST(Node* root) {
    // Your code here
    int prev = -1;
    return isBSTUtil(root, prev);
}
