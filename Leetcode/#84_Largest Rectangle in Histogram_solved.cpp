// Time Complexity: O(heights.length).
//자료구조 Stack 사용. (Vector로 관리할 수 있지만, Stack은 높이 크기순으로 정렬된 상태를 유지하므로 스택 내 모든 원소와 비교할 필요가 없는 반면, Vector는 전부 비교해야하므로 O((heights.length)^2)이 됨.)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int N = heights.size();
        int largestRectangleArea = 0;
        int left[N], right[N];
        fill(left,left+N,-1);
        fill(right,right+N,N);
        
        stack<int> st; 
        for(int i=0;i<N;i++)
        {
            while(!st.empty() && heights[i]<heights[st.top()])
            {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())  st.pop();
        for(int i=N-1;i>=0;i--)
        {
            while(!st.empty() && heights[i]<heights[st.top()])
            {
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        for(int i=0;i<N;i++)   largestRectangleArea = max(largestRectangleArea, heights[i]*(right[i]-left[i]-1));
        return largestRectangleArea;
    }
};
