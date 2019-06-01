/*
    Problem:    https://practice.geeksforgeeks.org/problems/array-to-bst/0
    Editorial:  https://www.geeksforgeeks.org/sorted-array-to-balanced-bst/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

typedef struct Node{
    int data;
    struct Node *left, *right;
}Node;

Node* getNode(int key){
    Node* newNode = NULL;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* buildBST(int l, int r, vector<int> &arr){
    if(l>r)
        return NULL;
    Node* root;
    int m = l + (r-l)/2;
    root = getNode(arr[m]);
    if(l==r)
        return root;
    root->left = buildBST(l, m-1, arr);
    root->right = buildBST(m+1, r, arr);
    return root;
}

void preorder(Node* root){
    if(root){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];

    Node *root = NULL;
    root = buildBST(0, n-1, arr);
    preorder(root);
    cout<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tcases;
    cin>>tcases;
    while(tcases--)
        solve();
    return 0;
}