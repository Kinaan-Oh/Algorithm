// O(m^2*n). 좀더 이해하기 쉽고 접근하기 쉬운 풀이. 현 위치를 포함한 왼쪽으로의 연속된 1의 갯수를 미리 계산하여 numOfConsecutiveOne에 저장하여 O(m^2*n^2)에서 O(m^2*n)으로 연산을 줄임.

class Solution {
private:
    int m, n;
    int answer = 0;
    int numOfConsecutiveOne[200][200] = {0,};  // num of consecutive one left and including matrix[i][j] 
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        m = matrix.size();
        if(m>0) n = matrix[0].size();
        else    n=0; 
        
        setNumOfConsecutiveOne(matrix);
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int width = n;
                int height = 1;
                
                while(i-height+1>=0 && numOfConsecutiveOne[i-height+1][j]>0)
                {
                    width = min(width, numOfConsecutiveOne[i-height+1][j]);
                    answer = max(answer, width*height);
                    height++;
                }
            }
        }
        return answer;
    }
    
    void setNumOfConsecutiveOne(vector<vector<char>>& matrix)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1' && j==0)   numOfConsecutiveOne[i][j] = 1;
                else if(matrix[i][j]=='1' && j-1>=0)   numOfConsecutiveOne[i][j] = numOfConsecutiveOne[i][j-1]+1;
            }
        }
    }
    
};
