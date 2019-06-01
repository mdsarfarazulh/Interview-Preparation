/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
  Reverse a linked list
  The input list will have at least one element  
  Return pointer to head of reverse linked list 
  Node is defined as 
  struct node
  {
     int data;
     struct Node *next;
  }
*/
struct node *reverse (struct node *head, int k)
{ 
    if(!head)
        return head;

    struct node *ptr, *prev, *next;
    prev = NULL;
    ptr = head;
    for(int i=0;i<k && ptr;++i){
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }
    struct node *temp = reverse(next, k);
    head->next = temp;
    return prev;
}