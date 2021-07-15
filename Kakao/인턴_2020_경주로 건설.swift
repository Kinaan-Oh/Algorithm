// 출제의도: "Bfs, DP"
// enum을 이용하여 Dir을 가독성있게 정의

import Foundation

var board = [[Int]]()
var cost = Array(repeating: Array(repeating: Array(repeating: Int.max, count: 4),
           count: board.count), count: board.count)
let dxdy: [Pos] = [Pos(0,1), Pos(1,0), Pos(0,-1), Pos(-1,0)]

struct Pos {
    let x: Int, y: Int
    init(_ x: Int,_ y: Int) {
        self.x = x
        self.y = y
    }
    
    static func +(_ p1: Pos,_ p2: Pos) -> Pos {
        return Pos(p1.x+p2.x, p1.y+p2.y)
    }
    
    static func ==(_ p1: Pos,_ p2: Pos) -> Bool {
        return p1.x==p2.x && p1.y==p2.y
    }
    
    func isOutOfBound() -> Bool {
        let N = board.count
        guard 0..<N ~= self.x && 0..<N ~= self.y else { return true }
        return false
    }
}

enum Dir: Int, CaseIterable {
    case East, South, West, North
}

struct Car {
    let pos: Pos
    let cost: Int
    let dir: Dir
    init(_ pos: Pos,_ cost: Int,_ dir: Dir) {
        self.pos = pos
        self.cost = cost
        self.dir = dir
    }
}

func isVertical(_ d1: Dir,_ d2: Dir) -> Bool {
    if abs(d1.rawValue - d2.rawValue) == 1 || abs(d1.rawValue - d2.rawValue) == 3 {
        return true
    }
    return false
}

func bfs() -> Int {
    let N = board.count
    let dest = Pos(N-1, N-1)
    var que = [Car(Pos(0,0),0,.East)]

    while !que.isEmpty {
        guard let cur = que.first else { break }
        
        que.removeFirst()
        guard !(cur.pos == dest) else { continue }

        for dir in Dir.allCases {
            let posNext = cur.pos + dxdy[dir.rawValue]
            guard !posNext.isOutOfBound() && board[posNext.x][posNext.y] == 0 else { continue }
            
            let costCorner = isVertical(dir, cur.dir) && !(cur.pos==Pos(0,0)) ? 500 : 0
            let costNext = cur.cost + 100 + costCorner
            guard costNext<cost[posNext.x][posNext.y][dir.rawValue] else { continue }
            
            cost[posNext.x][posNext.y][dir.rawValue] = costNext
            que.append(Car(posNext, costNext, dir))
        }
    }

    return min(cost[N-1][N-1][Dir.East.rawValue], cost[N-1][N-1][Dir.South.rawValue])
}

func solution(_ param0:[[Int]]) -> Int {
    board = param0
    cost[0][0][Dir.East.rawValue] = 0 
    cost[0][0][Dir.West.rawValue] = 0
    cost[0][0][Dir.South.rawValue] = 0
    cost[0][0][Dir.North.rawValue] = 0
    
    return bfs()
}
