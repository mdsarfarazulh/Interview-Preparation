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
    Node *random;
};
*/
/* The function should clone the passed tree and return 
   root of the cloned tree */

Node *getNode(int key){
    Node* newNode = NULL;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = key;
    newNode->left = newNode->right = newNode->random = NULL;
    return newNode;
}
Node* cloneTreeUtil(Node* tree, map<int, Node*> &mp){
    if(!tree)
        return tree;
    Node* root = getNode(tree->data);
    mp[root->data] = root;
    root->left = cloneTreeUtil(tree->left, mp);
    root->right = cloneTreeUtil(tree->right, mp);
    return root;
}
void setRandom(Node* root, Node* tree, map<int, Node*> &mp){
    if(!root)
        return;
    if(tree->random)
        root->random = mp[tree->random->data];
    else
        root->random = NULL;
    setRandom(root->left, tree->left, mp);
    setRandom(root->right, tree->right, mp);
}
Node* cloneTree(Node* tree){
    Node *root = NULL;
    map<int, Node*> mp;
    mp.clear();
    root = cloneTreeUtil(tree, mp);
    setRandom(root, tree, mp);
    return root;
}