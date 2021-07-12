// "Stack", Time Complexity: O(mn), Space Complexity: O(n) (m: board.size, n: moves.size)
// reduce를 이용하여 간단하게 풀이.

import Foundation

var board = [[Int]]()
var moves = [Int]()

func pick(_ pos: Int) -> Int? {
    for i in 0..<board.count {
        if board[i][pos-1] > 0 {
            let doll = board[i][pos-1]
            board[i][pos-1] = 0
            return  doll
        }
    }
    return nil
}

func solution(_ param0:[[Int]], _ param1:[Int]) -> Int {
    var ans: Int = 0
    board = param0
    moves = param1
    
    moves.reduce(into: [Int]()) { stack, pos in
        guard let doll = pick(pos) else { return }
        if stack.isEmpty || stack.last != doll {
            stack.append(doll)
            return
        }
        stack.removeLast()
        ans += 2
    }
    return ans
}
