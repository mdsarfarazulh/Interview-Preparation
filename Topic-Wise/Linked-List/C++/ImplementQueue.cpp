/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};
And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */
/* The method push to push element into the queue*/
void MyQueue:: push(int x)
{
    // Your Code
    QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = x;
    newNode->next = NULL;
    if(!front){
        front = newNode;
        rear = newNode;
    }else{
        rear->next = newNode;
        rear = rear->next;
    }
}
/*The method pop which return the element
  poped out of the queue*/
int MyQueue :: pop()
{
    // Your Code  
    if(!front)
        return -1;
    QueueNode *temp = front;
    front = front->next;
    int ans = temp->data;
    free(temp);
    return ans;
}
