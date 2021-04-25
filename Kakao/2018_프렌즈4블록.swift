// Time Complexity: O(m^3*n)

var numOfPops: Int = 0

// O(mn)
func checkBlocksToBurst(gameBoard: [[String]], blocksToBurst: inout [[Bool]], bursted: inout Bool) {
    bursted = false
    for i in 0..<gameBoard.count-1 {
        for j in 0..<gameBoard[0].count-1 {
            if gameBoard[i][j] != "POP" && gameBoard[i][j] == gameBoard[i][j+1] && gameBoard[i][j] == gameBoard[i+1][j] && gameBoard[i][j] == gameBoard[i+1][j+1] {
                blocksToBurst[i][j] = true
                blocksToBurst[i][j+1] = true
                blocksToBurst[i+1][j] = true
                blocksToBurst[i+1][j+1] = true
                bursted = true
            }
        }
    }
}

//O(mn)
func burstBlocks(gameBoard: inout [[String]], blocksToBurst: [[Bool]]) {
    for i in 0..<gameBoard.count {
        for j in 0..<gameBoard[0].count {
            if blocksToBurst[i][j] {
                gameBoard[i][j] = "POP"
                numOfPops += 1
            }
        }
    }
}

O(m^2*n)
func dropBlocks(gameBoard: inout [[String]])
{
    for col in 0..<gameBoard[0].count {
        for _ in 0..<gameBoard.count-1 {
            for row in (1..<gameBoard.count) {
                if gameBoard[row][col] == "POP" && gameBoard[row-1][col] != "POP" {
                    gameBoard[row][col] = gameBoard[row-1][col]
                    gameBoard[row-1][col] = "POP"
                }
            }
        }
    }
}

func solution(_ m:Int, _ n:Int, _ board:[String]) -> Int {
    var gameBoard = board.map({$0.map({String($0)})})
    var bursted = true
    // repeat 최대 m/2회 반복.
    repeat {
        var blocksToBurst = [[Bool]].init(repeating: [Bool].init(repeating: false, count: n), count: m)
        checkBlocksToBurst(gameBoard: gameBoard, blocksToBurst: &blocksToBurst, bursted: &bursted)
        burstBlocks(gameBoard: &gameBoard, blocksToBurst: blocksToBurst)
        dropBlocks(gameBoard: &gameBoard)
    } while bursted
    
    return numOfPops
}
