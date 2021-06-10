// 출제의도: "Cycle In Graph, List, Hash Table", Time Complexity: O(n), Space Complexity: O(n). (n: list 노드의 갯수)
// 해시 테이블로 각 리스트 노드의 방문여부를 판단. 단순 반복문으로 구현. 
// List를 Graph로 간주하여 DFS/BFS 하는 풀이도 통과(아래 주석으로 기록). 그러나, 이 문제는 간단하므로 단순 반복문 구현이 더 효율적.

class Solution {
private:
    unordered_map<ListNode*,bool>   visited;
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr)   return false;
        
        ListNode *cur = head;
        while(cur) {
            if(visited[cur])    return true;
            
            visited[cur]=true;
            cur = cur->next;
        }
        return false;
    }
};

// - "BFS" 풀이 -

// class Solution {
// private:
//     unordered_map<ListNode*,bool>   visited;
// public:
//     bool hasCycle(ListNode *head) {
//         if(head==nullptr)   return false;
        
//         queue<ListNode*>    que;
//         que.push(head);
//         while(!que.empty()) {
//             ListNode *cur = que.front();
//             que.pop();
//             if(visited[cur])    return true;
            
//             visited[cur] = true;
//             if(cur->next)   que.push(cur->next);
//         }
//         return false;
//     }
// };

// - "DFS" 풀이 -

// class Solution {
// private:
//     unordered_map<ListNode*,bool>   visited;
// public:
//     bool hasCycle(ListNode *head) {
//         if(head==nullptr)   return false;
//         if(visited[head])   return true;
        
//         visited[head]=true;
//         return hasCycle(head->next);
//     }
// };
