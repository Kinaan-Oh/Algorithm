// "BFS", Time Complexity: O(n^3), Space Complexity: O(n).
// 자료구조 큐를 이용하여 s의 각 지점으로 부터 방문가능한 다음 지점을 탐색한다.(BFS)
// visited를 유지하여 s의 각 지점을 한번씩만 방문한다.(중복 방문을 방지) 따라서, #139. Word Break_sol1.cpp과 동일한 Time Complexity를 갖게 된다.

class Solution {
private:
    unordered_set<string>   hash_set;
    bool visited[300];

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(int i=0;i<wordDict.size();i++)  hash_set.insert(wordDict[i]);
        fill(visited,visited+300,false);
        queue<int>  que;
        que.push(0);
        
        while(!que.empty()) {
            int cur = que.front();
            que.pop();
            if(cur==s.length())    return true;
            if(visited[cur])    continue;
            visited[cur] = true;
            
            for(int end=cur;end<s.length();end++) {
                if(hash_set.find(s.substr(cur,end-cur+1))!=hash_set.end()) {
                    que.push(end+1);
                }
            }
        }
        return false;
    }
};
