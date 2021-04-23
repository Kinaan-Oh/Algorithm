// Time Complexity: O((heights.length)^2). failed1 보다 시간복잡도가 좋지 않음.

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largestRectangleArea = 0;
        for(int i=0;i<heights.size();i++)
        {
            int left = i, right = i;
            for(;left>=0 && heights[left]>=heights[i];left--)   {}
            for(;right<heights.size() && heights[right]>=heights[i];right++)   {}
            largestRectangleArea = max(largestRectangleArea, heights[i]*(right-left-1));
        }
        return largestRectangleArea;
    }
};
