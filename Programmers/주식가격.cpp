// 출제의도: "스택", Time Complexity: O(n), Space Complexity: O(n). (n: prices.size)
// Leetcode #84_Largest Rectangle in Histogram 문제와 동일한 원리.(이 문제의 난이도가 더 낮음)

#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std; 

stack<pair<int,int>>  st;   // (price,index)

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    for(int i=0;i<prices.size();i++) {
        if(st.empty() || st.top().first<=prices[i]) {
            st.push({prices[i],i});
        }
        else {
            while(!st.empty() && st.top().first>prices[i]) {
                answer[st.top().second] = i-st.top().second;
                st.pop();
            }
            st.push({prices[i],i});
        }
    }
    while(!st.empty()) {
        answer[st.top().second] = prices.size()-1-st.top().second;
        st.pop();
    }
    return answer;
}
