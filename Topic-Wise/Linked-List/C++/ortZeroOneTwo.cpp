/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
  Sort the list of 0's,1's and 2's
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     Node *next;
  }
*/

void sortList(Node *head)
{
    //Add code here
    int count[3];
    for(int i=0;i<3;++i)
        count[i] = 0;
    for(Node *ptr=head; ptr; ptr = ptr->next)
        count[ptr->data]++;
    Node *ptr;
    ptr = head;
    for(int i=0;i<3;++i){
        while(count[i]){
            ptr->data = i;
            --count[i];
            ptr = ptr->next;
        }
    }
}