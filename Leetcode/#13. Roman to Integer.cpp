// Math/HashTable, Time Complexity: O(l), Space Complexity: O(1) (l: s.length)

class Solution {
public:
    int romanToInt(string s) {
        int answer = 0;
        unordered_map<string, int>  ht;
        string prev;
        
        ht["I"] = 1; 
        ht["IV"] = 4; 
        ht["IX"] = 9;
        ht["V"] = 5;
        ht["X"] = 10; 
        ht["XL"] = 40; 
        ht["XC"] = 90;
        ht["L"] = 50;
        ht["C"] = 100; 
        ht["CD"] = 400; 
        ht["CM"] = 900;
        ht["D"] = 500;
        ht["M"] = 1000;
        
        for(auto c: s) {
            prev += c;
            
            if(ht.find(prev) == ht.end()) {
                answer += ht[prev.substr(0, prev.size()-1)];
                prev = prev.back();
            }
        }
        answer += ht[prev];
        return answer;
    }
};
