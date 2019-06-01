/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of linked list is the following
struct Node
{
int data;
Node* next; 
};*/
/*The function removes the loop from the linked list if present
You are required to complete this method*/
void removeTheLoop(Node *head)
{
    //Your code here
    if(!detectloop(head))
        return; 
    
    Node *ptr, *fptr;
    ptr = fptr = head;
    while(true){
        ptr = ptr->next;
        fptr = fptr->next->next;
        if(ptr == fptr)
            break;
    }
    
    ptr = head;
    while(ptr->next != fptr->next){
        ptr = ptr->next;
        fptr = fptr->next;
    }
    
    fptr->next = NULL;
}
