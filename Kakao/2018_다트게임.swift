// String.split, reduce 를 사용해보았음.

func solution(_ dartResult:String) -> Int 
{
    var scoreCalculatedList: [Int] = []
    let scoreList = dartResult.split {$0.isLetter || $0=="#" || $0=="*"}
    let letterList = dartResult.split(whereSeparator: {$0.isNumber})
    for i in 0..<3
    {
        var score = Int(scoreList[i])!
        switch letterList[i].first
        {
            case "D":
                score = score*score
            case "T":
                score = score*score*score
            default:
                break
        }

        if letterList[i].count==2
        {
            switch letterList[i].last
            {
                case "#":
                    score *= -1
                case "*":
                    if scoreCalculatedList.count != 0 {
                        scoreCalculatedList[scoreCalculatedList.count-1] *= 2
                    }
                    score *= 2
                default:
                    break
            }
        }
        scoreCalculatedList.append(score)
    }
    
    return scoreCalculatedList.reduce(0){$0+$1}  
}
