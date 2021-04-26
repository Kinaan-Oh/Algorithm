// O(mn). #84 Largest Rectangle in Histogram 문제로 변환하여 m번 반복.

class Solution {
private:
    int answer = 0;
    int m, n;
    int height[200][200];
    int left[200], right[200];
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        m = matrix.size();
        if(m>0) n = matrix[0].size();
        else    n=0;
        setHeight(matrix);
      
        for(int i=0;i<m;i++)
        {
            fill(left,left+n,-1);
            fill(right,right+n,n);
            answer = max(answer, findMaxRectangleOfHistogram(i));
        }
        
        return answer;
    }
    
    //O(mn)
    void setHeight(vector<vector<char>>& matrix)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='0')   height[i][j] = 0;
                else if(matrix[i][j]=='1' && i==0)    height[i][j] = 1;
                else if(matrix[i][j]=='1' && i>0)    height[i][j] = height[i-1][j]+1; 
            }
        }
    }
    
  // O(n)
    int findMaxRectangleOfHistogram(int row)
    {
        int maxOfHistogram = 0;
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && height[row][st.top()]>height[row][i])
            {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())  st.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && height[row][st.top()]>height[row][i])
            {
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }    
        for(int i=0;i<n;i++)    maxOfHistogram = max(maxOfHistogram, height[row][i]*(right[i]-left[i]-1));
        return maxOfHistogram;
    }
};
