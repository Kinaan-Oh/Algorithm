// 출제 의도: 최단경로 -> "BFS"

#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct Stopover {
    string word;
    int round;
    Stopover(string w, int r):word(w),round(r){}
};

int getDist(string &s1, string &s2) {
    int dist=0;
    for(int i=0;i<s1.length();i++) {
        if(s1[i]!=s2[i])    dist++;
    }
    return dist;
}

int bfs(vector<string> &words, string begin, string target) {
    unordered_map<string,bool>   visited;
    queue<Stopover> que;
    
    visited[begin]=true;
    que.push(Stopover(begin,0));
    while(!que.empty()) {
        Stopover cur = que.front();
        que.pop();
        if(cur.word == target)  return cur.round;
        
        for(int i=0;i<words.size();i++) {
            if(visited[words[i]] || getDist(cur.word,words[i])!=1)  continue;
            
            visited[words[i]] = true;
            que.push(Stopover(words[i],cur.round+1));
        }
    }
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = bfs(words, begin, target);
    return answer;
}
