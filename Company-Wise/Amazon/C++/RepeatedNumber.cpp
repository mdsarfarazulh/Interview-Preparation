int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<char> count(A.size()+1, '0');
    for(int v: A){
        if(count[v]=='1')
            return v;
        count[v] = '1';
    }
    return -1;
}
