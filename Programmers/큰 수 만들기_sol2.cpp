// 출제의도: "greedy", Time Complexity: O(n), Space Complexity: O(1). (n: number.size)
// 스택 자료구조를 이용하여 해결.

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<char> st;
    int num_of_del = k;
    for(int i=0;i<number.size();i++) {
        while(!st.empty() && st.back()<number[i] && num_of_del) {
            st.pop_back();
            num_of_del--;
        }
        
        st.push_back(number[i]);
    }
    while(num_of_del--) {
        st.pop_back();
    }
    for(int i=0;i<st.size();i++)    answer += st[i];
    return answer;
}
