/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Node structure  used in the program
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom ;
}; */
/*  Function which returns the  root of 
    the flattened linked list. */
    
Node* merge(Node *a, Node *b){
    if(!a)
        return b;
    if(!b)
        return a;
    Node *result;
    if(a->data < b->data){
        result = a;
        result->bottom = merge(a->bottom, b);
    }
    else{
        result = b;
        result->bottom = merge(a, b->bottom);
    }
    return result;
}
Node* flatten(Node *root)
{
    // Your code here
    if(!root || !root->next)
        return root;
    return merge(root, flatten(root->next));
}