// O(m^2*n^2)

class Solution {
private:
    int sum[200][200];
    int answer = 0;
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        setSum(matrix);
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                for(int k=i;k<matrix.size();k++)
                {
                    for(int l=j;l<matrix[0].size();l++)
                    {
                        int areaOfRectangle = (k-i+1)*(l-j+1);
                        int sumOfArea;
                        if(i-1>=0 && j-1>=0)  sumOfArea = sum[k][l] - sum[k][j-1] - sum[i-1][l] + sum[i-1][j-1];
                        else if(i-1<0 && j-1>=0)    sumOfArea = sum[k][l] - sum[k][j-1];
                        else if(i-1>=0 && j-1<0)    sumOfArea = sum[k][l] - sum[i-1][l];
                        else    sumOfArea = sum[k][l];
                        
                        if(sumOfArea == areaOfRectangle) answer = max(answer, sumOfArea);
                    }
                }
            }
        }
        return answer;
    }
    
    void setSum(vector<vector<char>>& matrix)
    {
        for(int i=0;i<matrix.size();i++)
        {
            int sumOfRow = 0;
            for(int j=0;j<matrix[0].size();j++)
            {
                sumOfRow += (matrix[i][j]-'0');
                if(i>0) sum[i][j] = sum[i-1][j] + sumOfRow;
                else    sum[i][j] = sumOfRow;
            }
        }
    }
};
