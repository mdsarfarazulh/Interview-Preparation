/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

 
/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
// Function to merge the two sorted linked lists
// head1, head2: head of the two sorted linked lists
Node* sortedMerge(Node* head1,   Node* head2)
{
    // Your Code Here
    Node *head = NULL, *temp, *ptr;
    while(head1 && head2){
        if(head1->data > head2->data){
            temp = head2;
            head2 = head2->next;
        }else{
            temp = head1;
            head1 = head1->next;
        }
        temp->next = NULL;
        if(!head){
            head = temp;
            ptr = head;
        }else{
            ptr->next = temp;
            ptr = ptr->next;
        }
    }
    
    if(head1)
        ptr->next = head1;
    if(head2)
        ptr->next = head2;
    return head;
}
