/*
    Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

    For example:
    Given the array [-2,1,-3,4,-1,2,1,-5,4],
    the contiguous subarray [4,-1,2,1] has the largest sum = 6.
    For this problem, return the maximum sum.
*/
int Solution::maxSubArray(const vector<int> &A) {
    int max_so_far = INT_MIN;
    int sum_so_far = 0;
    for(int i=0;i<A.size();++i){
        sum_so_far = max(sum_so_far+A[i], A[i]);
        max_so_far = max(max_so_far, sum_so_far);
    }
    return max_so_far;
}
