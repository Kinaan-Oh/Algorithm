// 출제의도: "Hash Table, Disjoint-Set/Union-ifnd", Time Complexity: O(nlg*n), Space Complexity: O(n). (n: room_number.size)
// 해당 문제는 Hash Table 구현방법 중 Open Addressing의 Linear Probing과 동일
// Hash Table로 할당한 room number를 관리해야 메모리 초과를 피할 수 있음.
// Linear Probing은 정확성을 모두 통과 할 수 있지만, Clustering의 문제로 비효율이 발생. 때문에 Time Complexity: O(n^2).
// Linear Probing을 개선할 방법을 찾아야 함. DisJoint-Set/Union-Find를 이용하면 O(nlg*n)으로 개선 가능.

import Foundation

extension Dictionary where Key == Int64, Value == Int64 {
    mutating func find(_ request: Int64) -> Int64 {
        guard let room_assigned = self[request] else {
            self[request] = request+1
            return request
        }
        
        self[request] = self.find(room_assigned)
        return self[request]! 
    }
}

func solution(_ k:Int64, _ room_number:[Int64]) -> [Int64] {
    var booker = [Int64: Int64]()
    
    return room_number.reduce(into: [Int64]()) { ans, request in
                let room_no = booker.find(request)
                ans.append(room_no)
           }
}
