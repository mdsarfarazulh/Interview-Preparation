/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Structure of the Node of the binary tree is as
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/
// function should return the root of the new binary tree formed
struct Node * getNode(int key){
    struct Node* newNode = NULL;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* constructTreeUtil(int &it, int n, int pre[], char preLN[]){
    if(it>=n)
        return NULL;
    struct Node* root = getNode(pre[it]);
    if(preLN[it] == 'L')
        return root;
    root->left = constructTreeUtil(++it, n, pre, preLN);
    root->right = constructTreeUtil(++it, n, pre, preLN);
    return root;
}


struct Node *constructTree(int n, int pre[], char preLN[]){
    int it = 0;
    struct Node* root = NULL;
    if(!n)
        return root;
    root = constructTreeUtil(it, n, pre, preLN);
}