// Greedy, Time Complexity: O(l), Space Complexity: O(1) (l: s.length)
// 1. s의 각 alphabet의 마지막 index를 memoize.
// 2. s를 순회하면서 마지막 index를 갱신. 만약, 현재 index가 마지막 index와 같다면 해당 index는 partition의 경계가 되므로 partition 크기 계산하여 answer에 추가.

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int>    memo;
        vector<int>    answer;
        int begin = 0;
        int end = 0;
        
        for(int i=0;i<s.length();i++)   memo[s[i]] = i;
        for(int i=0;i<s.length();i++) {
            end = max(end, memo[s[i]]);
            
            if(i==end && memo[s[i]]==end) {
                answer.push_back(end-begin+1);
                begin = end+1;
            }
        }
        return answer;
    }
};
