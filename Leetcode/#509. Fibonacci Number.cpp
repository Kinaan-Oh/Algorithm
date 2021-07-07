// "Recursive", Time Complexity: O(2^n), Space Complexity: O(n).
// F(n) = F(n-1) + F(n-2) < 2*F(n-1) 이므로 F(n) Time Complexity의 상한으로 O(2^n)을 잡을 수 있다.

class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1)    return n;
        
        return fib(n-1) + fib(n-2);
    }
};
