/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
// A wrapper over leftViewUtil()
void leftView(Node *root)   // Iterative
{
    // Your code here
    queue<Node*> Q;
    Node *curr;
    Q.push(root);
    Q.push(NULL);
    cout<<root->data<<" ";
    while(!Q.empty()){
        curr = Q.front();
        Q.pop();
        if(curr){
            if(curr->left)
                Q.push(curr->left);
            if(curr->right)
                Q.push(curr->right);
        }else{
            if(Q.empty()){
                break;
            }
            cout<<Q.front()->data<<" ";
            Q.push(NULL);
        }
    }
}


void leftViewUtil(Node *root, int level, int &maxLevel){    // Recursive
    if(!root)
        return;
    if(level>maxLevel){
        cout<<root->data<<" ";
        maxLevel = level;
    }
    
    leftViewUtil(root->left, level+1, maxLevel);
    leftViewUtil(root->right, level+1, maxLevel);
}

void leftView(Node *root)
{
    int level = 0;
    int maxLevel = -1;
    leftViewUtil(root, level, maxLevel);
}