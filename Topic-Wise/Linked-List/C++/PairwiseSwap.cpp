/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
  Pairwise swap a linked list
  The input list will have at least one element  
  node is defined as 
  struct node
  {
     int data;
     struct node *next;
  }
*/
struct node* Util(struct node *head)
{
    // The task is to complete this method
    if(!head || !head->next)
        return head;
    struct node *temp, *prev, *ptr, *next;
    prev = NULL;
    ptr = head;
    for(int i=0;i<2;++i){
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }
    temp = Util(next);
    head->next = temp;
    return prev;
}

void pairWiseSwap(struct node *head){
    head = Util(head);
    if(head->next)
        printf("%d ",head->data);
}