// "구현(Recursive)", Time Complexity: O(n), Space Complextiy: O(n) (n: list 길이)
// match_reversely 재귀호출로 system stack의 Space Complexity는 O(n).
// 구현하기 생각보다 까다로웠음. list의 길이가 0,1 인 경우 예외처리 해주어야 함. 이는 if(font), if(front->next)를 통해 해주었음.

class Solution {
private:
    ListNode* list;
    
public:
    bool isPalindrome(ListNode* head) {
        list = head;
        return match_reversely(head);
    }
    
    bool match_reversely(ListNode* front) {
        if(front) {
            if(front->next) {
                if(!match_reversely(front->next))   return false;
                list = list->next;
            }
            
            if(list->val != front->val) return false;
        }
        
        return true;
    }
};
