/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Link list Node 
struct Node {
    int data;
    Node* next;
}; */
/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
    // Your code here
    Node *ptr, *fptr;
    ptr = fptr = head;
    while(fpt && fptr->next){
        fptr = fptr->next->next;
        ptr = ptr->next;
    }
    return ptr->data;
}
