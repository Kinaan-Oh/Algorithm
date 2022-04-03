// List/Two-Pointer, Time Complexity: O(n), Space Complexity: O(1) (n: num of list)
// 논리: 1) mid node 찾기 위해 walker/runner method 2) mid node를 시작점으로 하는 list를 reverse하기 위한 Two-Pointer method 3) 두 리스트를 merge히기 위한 Two-Pointer method
// list reverse -> L사 필기시험 출제. 해당 로직으로 풀이.

class Solution {
public:
    void reorderList(ListNode* head) {
        // 1. find mid of list
      
        ListNode* walker = head;
        ListNode* runner = head;
        
        while(runner && runner->next) {
            walker = walker->next;
            runner = runner->next->next;
        }
      
        // reverse second list
        
        ListNode* tmp = nullptr;
        ListNode* prev = nullptr;
        ListNode* cur = walker;
        
        while(cur) {
            tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        } 
      
        // merge first and second list
        
        tmp = nullptr;
        ListNode* first = head;
        ListNode* second = prev;
        
        while(second->next) {
            tmp = first->next;
            first->next = second;
            first = tmp;
            
            tmp = second->next;
            second->next = first;
            second = tmp;
        }
    }
};
