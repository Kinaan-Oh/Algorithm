// 출제의도: "BFS, 회전변환"
// [ 이 문제에서 C++보다 Swift가 우수한 점 ]
// 1) Array를 Set의 key로 바로 사용가능.
// 2) Array 간 + 연산 제공
// 3) 경계값 검사에 유용한 ~= 연산자 제공

import Foundation

var board = [[Int]]()

struct Point: Hashable {
    let x: Int
    let y: Int
    
    init(_ x: Int, _ y:Int) {
        self.x = x
        self.y = y
    }
    
    static func + (_ lhs: Point, _ rhs: Point) -> Point {
        return Point(lhs.x+rhs.x, lhs.y+rhs.y)
    }
    
    static func - (_ lhs: Point, _ rhs: Point) -> Point {
        return Point(lhs.x-rhs.x, lhs.y-rhs.y)
    }
    
    static func < (_ lhs: Point, _ rhs: Point) -> Bool {
        return (lhs.x, lhs.y) < (rhs.x, rhs.y)
    }
}

struct Agent: Hashable {
    static var memo = Set<[Int]>()
    let pos: Point
    let shape: Shape
    let numOfMove: Int
    
    var posElse: Point {
        return shape == .horizontal ? Point(pos.x,pos.y+1) : Point(pos.x+1,pos.y)
    }
    
    init(_ pos: Point, _ shape: Shape, _ numOfMove: Int) {
        self.pos = pos
        self.shape = shape
        self.numOfMove = numOfMove
    }
    
    static func visit(_ agent: Agent) -> Void {
        Agent.memo.insert([agent.pos.x]+[agent.pos.y]+[agent.shape.rawValue])
    }
    
    static func isPossibleToVisit(_ agent: Agent) -> Bool {
        return !Agent.memo.contains([agent.pos.x]+[agent.pos.y]+[agent.shape.rawValue])
    }
    
    func move() -> [Agent] {
        var next = [Agent]()
        
        let dxy = [(1,0),(-1,0),(0,1),(0,-1)]
        next += dxy.map({ pos + Point($0.0,$0.1) })
                   .filter({ isAgentValid($0, self.shape) })
                   .map { Agent($0, self.shape, self.numOfMove+1) }
        
        next += rotate(axis: pos, target: posElse)
        next += rotate(axis: posElse, target: pos)
        
        return next
    }
    
    func isAgentValid(_ pos: Point, _ shape: Shape) -> Bool {
        let posElse = ( shape == .horizontal ? Point(pos.x,pos.y+1) : Point(pos.x+1,pos.y) )
        
        if !isPosValid(pos) || !isPosValid(posElse) {
            return false
        }
        return true
    }
    
    func isPosValid(_ pos: Point) -> Bool {
        let N = board.count
        if !(0..<N ~= pos.x && 0..<N ~= pos.y) || board[pos.x][pos.y] == 1 {
            return false
        }
        return true
    }
    
    func rotate(axis: Point, target: Point) -> [Agent] {
        var next = [Point]()
        next += [rotateClockwise(axis: axis, target: target)]
        next += [rotateCounterClockwise(axis: axis, target: target)]
        
        return next.filter({ isPosValid($0) })
            .filter({ board[target.x+$0.x-axis.x][target.y+$0.y-axis.y] == 0 })
            .map { Agent(axis<$0 ? axis : $0, self.shape == .horizontal ? .vertical : .horizontal,
            self.numOfMove+1) }
    }
    
    func rotateClockwise(axis: Point, target: Point) -> Point {
        let relativePos = target - axis
        return Point(axis.x + relativePos.y, axis.y - relativePos.x)
    }
    
    func rotateCounterClockwise(axis: Point, target: Point) -> Point {
        let relativePos = target - axis
        return Point(axis.x - relativePos.y, axis.y + relativePos.x)
    }
    
    enum Shape: Int {
        case horizontal, vertical
    }
}

func bfs() -> Int {
    let dest = Point(board.count-1,board.count-1);
    var que = [Agent(Point(0,0), .horizontal, 0)]
    Agent.visit(Agent(Point(0,0), .horizontal, 0))
    
    while !que.isEmpty {
        let cur = que.removeFirst()
        if cur.pos == dest || cur.posElse == dest {
            return cur.numOfMove
        }
        
        cur.move()
           .filter({ Agent.isPossibleToVisit($0) })
           .forEach {
                Agent.visit($0)
                que.append($0)
           }
    }
    
    return -1
}

func solution(_ param:[[Int]]) -> Int {
    board = param
    return bfs()
}
