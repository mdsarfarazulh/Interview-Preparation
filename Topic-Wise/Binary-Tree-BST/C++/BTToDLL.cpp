/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Structure for tree and linked list
struct Node
{
    int data;
    // left is used as previous and right is used
    // as next in DLL
    Node *left, *right;
}; */
// This function should convert a given Binary tree to Doubly
// Linked List

void BToDLLUtil(Node *root, Node* &prev, Node* &head){
    if(root){
        BToDLLUtil(root->left, prev, head);
        root->left = prev;
        if(!head){
            head = root;
            prev = root;
        }else{
            prev->right = root;
            prev = prev->right;
        }
        BToDLLUtil(root->right, prev, head);
    }
}
void BToDLL(Node *root, Node **head_ref)
{
    Node *head = NULL;
    Node *prev = NULL;
    BToDLLUtil(root, prev, head);
    prev->right = NULL;
    *head_ref = head;
}
