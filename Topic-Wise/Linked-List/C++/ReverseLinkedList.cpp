/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//function Template for C++
/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
  }
*/
// Should reverse list and return new head.
Node* reverse(Node *head){   // Iterative Approach
    // Your code here
    Node *ptr, *next, *prev;
    prev = NULL;
    ptr = head;
    while(ptr){
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }
    return prev;
}

Node *reverse(Node *head){  // Recursive Approach
    if(!head || !head->next)
        return head;
    
    Node *temp = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
} 