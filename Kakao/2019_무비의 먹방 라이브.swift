// 출제의도: "구현(원형), Greedy(정렬 or 우선순위큐 or BST)", Time Complexity: O(nlgn), Space Complexity: O(n). (n: food_times)
// 매 순간 food_times에서 가장 작은 값을 찾아 한꺼번에 k를 감소시킨다. 가장 작은 값을 찾기 위해 정렬, Min Heap, BST 등을 이용할 수 있으나 C++과는 다르게 Swift에서는 Heap(priority_queue),
// BST(map,set)을 제공하지 않는다.(Swift가 제공하는 Dic,Set는 Hash Map, Hash Set이다.) 따라서 Swift는 해당 자료구조들을 직접 구현해야하는 문제점이 발생하는데 이는 코딩테스트에 적절하지 않다.
// 따라서, 정렬을 이용하여 구현하였고 문제에 따라서 Heap, BST가 꼭 필요하다면 Swift가 아닌 C++를 선택해야함을 느꼈다.

import Foundation

func solution(_ food_times:[Int], _ k:Int64) -> Int {
    var answer = -1
    guard food_times.reduce(0,{$0+$1})>k else { return answer }
    
    let sorted = food_times.enumerated()
                       .map {($0.element,$0.offset)}
                       .sorted(by: <)
    var pos = 0
    var prev = 0
    var K: Int64 = k

    while(pos<sorted.count) {
        guard K>=Int64(sorted[pos].0-prev)*Int64(sorted.count-pos) else {
            let sorted = sorted[pos..<sorted.count].sorted { $0.1<$1.1 }
            answer = sorted[Int(K%Int64(sorted.count))].1+1
            break
        }

        K -= Int64(sorted[pos].0-prev)*Int64(sorted.count-pos)
        prev = sorted[pos].0
        while(pos<sorted.count && sorted[pos].0==prev) { pos += 1 }
    }
    
    return answer
}
