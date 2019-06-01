/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/
/*returns min element from stack*/
int _stack :: getMin()
{
    //Your code here
    if(s.empty())
        return -1;
    return minEle;
}
/*returns poped element from stack*/
int _stack ::pop()
{
    //Your code here
    if(s.empty())
        return -1;
    int ans;
    if(s.top()<minEle){
        ans = minEle;
        minEle = 2*minEle - s.top();
    }else{
        ans = s.top();
    }
    s.pop();
    return ans;
}
/*push element x into the stack*/
void _stack::push(int x)
{
    //Your code here
    if(s.empty()){
        s.push(x);
        minEle = x;
    }
    else if(x<minEle){
        s.push(2*x-minEle);
        minEle = x;
    }else{
        s.push(x);
    }
}
