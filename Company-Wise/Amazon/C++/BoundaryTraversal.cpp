/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

void printLeaf(Node *root){
    if(root){
        printLeaf(root->left);
        if(!root->left && !root->right)
            cout<<root->data<<" ";
        printLeaf(root->right);
    }
}

void printLeft(Node *root){
    if(root){
        if(root->left){
            cout<<root->data<<" ";
            printLeft(root->left);
        }else if(root->right){
            cout<<root->data<<" ";
            printLeft(root->right);
        }
    }
}

void printRight(Node *root){
    if(root){
        if(root->right){
            printRight(root->right);
            cout<<root->data<<" ";
        }else if(root->left){
            printRight(root->left);
            cout<<root->data<<" ";
        }
    }
}
void printBoundary(Node *root){
    //Your code here
    if(root){
        cout<<root->data<<" ";
        printLeft(root->left);
        printLeaf(root->left);
        printLeaf(root->right);
        printRight(root->right);
    }
}