// "Priority Queue", Time Complexity: O(lgk*N), Space Complexity: O(k). (k: lists.size, N: 모든 리스트 노드의 갯수)
// sol1의 모든 리스트의 front를 비교하여 최솟값을 찾는 로직을 priority queue 자료구조를 이용하여 최적화. 해당 로직의 Time Complexity는 O(k)에서 O(lgk)로 개선.
// 위의 로직을 N회 반복하므로 전체 Time Complexity: O(lgk*N).

struct compare {
    bool operator()(ListNode* n1, ListNode* n2) {
        return n1->val>n2->val;
    }
};

class Solution {
private:
    ListNode* head = new ListNode();    // dummy node

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        ListNode* cur = head;
        
        for(int i=0;i<lists.size();i++) {
            if(lists[i]!=nullptr)    pq.push(lists[i]);
        }
        while(!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();
            cur->next = top;
            cur = cur->next;
            if(top->next!=nullptr)  pq.push(top->next);
        }
        
        return head->next;
    }
};
