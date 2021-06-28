// 출제의도: "구현"
// c++에 비교하여 swift 언어 사용의 장점은 없었던 문제.

import Foundation

func rotateClockwise90(_ key: [[Int]]) -> [[Int]] {
    let m = key.count
    var keyRotated = Array(repeating: Array(repeating: 0, count: m), count: m)
    
    for i in 0..<m {
        for j in 0..<m {
            keyRotated[j][m-i-1] = key[i][j]
        }
    }
    return keyRotated
}

func putLockOnBoard(_ board: inout [[Int]], _ lock: [[Int]], _ key: [[Int]]) -> Void {
    let m = key.count, n = lock.count
    
    for i in m-1..<m+n-1 {
        for j in m-1..<m+n-1 {
            board[i][j] += lock[i-(m-1)][j-(m-1)]
        }
    }
}

func putKeyOnBoard(_ board: inout [[Int]], _ key: [[Int]], _ pos: [Int]) -> Void {
    let m = key.count
    
    for i in pos[0]..<pos[0]+m {
        for j in pos[1]..<pos[1]+m {
            board[i][j] += key[i-pos[0]][j-pos[1]]
        }
    }
}

func keyFitsLock(_ board: [[Int]], _ lock: [[Int]], _ key: [[Int]]) -> Bool {
    let m = key.count, n = lock.count
    
    for i in m-1..<m+n-1 {
        for j in m-1..<m+n-1 {
            if board[i][j] != 1 {
                return false
            }
        }
    }
    return true
}

func insertKeyIntoLock(_ lock: [[Int]], _ key: [[Int]]) -> Bool {
    let m = key.count, n = lock.count
    
    for i in 0..<m+n-1 {
        for j in 0..<m+n-1 {
            var board = Array(repeating: Array(repeating: 0, count: 2*m+n-2), count: 2*m+n-2)
            putLockOnBoard(&board, lock, key)
            putKeyOnBoard(&board, key, [i,j])
            if(keyFitsLock(board, lock, key)) {
                return true
            }
        }
    }
    return false
}

func solution(_ key:[[Int]], _ lock:[[Int]]) -> Bool {
    var key = key
    for i in 0..<4 {
        if(insertKeyIntoLock(lock, key)) {
            return true
        }
        key = rotateClockwise90(key)
    }
    return false
}
