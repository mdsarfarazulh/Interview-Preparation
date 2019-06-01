/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Link list Node  
struct Node {
    int data;
    Node* next;
}; */
Node* SortedMerge(Node* head1,   Node* head2)
{
    // Your Code Here
    Node *head = NULL, *temp, *ptr;
    while(head1 && head2){
        if(head1->data<head2->data){
            temp = head1;
            head1 = temp->next;
            temp->next = NULL;
        }else{
            temp = head2;
            head2 = temp->next;
            temp->next = NULL;
        }
        
        if(!head){
            head = temp;
            ptr = head;
        }else{
            ptr->next = temp;
            ptr = ptr->next;
        }
    }
    ptr->next = (head1)?head1:head2;
    return head;
}