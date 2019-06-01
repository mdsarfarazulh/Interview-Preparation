/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
/* Should return true if trees with roots as r1 and 
   r2 are identical */
bool isIdentical(Node *r1, Node *r2)
{
    if(!r1 && !r2)
        return true;
    if(!r1 || !r2)
        return false;
    if(r1->data == r2->data)
        return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
    return false;
}