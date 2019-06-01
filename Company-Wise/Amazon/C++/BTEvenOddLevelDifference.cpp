/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/*You are required to complete this function*/
int getLevelDiff(Node *root)
{
    //Your code here
    Node *curr;
    int level = 0;
    queue<Node*> Q;
    int even, odd;
    even = odd = 0;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty()){
        curr = Q.front();
        Q.pop();
        if(curr){
            if(level%2)
                odd += curr->data;
            else
                even += curr->data;
            if(curr->left)
                Q.push(curr->left);
            if(curr->right)
                Q.push(curr->right);
        }else{
            level++;
            if(Q.empty())
                break;
            Q.push(NULL);
        }
    }
    return (even - odd);
}
