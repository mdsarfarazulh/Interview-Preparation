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
int getLength(Node* head){
    int ans = 0;
    for(Node* ptr=head; ptr ;ptr=ptr->next)
        ++ans;
    return ans;
}
int intersectPoint(Node* head1, Node* head2){
    int l_1 = getLength(head1);
    int l_2 = getLength(head2);
    Node *ptr_1, *ptr_2;
    ptr_1 = head1;
    ptr_2 = head2;
    if(l_1>l_2){
        for(int i=1;i<=(l_1-l_2);++i){
            ptr_1 = ptr_1->next;
        }
    }else if(l_2>l_1){
        for(int i=1;i<=(l_2-l_1);++i)
            ptr_2 = ptr_2->next;
    }
    while(ptr_1 != ptr_2 && ptr_1 && ptr_2){
        ptr_1 = ptr_1->next;
        ptr_2 = ptr_2->next;
    }
    if(!ptr_1 || !ptr_2)
        return -1;
    return ptr_1->data;
}