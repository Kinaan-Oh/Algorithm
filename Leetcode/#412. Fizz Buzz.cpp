// Math, Time Complexity: O(n), Space Complexity: O(n)

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>  answer;
        
        for(int i=1;i<=n;i++) {
            string s;
            bool divisibleBy3 = i%3==0 ;
            bool divisibleBy5 = i%5==0;
            
            if(divisibleBy3)    s += "Fizz";
            if(divisibleBy5)    s += "Buzz";
            if(s.empty())   s = to_string(i);
            
            answer.push_back(s);
        }
        return answer;
    }
};
