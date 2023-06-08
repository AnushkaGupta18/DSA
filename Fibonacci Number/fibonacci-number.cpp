class Solution {
public:
    int fib(int n) {
        //we know that f(0) = 0 and f(1) = 1, so fib(2) = 1
        //base case
        int ans = 0;
        if (n==0) {
            return 0;
        }
        else if(n==1) {
            return 1;
        }

        ans = fib(n-1) + fib(n-2);
        return ans;
    }
};