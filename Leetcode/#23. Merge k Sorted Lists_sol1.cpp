// "Brute Force", Time Complexity: O(k*N), Space Complexity: O(1). (k: lists.size, N: 모든 리스트 노드의 갯수)
// 각 리스트의 front들을 비교하여(O(k)) 최솟값을 찾는 것을 N번 반복.

class Solution {
private:
    ListNode* head = new ListNode();    // dummy node
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* cur = head;
        bool fnd=true;
        int minOfList, idx;
        
        while(fnd) {
            fnd = false;
            minOfList = INT_MAX;
            
            for(int i=0;i<lists.size();i++) {
                if(lists[i]!=nullptr && lists[i]->val<minOfList) {
                    fnd = true;
                    minOfList = lists[i]->val;
                    idx = i;
                }
            }
            
            if(fnd) {
                cur->next = lists[idx];
                cur = cur->next;
                lists[idx] = lists[idx]->next; 
            }
        }
        
        return head->next;
    }
};
