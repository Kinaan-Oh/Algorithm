// Bruteforce: O(heights.length*lg(heights.length) + heights.length*max(heights)) [Time Limit Exceeded(Testcase 90)]

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        set<int> h(heights.begin(),heights.end());
        
        int largestRectangleArea = 0;
        
        for(auto it = h.begin();it!=h.end();it++)
        {
            int maximumLengthOfRectangle = 0;
            int lengthOfRectangle = 0;
            for(int i=0;i<heights.size();i++)
            {
                if(heights[i]<*it) {
                    maximumLengthOfRectangle = max(maximumLengthOfRectangle, lengthOfRectangle);
                    lengthOfRectangle = 0;
                }
                else {
                    lengthOfRectangle++;
                }
            }
            maximumLengthOfRectangle = max(maximumLengthOfRectangle, lengthOfRectangle);
            largestRectangleArea = max(largestRectangleArea, (*it)*maximumLengthOfRectangle);
        }
        return largestRectangleArea;
    }
};
