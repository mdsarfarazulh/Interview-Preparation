/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of the Node is
struct Node
{
    int data;
    struct Node* next;
};*/
/*You are required to complete this method */
Node* reverse(Node *head){
    if(!head || !head->next)
        return head;
    Node *temp = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}
bool isPalindrome(Node *head)
{
    //Your code here
    Node *ptr, *fptr;
    ptr = fptr = head;
    while(fptr->next && fptr->next->next){
        ptr = ptr->next;
        fptr = fptr->next->next;
    }
    ptr->next = reverse(ptr->next);
    ptr = ptr->next;
    fptr = head;
    while(ptr){
        if(ptr->data != fptr->data){
            return false;
        }
        ptr = ptr->next;
        fptr = fptr->next;
    }
    return true;
}