/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
void printSpiral(Node *root)
{
    //Your code here
    int level = 1;
    queue<Node *> Q;
    stack<int> S;
    Node *curr;
    Q.push(root);
    Q.push(NULL);
    
    while(!Q.empty()){
        curr = Q.front();
        Q.pop();
        if(curr){
            if(level%2)
                S.push(curr->data);
            else
                cout<<curr->data<<" ";
            if(curr->left)
                Q.push(curr->left);
            if(curr->right)
                Q.push(curr->right);
        }else{
            if(level%2){
                while(!S.empty()){
                    cout<<S.top()<<" ";
                    S.pop();
                }
            }
            level = (level+1)%2;
            if(Q.empty())
                break;
            Q.push(NULL);
        }
    }
}