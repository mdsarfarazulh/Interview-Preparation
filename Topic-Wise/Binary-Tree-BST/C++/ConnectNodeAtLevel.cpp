/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */
// Should set the nextRight for all nodes
void connect(Node *p)
{
    // Your Code Here
    Node *curr;
    queue<Node*> Q;
    Q.push(p);
    Q.push(NULL);
    while(!Q.empty()){
        curr = Q.front();
        Q.pop();
        if(curr){
            curr->nextRight = Q.front();
            if(curr->left)
                Q.push(curr->left);
            if(curr->right)
                Q.push(curr->right);
        }else{
            if(Q.empty())
                break;
            Q.push(NULL);
        }
    }
}
