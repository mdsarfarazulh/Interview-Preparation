/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
  Rotate a linked list after node k
  The input list will have at least one element  
  A Linked List node has following structure.
  struct node
  {
     int data;
     struct node *next;
  }
*/
/*  **head_ref is a pointer to head pointer.  This function
    should modify value at head_ref to change head (if required)*/
void rotate(struct node **head_ref, int k){
    struct node *ptr, *newHead;
    ptr = *head_ref;
    int count = 1;
    while((count++)<k && ptr)
        ptr = ptr->next;

    if(count<k-1 || !ptr->next)
        return;
    newHead = ptr->next;
    ptr->next = NULL;
    ptr = newHead;
    while(ptr->next)
        ptr = ptr->next;
    ptr->next = *head_ref;
    *head_ref = newHead;
}