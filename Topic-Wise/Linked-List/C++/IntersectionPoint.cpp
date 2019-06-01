/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Link list Node 
struct Node {
    int data;
    struct Node* next;
}; */
/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int getLength(Node *head){
    if(!head)
        return 0;
    return getLength(head->next) + 1;
}
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int len_1 = getLength(head1);
    int len_2 = getLength(head2);
    Node *newHead1, *newHead2;
    newHead1 = head1;
    newHead2 = head2;
    if(len_1>len_2){
        while(len_1 != len_2){
            newHead1 = newHead1->next;
            len_1--;
        }
    }else{
        while(len_1 != len_2){
            newHead2 = newHead2->next;
            len_2--;
        }
    }
    
    while(newHead1 && newHead2 && newHead1 != newHead2){
        newHead1 = newHead1->next;
        newHead2 = newHead2->next;
    }
    return (newHead1)?newHead1->data:-1;
}