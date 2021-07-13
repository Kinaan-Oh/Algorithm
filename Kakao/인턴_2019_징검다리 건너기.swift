// leetcode #239. Sliding Window Maximum과 같은 문제.
// 출제의도: "Sliding Window",
// 풀이 방법: "Monotone Queue", Time Complexity: O(n), Space Complexity: O(n). (n: stones.size)
// 다양한 풀이 방법이 있지만(이분탐색, 슬라이딩 윈도우(bst), union-find, monotone queue) 가장 효율성 높은 방법은 monotone queue.
// 문제를 해석하고 Sliding Window Maximum 를 구하는 문제로 번역 하는 과정이 필요. 해당 문제를 미리 풀어보지 않았다면 Brute Force에 까까운 이분탐색 외에 절대 스스로 다른 풀이를 생각할 수 없음.

import Foundation

func solution(_ stones:[Int], _ k:Int) -> Int {
    var ans = Int.max
    var deq = [Int]()
    
    stones.enumerated()
        .forEach {
            while !deq.isEmpty && stones[deq.last!] <= $0.element {
                deq.removeLast()
            }

            deq.append($0.offset)

            while $0.offset-deq.first!+1 > k {
                deq.removeFirst()
            }
            guard $0.offset+1 >= k    else { return }
            ans = min(ans, stones[deq.first!])
        }
    return ans
}
