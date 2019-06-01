/*
    Problem:    https://practice.geeksforgeeks.org/problems/trie-insert-and-search/0
    Editorial:  https://www.geeksforgeeks.org/trie-insert-and-search/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

typedef struct Node{
    struct Node* ptrTo[26];
    bool isEndOfWord;
}Node;

Node* getNode(){
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
    for(int i=0;i<26;++i)
        newNode->ptrTo[i] = NULL;
    newNode->isEndOfWord = false;
    return newNode;
}

void insert(Node *root, string word){
    Node *curr = root;
    for(char c: word){
        if(!curr->ptrTo[c - 'a'])
            curr->ptrTo[c-'a'] = getNode();
        curr = curr->ptrTo[c-'a'];
    }
    curr->isEndOfWord = true;
}

bool search(Node *root, string word){
    Node *curr = root;
    for(char c: word){
        if(!curr->ptrTo[c-'a']){
            return false;
        }
        curr = curr->ptrTo[c-'a'];
    }
    if(!curr->isEndOfWord)
        return false;
    return true;
}

void solve(){
    int n;
    cin>>n;
    string str;
    Node* root = getNode();
    for(int i=0;i<n;++i){
        cin>>str;
        insert(root, str);
    }
    cin>>str;
    cout<<search(root, str)<<endl;
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