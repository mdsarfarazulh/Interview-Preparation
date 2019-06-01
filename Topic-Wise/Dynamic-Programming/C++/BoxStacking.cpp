/* 
    Problem:    https://practice.geeksforgeeks.org/problems/box-stacking/1
    Editorial:  https://www.geeksforgeeks.org/box-stacking-problem-dp-22/
*/

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The function takes an array of heights, width and 
length as its 3 arguments where each index i value 
determines the height, width, length of the ith box. 
Here n is the total no of boxes.*/

typedef struct box{
    int h, w, d;  
}box;

bool comparator(box a, box b){
    return (b.w * b.d) < (a.w * a.d);
}
int maxHeight(int height[],int width[],int length[],int n)
{
    //Your code here
    box arr[3*n];
    int index = 0;
    for(int i=0;i<n;++i){
        arr[index].h = height[i];
        arr[index].w = min(width[i], length[i]);
        arr[index].d = max(width[i], length[i]);
        ++index;
        arr[index].h = width[i];
        arr[index].w = min(height[i], length[i]);
        arr[index].d = max(height[i], length[i]);
        ++index;
        arr[index].h = length[i];
        arr[index].w = min(height[i], width[i]);
        arr[index].d = max(height[i], width[i]);
        ++index;
    }
    
    n = 3*n;
    sort(arr, arr+n, comparator);
    int msh[n];
    for(int i=0;i<n;++i)
        msh[i] = arr[i].h;
    
    for(int i=1;i<n;++i){
        for(int j=0;j<i;++j){
            if(arr[i].w < arr[j].w && arr[i].d < arr[j].d)
                msh[i] = max(msh[i], msh[j] + arr[i].h);
        }
    }
    int ans = -1;
    for(int i=0;i<n;++i)
        ans = max(ans, msh[i]);
    return ans;
}