/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* struct Node
 {
   int data;
   Node* next;
 }; */
/* Should return data of n'th node from the end of linked list */
int getNthFromLast(Node *head, int n)
{
    // Your code here
    Node *ptr, *fptr;
    ptr = fptr = head;
    
    int count = 1;
    while(count++<n && fptr)
        fptr = fptr->next;
    if(!fptr && count<=n)
        return -1;
    while(fptr->next){
        fptr = fptr->next;
        ptr = ptr->next;
    }
    return ptr->data;
}