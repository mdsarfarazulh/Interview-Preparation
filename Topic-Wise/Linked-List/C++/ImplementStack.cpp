/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* 
The structure of the node of the stack is
struct StackNode
{
    int data;
    StackNode *next;
    StackNode(int a)
    {
        data = a;
        next = NULL;
    }
};
// And this is structure of MyStack
class MyStack {
private:
StackNode *top;
public :
    void push(int);
    int pop();
    MyStack()
    {
        top = NULL;
    }
};
/* The method push to push element 
   into the stack */
   
StackNode* getNode(int key){
    StackNode *newNode = NULL;
    newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->data = key;
    newNode->next = NULL;
    return newNode;
}
void MyStack :: push(int x)
{
    // Your Code
    StackNode *newNode = getNode(x);
    newNode->next = top;
    top = newNode;
}
/* The method pop which return the element 
  poped out of the stack*/
int MyStack :: pop()
{
    // Your Code    
    int ans;
    if(!top)
        return -1;
    ans = top->data;
    StackNode *temp = top;
    top = temp->next;
    temp->next = NULL;
    free(temp);
    return ans;
}