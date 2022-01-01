// 출제의도: Greedy/ Sort, Time Complexity: O(nklgn), Space Complexity: O(n). (n: nums.size, k:largest length of nums)
// string a,b 간 비교 연산 비용은 a, b의 length에 비례하므로 time complexity는 엄밀히 nlgn * k 가 됨.
// 단순하게 lexicographic order로 배치하는 것은 정답이 아님을 예시를 통해 hint를 제공하고 있음.
// 따라서, concatenate한 결과를 비교하는 방법을 떠올려야함. 단순한 idea지만 의외로 떠올리기는 쉽지않았음.


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string answer;
        vector<string>  nums_string;
        
        for(auto i: nums)   nums_string.push_back(to_string(i));
        sort(nums_string.begin(), nums_string.end(), [](string &s1, string &s2){ return s1+s2>s2+s1; });
        for(auto s: nums_string)    answer += s;  
        return answer.front() == '0' ? "0" : answer;
    }
};
