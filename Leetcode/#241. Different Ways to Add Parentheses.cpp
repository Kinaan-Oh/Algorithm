// "Divide and Conquer With Memoization"
// 선택된 연산자 기준으로 왼쪽, 오른쪽 연산식으로 분할. 선택된 연산자는 가장 마지막에 연산.

class Solution {
private:
    unordered_map<string,vector<int>>   memo;
    
public:
    vector<int> diffWaysToCompute(string expression) {
        if(memo.find(expression)!=memo.end())    return memo[expression];
        
        vector<int> ans;
        
        for(int i=0;i<expression.size();i++) {
            if(isdigit(expression[i]))  continue;

            vector<int> front = diffWaysToCompute(expression.substr(0,i));
            vector<int> rear = diffWaysToCompute(expression.substr(i+1));

            for(int j=0;j<front.size();j++) {
                for(int k=0;k<rear.size();k++) {
                    switch(expression[i]) {
                        case '+':
                            ans.push_back(front[j]+rear[k]);
                            break;
                        case '-':
                            ans.push_back(front[j]-rear[k]);
                            break;
                        case '*':
                            ans.push_back(front[j]*rear[k]);
                            break;
                    }
                }
            }
        }
        
        if(ans.size()==0)   ans = {stoi(expression)};
        return  memo[expression] = ans;
    }
};
