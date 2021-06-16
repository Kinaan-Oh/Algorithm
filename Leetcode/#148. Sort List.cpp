// Time Complexity: O(nlgn), Space Complexity: O(n).

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr)   return nullptr;
        
        vector<int> list;
        for(ListNode* i=head;i!=nullptr;i=i->next) {
            list.push_back(i->val);
        }
        sort(list.begin(),list.end());
        ListNode* sortList = new ListNode(list[0]);
        ListNode* cur = sortList;
        for(int i=1;i<list.size();i++) {
            cur->next = new ListNode(list[i]);
            cur = cur->next;
        }
        return sortList;
    }
};
