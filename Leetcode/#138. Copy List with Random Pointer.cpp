// 출제의도: "리스트, 해시 테이블", Time Complexity: O(n), Space Complexity: O(n). (n: list.length)
// array은 메모리상 논리적으로 연속된 위치에 배치되는 반면, list는 동적할당으로 인해 메모리상 할당 가능한 임의 위치에 배치된다는 차이점이 있다. 
// 따라서 list는 1) array와 다르게 head 메모리 주소와 특정 노드의 메모리 주소만으로 head로부터의 상대적 위치를 O(1)로 알 수 없고 (head에서 순차탐색해야 하므로 O(n)이 걸린다.)
// 2) array와 다르게 head로부터 n번째 위치의 노드에 O(1)로 접근할 수 없다. (head에서 순차탐색해야 하므로 O(n)이 걸린다.)
// 이 문제는 해시 테이블을 이용하면 list를 array처럼 사용할 수 있어 위의 문제를 해결 할 수 있어 문제를 효율적으로 해결할 수 있다.
// list의 1) 각 노드의 상대 위치(index)에 대한 메모리주소의 사상, 2) 각 노드의 메모리주소에 대응하는 상대 위치의 사상 을 해시 테이블에 기록한다면 list를 array처럼 사용할 수 있다.


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr)   return nullptr;
        
        Node* copied = new Node(head->val);
        unordered_map<int,Node*> idx_to_ptr;
        unordered_map<Node*,int> ptr_to_idx;
        unordered_map<int,int>  random;
        
        int idx=1;
        for(Node* cur=head;cur!=nullptr;cur=cur->next) {
            idx_to_ptr[idx] = cur;
            ptr_to_idx[cur] = idx++;
        }
        idx_to_ptr[0] = nullptr;
        ptr_to_idx[nullptr] = 0;
        
        idx=1;
        for(Node* cur=head;cur!=nullptr;cur=cur->next) {
            random[idx++] = ptr_to_idx[cur->random];
        }
        
        Node* cur_copied = copied;
        idx=1;
        idx_to_ptr[idx] = cur_copied;
        ptr_to_idx[cur_copied] = idx++;
        for(Node* cur=head->next;cur!=nullptr;cur=cur->next) {
            cur_copied->next = new Node(cur->val);
            cur_copied = cur_copied->next;
            idx_to_ptr[idx] = cur_copied;
            ptr_to_idx[cur_copied] = idx++;
        }
        
        for(Node* cur=copied;cur!=nullptr;cur=cur->next) {
            cur->random = idx_to_ptr[random[ptr_to_idx[cur]]];
        }
        
        return copied;
    }
};
