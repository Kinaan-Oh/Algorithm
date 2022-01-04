// 출제의도: Monotone Stack, Time Complexity: O(n), Space Complexity: O(n) (n: temperatures.size)
// Kakao에 출제된적 있음.
// Stack은 단조감소상태로 원소들을 유지.
// stack에는 index만 넣어도 해결 가능하므로 Space Complexity를 개선할 수 있음.

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>  answer(temperatures.size(), 0);
        stack<pair<int,int>>    st; // (index, temperature)
        
        for(int i=0;i<temperatures.size();i++) {
            if(st.empty() || st.top().second>=temperatures[i]) {
                st.push({i,temperatures[i]});
            } else {
                while(!st.empty() && st.top().second<temperatures[i]) {
                    answer[st.top().first] = i-st.top().first;
                    st.pop();
                }
                st.push({i,temperatures[i]});
            }
        }
        return answer;
    }
};
