/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of linked list is the following
struct node
{
int data;
Node* next;
};*/
int detectloop(Node *head)
{
    Node *ptr, *fptr;
    ptr = fptr = head;
    while(fptr && fptr->next){
        ptr = ptr->next;
        fptr = fptr->next->next;
        if(ptr == fptr)
            return 1;
    }
    return 0;
}