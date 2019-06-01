/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*struct Node
{
    int data;
   Node* next;
}; */
//write a function returns the resultant linked list

Node *getNode(int key){
    Node* newNode = NULL;
    newNode = (Node *)malloc(sizeof(newNode));
    newNode->data = key;
    newNode->next = NULL;
    return newNode;
}
Node*  addTwoLists(Node* first, Node* second){
    // Code here
    
    Node *f, *s;
    f = first;
    s = second;
    int carry = 0;
    int sum = 0;
    Node *ptr = NULL;
    Node *head = NULL;
    while(s && f){
        sum = s->data + f->data + carry;
        carry = sum/10;
        if(!head){
            head = getNode(sum%10);
            ptr = head;
        }else{
            ptr->next = getNode(sum%10);
            ptr = ptr->next;
        }
        s = s->next;
        f = f->next;
    }
    while(s){
        sum = s->data + carry;
        carry = sum/10;
        if(!head){
            head = getNode(sum%10);
            ptr = head;
        }else{
            ptr->next = getNode(sum%10);
            ptr = ptr->next;
        }
        s = s->next;
    }
    while(f){
        sum = f->data + carry;
        carry = sum/10;
        if(!head){
            head = getNode(sum%10);
            ptr = head;
        }else{
            ptr->next = getNode(sum%10);
            ptr = ptr->next;
        }
        f = f->next;
    }
    if(carry){
        if(!head){
            head = getNode(carry);
            ptr = head;
        }else{
            ptr->next = getNode(carry);
            ptr = ptr->next;
        }
    }
    return head;
}