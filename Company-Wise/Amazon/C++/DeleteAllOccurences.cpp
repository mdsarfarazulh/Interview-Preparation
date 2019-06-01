/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Link list Node 
struct Node
{
    int data;
    Node* next;
};*/
/*You are required to complete below method*/
Node* deleteAllOccurances(Node *head,int x){
    Node *temp;
    while(head->data == x && head){
        temp = head;
        head = temp->next;
        free(temp);
    }

    Node* ptr = head;
    while(ptr && ptr->next){
        if(ptr->next->data == x){
            temp = ptr->next;
            ptr->next = temp->next;
            free(temp);
        }
        else
            ptr = ptr->next;
    }
    return head;
}