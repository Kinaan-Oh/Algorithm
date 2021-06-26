// 출제의도: "구현"
// 1) swift에서 struct는 생성된 이후 property 수정이 불가. 따라서, mutating func을 정의하여 수정해야 함.
// 2) for a in b 문에서 a는 let으로 받게 됨. 따라서, 수정이 불가능. 이 문제를 피하기 위해 for i in 0..<b.count로 인덱스로 접근해야 함.
// 3) 지울 수 있는 블록의 패턴은 5가지. lefttop을 기준으로 모양을 결정할 수 있음.
// 4) 이 문제는 Swift가 C++보다 풀기에 적합하지 않음. 


import Foundation

struct Type {
    let no: Int
    let body: [(Int, Int)]
    let dent: [(Int, Int)]
    
    init(_ no: Int, _ body: [(Int, Int)], _ dent: [(Int, Int)]) {
        self.no = no
        self.body = body
        self.dent = dent
    }
}

struct Block {
    let leftTop: (Int, Int)
    let type: Int
    var isPoped = false
    
    init(_ leftTop: (Int, Int), _ type: Int) {
        self.leftTop = leftTop
        self.type = type
    }
    
    mutating func pop()->Void {
        self.isPoped = true
    }
}

let types: [Type] = [Type(0,[(1,0),(1,1),(1,2)],[(0,1),(0,2)]),
                     Type(1,[(1,0),(2,0),(2,-1)],[(0,-1),(1,-1)]),
                     Type(2,[(1,0),(2,0),(2,1)],[(0,1),(1,1)]),
                     Type(3,[(1,0),(1,-1),(1,-2)],[(0,-1),(0,-2)]),
                     Type(4,[(1,0),(1,-1),(1,1)],[(0,-1),(0,1)])]

func isOutOfBound(_ N: Int, _ x: Int, _ y: Int) -> Bool {
    if x<0 || x>=N || y<0 || y>=N {
        return true
    }
    return false
}

func popBlock(_ board: inout [[Int]], _ block: Block) -> Void {
    board[block.leftTop.0][block.leftTop.1] = 0;
    types[block.type].body.forEach {
        board[block.leftTop.0 + $0.0][block.leftTop.1 + $0.1] = 0
    }
}

func solution(_ board:[[Int]]) -> Int {
    var board = board
    var answer: Int = 0
    var blocks = [Block]()
    var visited = [Int: Bool]()
    var N = board.count
    
    for i in 0..<N {
        for j in 0..<N {
            if board[i][j] == 0 || visited[board[i][j], default: false] {
                continue
            }
            visited[board[i][j]] = true
            
            for type in types {
                var fnd = true
                type.body.forEach {
                    if isOutOfBound(N,i+$0.0,j+$0.1) || board[i][j] != board[i+$0.0][j+$0.1]{
                        fnd = false
                        return
                    }
                }
                if fnd {
                    blocks.append(Block((i,j),type.no))
                    break
                }
            }
        }
    }
    
    for i in 0..<blocks.count {
        var numOfPop: Int = 0

        for i in 0..<blocks.count {
            if blocks[i].isPoped {
                continue
            }

            let dents = types[blocks[i].type].dent
            var isEmptyVerticaly = true

            dents.forEach {
                for r in 0...blocks[i].leftTop.0+$0.0 {
                    if board[r][blocks[i].leftTop.1+$0.1] > 0 {
                        isEmptyVerticaly = false
                        return
                    }
                }
            }

            if isEmptyVerticaly {
                numOfPop += 1
                popBlock(&board,blocks[i])
                blocks[i].pop()
            }
        }

        if numOfPop == 0 {
            break
        }
        answer += numOfPop
    }
    
    return answer
}
